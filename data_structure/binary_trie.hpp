template<typename T, int MAX_LOG=32, typename D=int>
struct binary_trie {
	struct Node {
		Node *nxt[2];
		D exist;
		vector<int> accept;

		Node() : nxt{nullptr, nullptr}, exist(0) {}
	};

	Node *root;

	explicit binary_trie() : root(new Node()) {}
	explicit binary_trie(Node *_root) : root(_root) {}

	~binary_trie() { clear(root); }

	void add(const T &bit, int idx=-1, D delta=1, T xor_val=0) {
		root = add(root, bit, idx, MAX_LOG, delta, xor_val);
	}

	void erase(const T &bit, T xor_val=0) {
		add(bit, -1, -1, xor_val);
	}

	Node *find(const T &bit, T xor_val=0) {
		return find(root, bit, MAX_LOG, xor_val);
	}

	D count(const T &bit, T xor_val=0) {
		auto node = find(bit, xor_val);
		return (node ? node->exist : 0);
	}

	pair<T, Node *> min_element(T xor_val=0) {
		assert(root->exist > 0);
		return kth_element(0, xor_val);
	}

	pair<T, Node *> max_element(T xor_val=0) {
		assert(root->exist > 0);
		return kth_element(root->exist - 1, xor_val);
	}

	pair<T, Node *> kth_element(D k, T xor_val=0) {
		assert(0 <= k && k < root->exist);
		return kth_element(root, k, MAX_LOG, xor_val);
	}

	// [0, bit)
	D count_less(const T &bit, T xor_val=0) {
		return count_less(root, bit, MAX_LOG, xor_val);
	}
private:
	virtual Node *clone(Node *t) { return t; }

	Node *add(Node *t, T bit, int idx, int depth, D x, T xor_val, bool need=true) {
		if(need) clone(t);
		if(depth == -1){
			t->exist += x;
			if(idx >= 0) t->accept.emplace_back(idx);
		}else{
			bool f = (xor_val >> depth) & 1;
			auto &to = t->nxt[f ^ ((bit >> depth) & 1)];
			if(not to) to = new Node(), need = false;
			to = add(to, bit, idx, depth-1, x, xor_val, need);
			t->exist += x;
		}
		return t;
	}
	
	Node *find(Node *t, T bit, int depth, T xor_val) {
		if(depth == -1) {
			return t;
		}else{
			bool f = (xor_val >> depth) & 1;
			auto &to = t->nxt[f ^ ((bit >> depth) & 1)];
			return (to ? find(to, bit, depth-1, xor_val) : nullptr);
		}
	}
	
	pair<T, Node *> kth_element(Node *t, D k, int depth, T xor_val) {
		if(depth == -1) {
			return {0, t};
		}else{
			bool f = (xor_val >> depth) & 1;
			if((t->nxt[f] ? t->nxt[f]->exist : 0) <= k) {
				auto ret = kth_element(t->nxt[f^1], k-(t->nxt[f] ? t->nxt[f]->exist : 0), depth-1, xor_val);
				ret.first |= T(1) << depth;
				return ret;
			}else{
				return kth_element(t->nxt[f], k, depth-1, xor_val);
			}
		}
	}
	
	D count_less(Node *t, const T &bit, int depth, T xor_val) {
		if(depth == -1)return 0;
		D ret = 0;
		bool f = (xor_val >> depth) & 1;
		if((bit >> depth & 1) and t->nxt[f])ret += t->nxt[f]->exist;
		if(t->nxt[f^(bit >> depth & 1)]){
			ret += count_less(t->nxt[f^(bit >> depth & 1)], bit, depth-1, xor_val);
		}
		return ret;
	}

	void clear(Node *t) {
		if (!t) return;
		clear(t->nxt[0]);
		clear(t->nxt[1]);
		delete t;
	}
};

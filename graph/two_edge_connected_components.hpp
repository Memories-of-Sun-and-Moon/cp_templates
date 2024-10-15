
#include "../data_structure/union_find.hpp"
#include "./lowlink.hpp"

auto two_edge_connected_components(vector<vector<int>> &g){
    lowlink l(g);
    union_find uf((int)g.size());
    for(int i = 0;i < (int)g.size();i++){
        for(int to : g[i]){
            if(not l.is_bridge(i, to)){
                uf.unite(i, to);
            }
        }
    }

    vector<vector<int>> group = uf.groups();
    vector<int> comp((int)g.size());
    for(int i = 0;i < (int)group.size();i++){
        for(int v : group[i]){
            comp[v] = i;
        }
    }

    vector<vector<int>> tree((int)group.size());
    for(int i = 0;i < (int)g.size();i++){
        for(int to : g[i]){
            if(comp[i] != comp[to]){
                tree[comp[i]].push_back(comp[to]);
            }
        }
    }

    return make_tuple(group, comp, tree);
}

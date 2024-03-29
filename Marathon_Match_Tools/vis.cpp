// https://gist.github.com/saharan/9547f3e56bcfb3e355a9d1df4d670fd4
#include <bits/stdc++.h>
using namespace std;

class Graphics {
public:
	double screenW;
	double screenH;
	ostringstream data;

	double sr;
	double sg;
	double sb;
	double sa;
	double fr;
	double fg;
	double fb;
	double fa;

	Graphics() : screenW(1), screenH(1), sr(0), sg(0), sb(0), sa(1), fr(1), fg(1), fb(1), fa(1) {
	}

	void screen(int width, int height) {
		screenW = width;
		screenH = height;
	}

	void clear() {
		data.str("");
		data.clear(stringstream::goodbit);
	}

	void stroke(double r, double g, double b) {
		stroke(r, g, b, 1.0);
	}

	void stroke(double r, double g, double b, double a) {
		sr = r;
		sg = g;
		sb = b;
		sa = a;
	}

    //https://ez-net.jp/article/89/CZq0rF1K/mY7SLPft42BO/
    //https://www.colordic.org/
    void stroke(string str) {
        if(str == "Red")sr = 1.0, sg = 0.0, sb = 0.0, sa = 1.0;
        if(str == "Pink")sr = 1.0, sg = 0.752, sb = 0.796, sa = 1.0;
        if(str == "Brown")sr = 0.647, sg = 0.164, sb = 0.164, sa = 1.0;
        if(str == "Orange")sr = 1.000, sg = 0.647, sb = 0.0, sa = 1.0;
        if(str == "Yellow")sr = 1.0, sb = 1.0, sg = 0.0, sa = 1.0;
        if(str == "Green")sr = 0.0, sg = 0.5, sb = 0.0, sa = 1.0;
        if(str == "Blue")sr = 0.0, sg = 0.0, sb = 1.0, sa = 1.0;
        if(str == "SkyBlue")sr = 0.529, sg = 0.807, sb = 0.921, sa = 1.0;
        if(str == "Purple")sr = 0.5, sg = 0.5, sb = 0.0, sa = 1.0;
        if(str == "Black")sr = 0.0, sg = 0.0, sb = 0.0, sa = 1.0;
        if(str == "Grey")sr = 0.5, sg = 0.5, sb = 0.5, sa = 1.0;
        if(str == "White")sr = 1.0, sg = 1.0, sb = 1.0, sa = 1.0;
    }

	void noStroke() {
		stroke(0.0, 0.0, 0.0, 0.0);
	}

	void fill(double r, double g, double b) {
		fill(r, g, b, 1.0);
	}

	void fill(double r, double g, double b, double a) {
		fr = r;
		fg = g;
		fb = b;
		fa = a;
	}
    
    void fill(string str) {
        if(str == "Red")fr = 1.0, fg = 0.0, fb = 0.0, fa = 1.0;
        if(str == "Pink")fr = 1.0, fg = 0.752, fb = 0.796, fa = 1.0;
        if(str == "Brown")fr = 0.647, fg = 0.164, fb = 0.164, fa = 1.0;
        if(str == "Orange")fr = 1.000, fg = 0.647, fb = 0.0, fa = 1.0;
        if(str == "Yellow")fr = 1.0, fg = 1.0, fb = 0.0, fa = 1.0;
        if(str == "Green")fr = 0.0, fg = 0.5, fb = 0.0, fa = 1.0;
        if(str == "Blue")fr = 0.0, fg = 0.0, fb = 1.0, fa = 1.0;
        if(str == "SkyBlue")fr = 0.529, fg = 0.807, fb = 0.921, fa = 1.0;
        if(str == "Purple")fr = 0.5, fg = 0.5, fb = 0.0, fa = 1.0;
        if(str == "Black")fr = 0.0, fg = 0.0, fb = 0.0, fa = 1.0;
        if(str == "Grey")fr = 0.5, fg = 0.5, fb = 0.5, fa = 1.0;
        if(str == "White")fr = 1.0, fg = 1.0, fb = 1.0, fa = 1.0;
    }
    
	void noFill() {
		fill(0.0, 0.0, 0.0, 0.0);
	}

	void line(double x1, double y1, double x2, double y2) {
		data << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" " << stroke() << "/>\n";
	}

	void rect(double x, double y, double w, double h) {
		data << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << w << "\" height=\"" << h << "\" " << stroke() << " " + fill() << "/>\n";
	}

	void text(string str, double x, double y, double size = 16) {
		data << "<text text-anchor=\"middle\" x=\"" << x << "\" y=\"" << y << "\" font-size=\"" << size << "\" " << fill() << " >" << str << "</text>\n";
	}

	string dump(string id = "", string style = "", int widthPx = -1, int heightPx = -1) const {
		ostringstream res;
		res << "<svg ";
		if (id != "") res << "id=\"" + id + "\" ";
		if (style != "") res << "style=\"" + style + "\" ";
		if (widthPx != -1) res << "width=\"" << widthPx << "\" ";
		if (heightPx != -1) res << "height=\"" << heightPx << "\" ";
		res << "viewBox=\"-1 -1 " << screenW + 2 << " " << screenH + 2 << "\" xmlns=\"http://www.w3.org/2000/svg\">\n" << data.str() << "</svg>";
		return res.str();
	}

private:
	string stroke() const {
		return "stroke=\"" + rgb(sr, sg, sb) + "\" stroke-opacity=\"" + s(sa) + "\"";
	}

	string fill() const {
		return "fill=\"" + rgb(fr, fg, fb) + "\" fill-opacity=\"" + s(fa) + "\"";
	}

	string rgb(double r, double g, double b) const {
		return "rgb(" + s(lround(r * 255)) + "," + s(lround(g * 255)) + "," + s(lround(b * 255)) + ")";
	}

	string s(double x) const {
		return to_string(x);
	}
};

class Movie {
public:
	vector<string> svgs;

	Movie() {
	}

	void clear() {
		svgs.clear();
	}

	void addFrame(Graphics& g) {
		svgs.push_back(g.dump("f" + to_string(svgs.size()), "display:none;pointer-events:none;user-select:none;"));
	}

	string dumpHtml(int fps) {
		ostringstream res;
		res << "<html><body><div id=\"text\">loading...</div>" << endl;
		for (string& svg : svgs) {
			res << svg << endl;
		}

		res << "<script>\nlet numFrames = " << svgs.size() << ", fps = " << fps << ";";
		res << R"(
	let text = document.getElementById("text");
	let frames = [];
	for (let i = 0; i < numFrames; i++) {
		let f = document.getElementById("f" + i);
		frames.push(f);
		f.style.display = "none";
	}
	let currentFrame = 0;
	let playing = true;
	setInterval(() => {
		if (!playing) return;
		text.innerText = (currentFrame + 1) + " / " + numFrames;
		frames[(currentFrame - 1 + numFrames) % numFrames].style.display = "none";
		frames[currentFrame].style.display = null;
		currentFrame = (currentFrame + 1) % numFrames;
		if (currentFrame == 0) playing = false;
	}, 1000 / fps);
	window.onmousedown = e => { if (e.button == 0) playing = true; };
;)";
		res << "</script>" << endl;
		res << "</body></html>" << endl;
		return res.str();
	}
private:
};
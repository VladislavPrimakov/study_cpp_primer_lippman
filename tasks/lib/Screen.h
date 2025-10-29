#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen {
	size_t cursor = 0;
	size_t height = 0;
	size_t width = 0;
	string contents;
public:
	Screen() = default;
	Screen(size_t ht, size_t wd) : height(ht), width(wd), contents(ht* wd, ' ') {}
	Screen(size_t ht, size_t wd, char c) : height(ht), width(wd), contents(ht* wd, c) {}
	Screen& move(size_t h, size_t w);
	Screen& set(char c);
	Screen& display(ostream& os);
	friend class Windowmgr;

};

class Windowmgr {
	void clear(size_t);
private:
	vector<class Screen> screens {Screen(24, 80, ' ')};
};

void Windowmgr::clear(size_t i) {
	Screen& s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}

Screen& Screen::move(size_t r, size_t c) {
	cursor = r * width + c;
	return *this;
}
Screen& Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
Screen& Screen::display(ostream& os) {
	os << contents;
	return *this;
}

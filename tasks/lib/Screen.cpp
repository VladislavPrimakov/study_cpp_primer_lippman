#include <Screen.h>

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

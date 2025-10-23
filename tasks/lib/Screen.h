//Упражнение 7.23.Напишите собственную версию класса Screen.

//Упражнение 7.24.Добавьте в свой класс Screen три конструктора :
//стандартный; получающий высоту, ширину и заполняющий содержимое
//соответствующим количеством пробелов; получающий высоту, ширину и
//заполняющий символ для содержимого экрана.

//Упражнение 7.27.Добавьте функции move(), set() и display() в свою
//версию класса Screen.Проверьте свой класс, выполнив следующий код :

//Упражнение 7.32.Определите собственные версии классов Screen и window_
//mgr, в которых функция clear() является членом класса Windowmgr и
//другом класса Screen.

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
//Упражнение 9.52.Используйте стек для обработки выражений со скобками.
//Встретив открывающую скобку, запомните ее положение.Встретив
//закрывающую скобку, после открывающей скобки, извлеките эти элементы,
//включая открывающую скобку, и поместите полученное значение в стек,
//переместив таким образом заключенное в скобки выражение.

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string ff(const string& s, stack<string>& st, size_t& index, string tmp = "") {
	for (; index < s.size(); ++index) {
		char ch = s[index];
		if (ch == '(') {
			tmp += ff(s, st, ++index, "(");
			ch = s[++index];
		}
		if (tmp.size()) {
			tmp += ch;
			if (ch == ')') {
				st.push(tmp);
				return tmp;
			}
		}
	}
	return "";
}

void f(const string& s, stack<string>& st) {
	size_t index = 0;
	ff(s, st, index);
}



int main() {
	string expr = "(1+(2*3)+((8)/4))+1";
	stack<string> st;
	f(expr, st);
	while (st.size()) {
		cout << st.top() << endl;
		st.pop();
	};
	return 0;
}
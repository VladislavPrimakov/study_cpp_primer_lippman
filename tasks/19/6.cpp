//”пражнение 19.6.Ќапишите выражение дл€ динамического приведени€
//указател€ на тип Querybase к указателю на тип AndQuery(см.раздел 15.9.1,
//стр. 802).ѕроверьте приведение, использу€ объект класса AndQuery и класса
//другого запроса.¬ыведите сообщение, подтверждающее работоспособность
//приведени€, и убедитесь, что вывод соответствует ожидани€м.

#include "TextQuery.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Query_base* qb = new AndQuery(Query("word1"), Query("word2"));
	AndQuery* aq = dynamic_cast<AndQuery*>(qb);
	if (aq) {
		cout << "Dynamic cast to AndQuery* successful." << endl;
	} else {
		cout << "Dynamic cast to AndQuery* failed." << endl;
	}
	return 0;
}
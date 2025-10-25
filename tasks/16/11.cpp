//Упражнение 16.11.Следующее определение шаблона List неправильно.
//Как его исправить ?
//template <typename elemType> class Listltem;
//template <typename elemType> class List {
//public:
//	List<elemType>();
//	List<elemType>(const List<elemType>&);
//	List<elemType>& operator= (const List<elemType>&);
//	-List();
//	void insert(Listltem* ptr, elemType value);
//private:
//	Listltem* front, * end;
//};

template <typename elemType> class Listltem;

template <typename elemType> class List {
public:
	List<elemType>();
	List<elemType>(const List<elemType>&);
	List<elemType>& operator= (const List<elemType>&);
	~List();
	void insert(Listltem<elemType>* ptr, elemType value);
private:
	Listltem<elemType>* front, * end;
};

int main() {
	return 0;
}
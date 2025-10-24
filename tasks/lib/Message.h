#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class Folder;

class Message {
	friend class Folder;
	friend void swap(Message& lhs, Message& rhs);
	friend ostream& operator<<(ostream& os, const Message& m);

	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void addFolder(Folder*);
	void remFolder(Folder*);
	void move_Folders(Message*);
public:
	explicit Message(const string);
	Message(const Message&);
	Message(Message&&);
	Message& operator=(const Message&);
	Message& operator=(Message&&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
};

class Folder {
	friend class Message;
	friend void swap(Message& lhs, Message& rhs);

	set<Message*> messages;
	string name;
	void add_to_Messages();
	void remove_from_Messages();
	void addMsg(Message*);
	void remMsg(Message*);
public:
	Folder(const string str = "") : name(str) {}
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	string getName() const;

};

#endif //MESSAGE_H
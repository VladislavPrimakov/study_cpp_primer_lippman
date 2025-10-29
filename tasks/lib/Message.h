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

void Message::add_to_Folders(const Message& m) {
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}

void Message::remove_from_Folders() {
	for (auto f : folders) {
		f->remMsg(this);
	}
	folders.clear();
}

Message::Message(const Message& other) : contents(other.contents), folders(other.folders) {
	add_to_Folders(other);
}

Message& Message::operator=(const Message& other) {
	if (this != &other) {
		remove_from_Folders();
		contents = other.contents;
		folders = other.folders;
		add_to_Folders(other);
	}
	return *this;
}

Message::Message(const string str = "") : contents(str) {}


Message::Message(Message&& m) : contents(move(m.contents)) {
	move_Folders(&m);
}

Message& Message::operator=(Message&& rhs) {
	if (this != &rhs) {
		remove_from_Folders();
		contents = move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

void Message::move_Folders(Message* m) {
	folders = move(m->folders);
	for (auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

void swap(Message& lhs, Message& rhs) {
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

Message::~Message() {
	remove_from_Folders();
}

void Message::save(Folder& f) {
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f) {
	folders.erase(&f);
	f.remMsg(this);
}

void Message::addFolder(Folder* f) {
	folders.insert(f);
}

void Message::remFolder(Folder* f) {
	folders.erase(f);
}

ostream& operator<<(ostream& os, const Message& m) {
	os << "Message: " << m.contents << endl;
	os << "Folders: ";
	for_each(m.folders.begin(), m.folders.end(), [&os](Folder* f) { os << f->getName() << ", "; });
	os << endl;
	return os;
}

Folder::Folder(const Folder& other) : name(other.name), messages(other.messages) {
	add_to_Messages();
}

Folder& Folder::operator=(const Folder& other) {
	remove_from_Messages();
	name = other.name;
	messages = other.messages;
	add_to_Messages();
	return *this;
}

Folder::~Folder() {
	remove_from_Messages();
}

void Folder::add_to_Messages() {
	for (auto m : messages) {
		m->addFolder(this);
	}
}

void Folder::remove_from_Messages() {
	for (auto m : messages) {
		m->remFolder(this);
	}
	messages.clear();
}

void Folder::addMsg(Message* m) {
	messages.insert(m);
}

void Folder::remMsg(Message* m) {
	messages.erase(m);
}

string Folder::getName() const {
	return name;
}



#endif //MESSAGE_H
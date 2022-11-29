#include <vector>
#include <iostream>
#include <functional>

using namespace std;

template <typename T_Key, typename T_Value>
class HashTable {

	function<int(T_Key)> hasher;
	unsigned int capacity;
	unsigned int size;

	class LinkedList {

		friend class HashTable;

		T_Key key;
		T_Value value;
		LinkedList* next;

		LinkedList(T_Key k, T_Value v) : key(k), value(v) {
			next = nullptr;
		}

		LinkedList(LinkedList& other) = delete;

		~LinkedList() { 
			delete next; 
		}

	};

	vector<LinkedList*> elements;

public:

	HashTable(function<int(T_Key)> hasher, unsigned int capacity = 10) 
	: hasher(hasher), capacity(capacity), size(0) {
		elements.resize(capacity);
	}

	HashTable(HashTable& other) = delete;

	~HashTable() {
		for (auto elm : elements)
			delete elm;
	}

	bool has(T_Key key) {

		auto hash = hasher(key);
		hash %= capacity;
		auto curr = elements.at(hash);

		while (curr) {
			if (curr->key == key)
				return true;
			curr = curr->next;
		}

		return false;
	}

	T_Value* get(T_Key key) {

		auto hash = hasher(key) % capacity;
		auto curr = elements.at(hash);

		while (curr) {
			if (curr->key == key)
				return &(curr->value);
			curr = curr->next;
		}

		return nullptr;
	}

	void insert(T_Key key, T_Value value) {

		size++;

		auto hash = hasher(key) % capacity;

		if (!elements.at(hash)) {
			elements[hash] = new LinkedList(key, value);
			return;
		}

		auto curr = elements.at(hash);
		while (curr->next)
			curr = curr->next;
		curr->next = new LinkedList(key, value);


	}

	void remove(T_Key key) {

		auto hash = hasher(key) % capacity;
		if (!elements.at(hash))
			return;

		LinkedList *curr = elements.at(hash), *prev = nullptr;

		while (curr) {

			if (curr->key != key) {
				prev = curr;
				curr = curr->next;
				continue;
			}

			size--;

			if (prev) {
				prev->next = curr->next;
				delete curr;
			}
			else {
				delete curr;
			}

			return;
		}
	}

	void print() {

		for (auto elm : elements) {
			while (elm) {
				cout << "Key: " << elm->key << ", Value: " << elm->value << endl;
				elm = elm->next;
			}
		}
		cout << endl;
	}
};

int main() {

	HashTable<int, int> table([](int a) { return a; });
	for (int i = 0; i < 20; ++i)
		table.insert(i, i * 2);
	table.print();
	table.remove(10);
	table.print();

	return 0;
}
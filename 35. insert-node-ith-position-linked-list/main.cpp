#include <vector>
#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
};

void insertNodeIthPos(Node* const head, unsigned int pos, int val) {

	auto counter = 0;
	auto curr = head;

	while (curr) {
		if (counter == pos) {
			auto oldNext = curr->next;
			curr->next = new Node { val, oldNext };
			return;
		}
		counter++;
		curr = curr->next;
	}

	cout << "Could not insert" << endl;
}

void deleteList(Node* head) {

	if (!head) {
		cout << "List is empty" << endl;
		return;
	}

	while (head) {
		auto temp = head->next;
		delete head;
		head = temp;
	}
}

void printList(Node* head) {

	if (!head) {
		cout << "List is empty" << endl;
		return;
	}

	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	auto head = new Node { 1, new Node { 2, new Node { 3, new Node { 4, new Node { 5, nullptr } } } } };
	cout << "Current List: ";
	printList(head);
	insertNodeIthPos(head, 2, 10);
	cout << "New List: ";
	printList(head);
	deleteList(head);
	printList(head);

	return 0;
}
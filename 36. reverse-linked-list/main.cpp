#include <vector>
#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
};

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

Node* reverseList(Node* head) {

	auto curr = head;
	Node* prev = nullptr;

	while (curr) {
		auto n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}

	return prev;
}

int main() {

	auto head = new Node { 1, new Node { 2, new Node { 3, new Node { 4, new Node { 5, nullptr } } } } };
	cout << "Current List: ";
	printList(head);
	auto reversedHead = reverseList(head);
	cout << "New List: ";
	printList(reversedHead);
	deleteList(reversedHead);

	return 0;
}
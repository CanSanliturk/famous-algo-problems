#include <queue>
#include <math.h>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

template <typename T>
struct LLNode {
	T data;
	LLNode<T>* next;
	LLNode(T data) : data(data) { }
	LLNode(LLNode& other) = delete;
	~LLNode() {
		if (next) {
			delete next;
			next = nullptr;
		}
	}

	void print() {
		for (auto curr = this; curr; curr = curr->next)
			cout << curr->data << " ";
		cout << endl;
	}
};

template <typename T>
struct BSTNode {

	T data;
	BSTNode* left = nullptr;
	BSTNode* right = nullptr;

	BSTNode(T data) : data(data) { }
	BSTNode(BSTNode& other) = delete;
	~BSTNode() {

		if (left) {
			delete left;
			left = nullptr;
		}

		if (right) {
			delete right;
			right = nullptr;
		}
	}

	bool validate() {

		if (left && left->data > data)
			return false;

		if (right && right->data < data)
			return false;

		if (left && !left->validate())
			return false;

		if (right && !right->validate())
			return false;

		return true;
	}

	BSTNode* search(T val, function<bool(T, T)> comparer) {

		BSTNode* ans = nullptr;

		if (data == val)
			ans = this;
		else if (comparer(val, data) && left)
			ans = left->search(val, comparer);
		else
			ans = right ? right->search(val, comparer) : nullptr;

		return ans;
	}

	BSTNode* getMinimum() {
		auto curr = this;

		while (curr->left)
			curr = curr->left;

		return curr;
	}


	BSTNode* getMaximum() {
		auto curr = this;

		while (curr->right)
			curr = curr->right;

		return curr;
	}

	T getRangeSum(T min, T max) {

		T ans = 0;

		auto checkInside = [&](T val) { return val <= max && min <= val; };

		if (checkInside(data))
			ans += data;

		if (max < data) {
			if (left)
				ans += left->getRangeSum(min, max);
		}
		else if (data < min) {
			if (right)
				ans += right->getRangeSum(min, max);
		}
		else {
			if (left)
				ans += left->getRangeSum(min, max);
			if (right)
				ans += right->getRangeSum(min, max);
		}

		return ans;
	}


	unsigned int getNodeCount() const{

		unsigned int leftChildNodeCount = 0, rightChildNodeCount = 0;

		if (left)
			leftChildNodeCount = left->getNodeCount();

		if (right)
			rightChildNodeCount = right->getNodeCount();

		return 1 + leftChildNodeCount + rightChildNodeCount;
	}

	unsigned int getTreeDepth() const {

		unsigned int childDepth = 0;

		if (left)
			childDepth = max(childDepth, left->getTreeDepth());

		if (right)
			childDepth = max(childDepth, right->getTreeDepth());

		return childDepth + 1;
	}

	void print() const {
		cout << data << endl;

		if (left)
			left->print();

		if (right)
			right->print();
	}

	void printLevelOrder() const {

		queue<BSTNode<T>*> q;
		q.push(const_cast<BSTNode<T>*>(this));

		while (!q.empty()) {
			// number of element in queue indicates number of nodes
			// at current level
			auto nodeCount = q.size();	

			// dequeue all nodes of current level and enqueue next level
			while (nodeCount) {
				auto curr = q.front();
				q.pop();

				cout << curr->data << " ";
				if (curr->left)
					q.push(curr->left);
				if (curr->right)
					q.push(curr->right);
				nodeCount--;
			}
			cout << endl;
		}
	}

	void printInOrder() const {

		if (left)
			left->printInOrder();

		cout << data << " ";

		if (right)
			right->printInOrder();
	}

	void printPreOrder() const {

		cout << data << " ";

		if (left)
			left->printPreOrder();

		if (right)
			right->printPreOrder();
	}

	void printPostOrder() const {

		if (left)
			left->printPostOrder();

		if (right)
			right->printPostOrder();

		cout << data << " ";
	}

	void insert(T val) {

		// call this for root. if root is changed, return the new root. else,
		// return this pointer
		if (val < this->data) {
			if (left)
				left->insert(val);
			else
				this->left = new BSTNode<T>(val);
		}
		else {
			if (right)
				right->insert(val);
			else
				this->right = new BSTNode<T>(val);
		}
	}

	LLNode<T>* convertToSortedLinkedList() {

		LLNode<T> *leftAns = nullptr, *curr = nullptr, *rightAns = nullptr, *head = nullptr;

		if (left) {
			leftAns = left->convertToSortedLinkedList();
		}

		curr = new LLNode<T>(data);

		if (right) {
			rightAns = right->convertToSortedLinkedList();
		}

		if (leftAns) {
			head = leftAns;

			auto currLeft = leftAns;
			while (currLeft->next)
				currLeft = currLeft->next;
			currLeft->next = curr;
		}
		else {
			head = curr;
		}

		curr->next = rightAns;
		return curr;
	}
};

template <typename T>
struct BSTFactory {

	static BSTNode<T>* createBalancedBSTWithSortedData(const vector<T>& sortedData, int start, int end) {

		if (start > end)
			return nullptr;

		auto rootIndex = (start + end) / 2;

		auto leftTreeStart = start;
		auto leftTreeEnd = rootIndex - 1;

		auto rightTreeStart = rootIndex + 1;
		auto rightTreeEnd = end;

		auto root = new BSTNode<T>(sortedData.at(rootIndex));
		root->left = createBalancedBSTWithSortedData(sortedData, leftTreeStart, leftTreeEnd);
		root->right = createBalancedBSTWithSortedData(sortedData, rightTreeStart, rightTreeEnd);

		return root;
	}
};

void implementationCheck() {

	auto root = new BSTNode<int>(4);
	auto n1 = new BSTNode<int>(1);
	auto n2 = new BSTNode<int>(2);
	auto n3 = new BSTNode<int>(3);
	auto n4 = root;
	auto n7 = new BSTNode<int>(7);

	root->left = n2;
	n2->left = n1;
	n2->right = n3;

	root->right = n7;

	cout << "Given BST is " << (root->validate() ? "VALID" : "NOT VALID") << endl;
	cout << "2 is searched in root and it is " << (root->search(2, [](int a, int b) { return a < b; }) ? "FOUND" : "NOT FOUND") << endl;
	cout << "Minimum value is searched and it is " << root->getMinimum()->data << endl;
	cout << "Maximum value is searched and it is " << root->getMaximum()->data << endl;
	cout << "Sum of elements smaller than 7 and larger than 0: " << root->getRangeSum(1, 6) << endl;

	delete root;
}

void creatingFromSortedData() {
	auto root = BSTFactory<int>::createBalancedBSTWithSortedData({ 1, 2, 3, 4, 5, 6, 7 }, 0, 6);
	root->printLevelOrder();
	auto llHead = root->convertToSortedLinkedList();
	llHead->print();
	//root->insert(8);
	//root->printLevelOrder();
	delete root;
	delete llHead;
}

int main() {

	creatingFromSortedData();

	return 0;
}

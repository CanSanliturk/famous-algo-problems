#include <queue>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
struct TreeNode {
	T data;

	TreeNode(T data)
		: data(data) { }

	~TreeNode() {
		for (auto child : children)
			delete child;
	}

	void addChild(TreeNode<T>* newChild) {
		this->children.push_back(newChild);
	}

	TreeNode* getChildAt(unsigned int index) {
		if (children.size() == 0 || (children.size() < index))
			return nullptr;
		return children[index];
	}

	unsigned int getNodeCount() {

		auto ans = 1;

		for (auto child : children)
			ans += child->getNodeCount();

		return ans;
	}

	unsigned int getTreeHeight() {

		auto ans = 0;

		for (auto child : children)
			ans = max((int)ans, (int)child->getTreeHeight());

		return ans + 1;
	}

	unsigned int getLeafCount() {

		auto ans = 0;

		for (auto child : children)
			ans += child->getLeafCount();

		return ans ? ans : 1;
	}

	void printPreOrder() {
		cout << this->data << endl;

		for (auto child : children)
			child->printPreOrder();
	}

	void printPostOrder() {
		for (auto child : children)
			child->printPostOrder();
		cout << data << endl;
	}

	void printLevelOrder() {

		queue<TreeNode<T>*> childrenQueue;
		childrenQueue.push(this);

		while (!childrenQueue.empty()) {
			auto curr = childrenQueue.front();
			childrenQueue.pop();

			cout << curr->data << endl;
			for (auto child : curr->children)
				childrenQueue.push(child);
		}
	}

	void printNodesAtGivenLevel(unsigned int level) {

		if (level == 0) {
			cout << data << endl;
			return;
		}

		for (auto child : children)
			child->printNodesAtGivenLevel(level - 1);
	}

private:
	vector<TreeNode<T>*> children;
};

int main() {

	auto root = new TreeNode<int>(1);
	
	auto n2 = new TreeNode<int>(2);
	auto n3 = new TreeNode<int>(3);

	auto n4 = new TreeNode<int>(4);
	auto n5 = new TreeNode<int>(5);
	auto n6 = new TreeNode<int>(6);
	auto n7 = new TreeNode<int>(7);
	auto n8 = new TreeNode<int>(8);

	n2->addChild(n4);
	n2->addChild(n5);

	n3->addChild(n6);
	n3->addChild(n7);

	root->addChild(n2);
	root->addChild(n3);

	cout << "Number of nodes: " << root->getNodeCount() << endl;
	cout << "Height of Tree: " << root->getTreeHeight() << endl;
	cout << "Number of Leaf: " << root->getLeafCount() << endl;

	cout << "Pre-Order Print" << endl;
	root->printPreOrder();

	cout << "Post-Order Print" << endl;
	root->printPostOrder();

	cout << "Level-Order Print" << endl;
	root->printLevelOrder();

	cout << "Third Level Print" << endl;
	root->printNodesAtGivenLevel(2);

	delete root;
	return 0;
}

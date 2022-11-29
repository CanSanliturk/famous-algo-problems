#include <queue>
#include <math.h>
#include <iostream>
#include <functional>

using namespace std;

template <typename T>
struct BTNode {
	T data;
	BTNode<T>* left = nullptr;
	BTNode<T>* right = nullptr;
	BTNode(T data) : data(data) { }
	BTNode(BTNode& other) = delete;
	~BTNode() {
		delete left;
		delete right;
	}

	static BTNode* createNode(T data) {
		return new BTNode(data);
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

		queue<BTNode<T>*> q;
		q.push(const_cast<BTNode<T>*>(this));

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

	bool isSymmetric() const {

		if ((left && !right) || (!left && right))
			return false;

		if (!left && !right)
			return true;

		if (left->data != right->data)
			return false;

		return left->isSymmetric() && right->isSymmetric();
	}

	const BTNode* findValueInTree(T value) const {

		if (data == value)
			return this;

		if (left) {
			auto leftAns = left->findValueInTree(value);
			if (leftAns)
				return leftAns;
		}

		if (right) {
			auto rightAns = right->findValueInTree(value);
			if (rightAns)
				return rightAns;
		}

		return nullptr;
	}

	T getValueWithComparer(function<bool(T, T)> comparer) const {

		auto ans = data;

		if (left) {
			auto leftAns = left->getValueWithComparer(comparer);
			if (comparer(leftAns, ans))
				ans = leftAns;
		}

		if (right) {
			auto rightAns = right->getValueWithComparer(comparer);
			if (comparer(rightAns, ans))
				ans = rightAns;
		}

		return ans;
	}

	unsigned int getLeafCount() const {

		if (isLeaf())
			return 1;

		auto ans = 0;
		if (left)
			ans += left->getLeafCount();

		if (right)
			ans += right->getLeafCount();

		return ans;
	}

	unsigned int getDiameter() const {

		int option1 = left->getTreeDepth() + right->getTreeDepth();
		int option2 = left->getDiameter();
		int option3 = right->getDiameter();
		return max(option1, max(option2, option3));
	}

	vector<T> getPath(T val) {
		vector<T> ans;
		auto isFound = getPath(val, ans);
		return ans;
	}

private:
	bool isLeaf() const { return !left && !right; }
	bool getPath(T val, vector<T>& ans) {
		
		ans.push_back(data);
		if (data == val)
			return true;

		auto leftAns = left->getPath(val, ans);
		auto rightAns = right->getPath(val, ans);
		
		if (left || right)
			return true;

		ans.pop_back();
		return false;
	}
};

template <typename T>
struct BinaryTreeFactory {

	static BTNode<T>* createTreeFromPreOrderAndInOrder(
		const vector<T>& preorder, const vector<T>& inorder, 
		const unsigned int preorderStart, const unsigned int preorderEnd,
		const unsigned int inorderStart, const unsigned int inorderEnd) {

		if (inorderStart > inorderEnd)
			return nullptr;

		if (preorderStart > preorderEnd)
			return nullptr;

		// first element in preorder is root
		auto root = new BTNode<T>(preorder.at(preorderStart));

		// find correct index values and perform recursive call for left and right substrees
		unsigned int leftPreorderStart, leftPreorderEnd, leftInorderStart, leftInorderEnd;
		unsigned int rightPreorderStart, rightPreorderEnd, rightInorderStart, rightInorderEnd;

		leftInorderStart = inorderStart;
		leftPreorderStart = preorderStart + 1;

		rightInorderEnd = inorderEnd;
		rightPreorderEnd = preorderEnd;

		unsigned int rootIndexAtInorder = 0;
		for (int iIdx = inorderStart; iIdx <= inorderEnd; ++iIdx) {
			if (inorder.at(iIdx) == root->data) {
				rootIndexAtInorder = iIdx;
				break;
			}
		}

		leftInorderEnd = rootIndexAtInorder - 1;
		leftPreorderEnd = leftPreorderStart + leftInorderEnd - leftInorderStart;

		rightInorderStart = rootIndexAtInorder + 1;
		rightPreorderStart = leftPreorderEnd + 1;

		root->left = createTreeFromPreOrderAndInOrder(preorder, inorder, leftPreorderStart, leftPreorderEnd, 
			leftInorderStart, leftInorderEnd);

		root->right = createTreeFromPreOrderAndInOrder(preorder, inorder, rightPreorderStart, rightPreorderEnd,
		  	rightInorderStart, rightInorderEnd);

		return root;
	}


	static BTNode<T>* createTreeFromPostOrderAndInOrder(
		const vector<T>& postorder, const vector<T>& inorder, 
		int ps, int pe,
		int is, int ie) {

		if (is > ie)
			return nullptr;

		if (ps > pe)
			return nullptr;

		auto rootData = postorder.at(pe);
		int rootIndex = -1;
		for (int i = is; i <= ie; ++i) {
			if (inorder.at(i) == rootData) {
				rootIndex = i;
				break;
			}
		}

		int lis = is;
		int lie = rootIndex - 1;
		int lps = ps;
		int lpe = lps + lie - lis;

		int ris = rootIndex + 1;
		int rie = ie;
		int rps = lpe + 1;
		int rpe = pe - 1;

		auto root = new BTNode<T>(rootData);
		root->left = createTreeFromPostOrderAndInOrder(
			postorder, inorder, 
			lps, lpe, 
			lis, lie
		);

		root->right = createTreeFromPostOrderAndInOrder(
			postorder, inorder, 
			rps, rpe, 
			ris, rie
		);

		return root;
	}
};

void tryBTWithCreatedNodes() {

	auto root = BTNode<int>::createNode(1);
	auto n2 = BTNode<int>::createNode(2);
	auto n3 = BTNode<int>::createNode(3);
	auto n4 = BTNode<int>::createNode(4);
	auto n5 = BTNode<int>::createNode(5);
	auto n6 = BTNode<int>::createNode(6);
	auto n7 = BTNode<int>::createNode(7);

	n2->left = n4;
	n2->right = n5;

	n3->left = n6;
	n3->right = n7;

	root->left = n2;
	root->right = n3;

	cout << "Node Count in Tree: " << root->getNodeCount() << endl;
	cout << "Tree Depth: " << root->getTreeDepth() << endl;
	cout << "Leaf Count in Tree: " << root->getLeafCount() << endl;
	cout << "Tree is " << (root->isSymmetric() ? "symmetric" : "not symmetric") << endl;
	cout << "Is 8 in Tree?: " << (root->findValueInTree(8) ? "YES" : "NO") << endl; 
	cout << "Minimum Value in Tree: " << root->getValueWithComparer([](int a, int b) { return a < b; }) << endl; 
	cout << "Maximum Value in Tree: " << root->getValueWithComparer([](int a, int b) { return a > b; }) << endl; 

	cout << "Print tree" << endl;
	root->print();

	cout << "Print Level-Order" << endl;
	root->printLevelOrder();

	cout << "Print In-Order" << endl;
	root->printInOrder();
	cout << endl;

	cout << "Print Pre-Order" << endl;
	root->printPreOrder();
	cout << endl;

	cout << "Print Post-Order" << endl;
	root->printPostOrder();
	cout << endl;

	delete root;
}

void tryCreateBTWithPreOrderAndInOrderInput() {

/*
			3
	9   			20
				15		7
*/
	const vector<int> preorder { 3, 9, 20, 15, 7 };
	const vector<int> inorder { 9, 3, 15, 20, 7 };
	auto root = BinaryTreeFactory<int>::createTreeFromPreOrderAndInOrder(
		preorder, inorder, 
		0, preorder.size() - 1, 
		0, inorder.size() - 1
	);

	cout << "Pre-Order Input: ";
	for (auto i : preorder)
		cout << i << " ";
	cout << endl;

	cout << "In-Order Input: ";
	for (auto i : inorder)
		cout << i << " ";
	cout << endl;

	cout << "Calculated Pre-Order" << endl;
	root->printPreOrder();
	cout << endl;

	cout << "Calculated In-Order" << endl;
	root->printInOrder();
	cout << endl;

	delete root;
}

void tryCreateBTWithPostOrderAndInOrderInput() {

	const vector<int> postorder { 9,15,7,20,3 };
	const vector<int> inorder { 9,3,15,20,7 };
	auto root = BinaryTreeFactory<int>::createTreeFromPostOrderAndInOrder(
		postorder, inorder, 
		0, postorder.size() - 1, 
		0, inorder.size() - 1
	);

	cout << "Post-Order Input: ";
	for (auto i : postorder)
		cout << i << " ";
	cout << endl;

	cout << "In-Order Input: ";
	for (auto i : inorder)
		cout << i << " ";
	cout << endl;

	cout << "Calculated Post-Order" << endl;
	root->printPostOrder();
	cout << endl;

	cout << "Calculated In-Order" << endl;
	root->printInOrder();
	cout << endl;

	delete root;
}


int main() {

	tryCreateBTWithPostOrderAndInOrderInput();

	return 0;
}

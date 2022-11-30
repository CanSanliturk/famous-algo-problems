#include <vector>
#include <iostream>

using namespace std;

// heap is a with two properties: complete binary tree (cbt) and heap order
// except last level, all levels are completely filled for cbt
// nodes are need to be ordered from left to right

class MinPriorityQueue {

	vector<int> pq;

public:

	MinPriorityQueue() { }
	MinPriorityQueue(const vector<int>& unsortedData) { 
		for (auto d : unsortedData)
			insert(d);
	}
	MinPriorityQueue(MinPriorityQueue&) = delete;
	~MinPriorityQueue() = default;

	bool isEmpty() { return pq.size() == 0; };

	unsigned int getSize() { return pq.size(); }

	int getMin() {
		if (isEmpty())
			return 0; // empty queue
		return pq.at(0);
	}

	void insert(int data) {
		pq.push_back(data);

		unsigned int childIndex = pq.size() - 1;

		while (childIndex) {
			unsigned int parentIndex = childIndex == 0 ? 0 : (childIndex - 1) / 2;
			if (pq[childIndex] < pq[parentIndex]) {
				swap(pq[childIndex], pq[parentIndex]);
				childIndex = parentIndex;
			}
			else
				break;
		}
	}

	void removeMinimum() {

		if (isEmpty())
			return;

		swap(pq[0], pq[pq.size() - 1]);
		pq.pop_back();

		if (pq.size() < 2)
			return;

		if (pq.size() == 2) {
			if (pq[1] < pq[0]) {
				swap(pq[1],pq[0]);
				return;
			}
		}

		int pi = 0;
		while (true) {

			auto lci = (2 * pi) + 1;
			auto rci = lci + 1;
			int minIndex = pi;

			if (lci < pq.size() && pq[lci] < pq[minIndex])
				minIndex = lci;
			if (rci < pq.size() && pq[rci] < pq[minIndex])
				minIndex = rci;

			if (minIndex == pi)
				break;

			swap(pq[pi], pq[minIndex]);
			pi = minIndex;
		}

	}
};

int main() {


	auto logger = [](MinPriorityQueue& q) {
		cout << "size: " << q.getSize() << ", min: " << q.getMin() << endl;
	};

	/*
	MinPriorityQueue q;
	q.insert(100);
	q.insert(10);
	q.insert(15);
	q.insert(4);
	q.insert(17);
	q.insert(21);
	q.insert(67);
	*/

	MinPriorityQueue q({ 4, 10, 15, 17, 21, 67, 100 });

	cout << "original: ";
	logger(q);

	while (!q.isEmpty()) {
		q.removeMinimum();
		logger(q);
	}

	return 0;
}


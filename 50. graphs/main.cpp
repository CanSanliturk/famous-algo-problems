#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

struct Graph {
	Graph() = delete;

	Graph(int n) : n(n) {
		matrix.resize(n);
		for (auto& vec : matrix)
			vec.resize(n);
	}

	Graph(const Graph&) = delete;

	~Graph() {}

	void print() {
		for (auto& vec : matrix) {
			for (auto i : vec)
				cout << i << " ";
			cout << endl;
		}
	}

	vector<vector<int>>& getMatrix() {
		return matrix;
	}

	int& operator()(int i, int j) {
		return matrix[i][j];
	}

	int getNodeCount() { return n; }

	void setNodeValue(int idx, int val) {
		matrix[idx][idx] = val;
	}

private:
	vector<vector<int>> matrix;

	int n;
	int v;
};

struct Traverser {

	Traverser() = delete;
	Traverser(Graph& g) : g(g) { }
	Traverser(const Traverser&) = delete;
	~Traverser() { }

	void bfs(int startingVertex) {
		unordered_set<int> visited;
		int numOfComponents = 0;
		bfsHelper(startingVertex, visited, numOfComponents);
		cout << "Number of components from BFS: " << numOfComponents << endl;
	}

	void dfs(int startingVertex) {
		unordered_set<int> visited;
		dfsHelper(startingVertex, visited);
		int numOfComponents = 1;

		while (visited.size() != g.getNodeCount()) {
			for (int i = 0; i < g.getNodeCount(); ++i) {
				if (visited.find(i) == visited.end()) {
					cout << endl;
					dfsHelper(i, visited);
					numOfComponents++;
				}
			}
		}
		cout <<  endl << "Number of components from DFS: " << numOfComponents << endl;
	}

private:
	Graph& g;

	void bfsHelper(int startingVertex, unordered_set<int>& visited, int& numOfComponents) {

		queue<int> q;
		q.push(startingVertex);
		numOfComponents++;

		while (!q.empty()) {

			auto nodeCount = q.size();

			while (nodeCount) {
				auto curr = q.front();
				q.pop();
				visited.insert(curr);
				cout << curr << " ";
				for (int i = 0; i < g.getNodeCount(); ++i) {
					if (i == curr)
						continue;

					if (g(curr, i) && visited.find(i) == visited.end()) {
						q.push(i);
						visited.insert(i);
					}
				}
				nodeCount--;
			}
			
			cout << endl;
		}

		if (visited.size() == g.getNodeCount())
			return;

		for (int i = 0; i < g.getNodeCount(); ++i) {
			if (visited.find(i) == visited.end()) {
				cout << endl;
				bfsHelper(i, visited, numOfComponents);
			}
		}
	}

	void dfsHelper(int startingVertex, unordered_set<int>& visited) {
		visited.insert(startingVertex);
		cout << startingVertex << " ";
		for (int i = 0; i < g.getNodeCount(); ++i) {
			if (i == startingVertex)
				continue;
			if (g(startingVertex, i) && visited.find(i) == visited.end())
				dfsHelper(i, visited);
		}
	}
};

// minimum spanning tree builder
struct MSTBuilder {

	MSTBuilder() = delete;
	MSTBuilder(Graph& g) : g(g) { }
	MSTBuilder(const MSTBuilder&) = delete;
	~MSTBuilder();

	void kruskal() {

		/*
			This is a greedy algorithm that sort the edges and picks the edges
			one-by-one, ensuring that they do not create a cycle. cycle detection
			is achieved by disjoint sets
		*/

		vector<int> djset(g.getNodeCount(), -1);
		


	}

	void prims() {

	}

private:
	Graph& g;
};

void testGraph4Node() {

	cout << "TEST 4 NODE" << endl;

	Graph g(4);

	g(0, 1) = g(0, 2) = g(0, 3) = 1;
	g(1, 0) = 1; g(1, 3) = 1;
	g(2, 0) = 1;
	g(3, 0) = g(3, 1) = 1;

	cout << "Adjacency Matrix" << endl;
	g.print();

	Traverser t(g);
	
	cout << "DFS starting from Vertex-0" << endl;
	t.dfs(0);
	cout << endl;

	cout << "BFS starting from Vertex-0" << endl;
	t.bfs(0);
	cout << endl;
}

void testGraph7Node() {

	cout << "TEST 7 NODE" << endl;

	Graph g(7);

	g(0, 1) = g(0, 2) = 1;
	g(1, 0) = g(1, 3) = g(1, 4) = 1;
	g(2, 0) = g(2, 6) = 1;
	g(3, 1) = g(3, 5) = 1;
	g(4, 1) = g(4, 5) = 1;
	g(5, 3) = g(5, 4) = g(5, 6) = 1;
	g(6, 2) = g(6, 5) = 1;


	cout << "Adjacency Matrix" << endl;
	g.print();

	Traverser t(g);
	
	cout << "DFS starting from Vertex-0" << endl;
	t.dfs(0);
	cout << endl;

	cout << "BFS starting from Vertex-0" << endl;
	t.bfs(0);
	cout << endl;
}

void testUnconnectedGraph() {

	cout << "TEST 8 NODE - Unconnected" << endl;

	Graph g(8);
	g(0, 2) = g(0, 4) = 1;
	g(1, 5) = 1;
	g(2, 0) = g(2, 3) = g(2, 4) = 1;
	g(3, 2) = 1;
	g(4, 0) = g(4, 2) = 1;
	g(5, 1) = 1;
	g(6, 7) = 1;
	g(7, 6) = 1;

	cout << "Adjacency Matrix" << endl;
	g.print();

	Traverser t(g);
	
	cout << "DFS starting from Vertex-0" << endl;
	t.dfs(0);
	cout << endl;

	cout << "BFS starting from Vertex-0" << endl;
	t.bfs(0);
	cout << endl;
}

int main() {
	testGraph4Node();

	testGraph7Node();

	testUnconnectedGraph();

	return 0;
}

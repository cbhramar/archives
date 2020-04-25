#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
public:
	Graph(int N);
	Graph(vector<vector<int> > & adjMat);
	void addEdge(int a, int b, int weight);
	void addTwoWayEdge(int a, int b, int weight);
	void removeEdge(int a, int b);
	void removeTwoWayEdge(int a, int b);
	void printGraph();
	int getNumVertices();
	void addVertices(int n);
	void disjoinVertex(int a);
	void complete(int weight);
	void removeLastVertex();
private:
	int numVertices;
	vector<vector<int> > adjMatrix;
};

Graph createComplete(int N, int weight);
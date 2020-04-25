#include "graphRep.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Graph::Graph(int N){
	numVertices = N;
	std::vector<int> v(numVertices);
	for (int i = 0; i < numVertices; ++i){
		adjMatrix.push_back(v);
	}
}

Graph::Graph(vector<vector<int> > & adjMat){
	adjMatrix = adjMat;
	numVertices = adjMat.size();
}

void Graph::addEdge(int a, int b, int weight = 1){
	if (a >= 0 && b >= 0 && a < numVertices && b < numVertices){
		adjMatrix[a][b] = weight;
	}
}

void Graph::addTwoWayEdge(int a, int b, int weight = 1){
	if (a >= 0 && b >= 0 && a < numVertices && b < numVertices){
		adjMatrix[a][b] = weight;
		adjMatrix[b][a] = weight;
	}
}

void Graph::removeEdge(int a, int b){
	if (a >= 0 && b >= 0 && a < numVertices && b < numVertices){
		adjMatrix[a][b] = 0;
	}
}

void Graph::removeTwoWayEdge(int a, int b){
	if (a >= 0 && b >= 0 && a < numVertices && b < numVertices){
		adjMatrix[a][b] = 0;
		adjMatrix[b][a] = 0;
	}
}

void Graph::printGraph(){
	for (int i = 0; i < numVertices; ++i){
		for (int j = 0; j < numVertices; ++j){
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int Graph::getNumVertices(){
	return numVertices;
}

void Graph::addVertices(int n = 1){
	int verticesToBeAdded = n;
	std::vector<int> v(numVertices + verticesToBeAdded);
	for (int i = 0; i < numVertices; ++i){
		for (int j = 0; j < verticesToBeAdded; ++j){
			adjMatrix[i].push_back(0);
		}
	}
	for (int i = 0; i < verticesToBeAdded; ++i){
		adjMatrix.push_back(v);
	}
	numVertices += verticesToBeAdded;
}

void Graph::disjoinVertex(int a){
	std::vector<int> v(numVertices);
	adjMatrix[a] = v;
	for (int i = 0; i < numVertices; ++i){
		adjMatrix[i][a] = 0;
	}
}

void Graph::complete(int weight = 1){
	for (int i = 0; i < numVertices; ++i){
		for (int j = 0; j < numVertices; ++j){
			if (i != j)
				adjMatrix[i][j] = weight;
		}
	}
}

void Graph::removeLastVertex(){
	--numVertices;
	for (int i = 0; i < numVertices; ++i){
		adjMatrix[i].pop_back();
	}
	adjMatrix.pop_back();
}

Graph createComplete(int N, int weight = 1){
	Graph ret(N);
	ret.complete(weight);
	return ret;
}

int main(){
	Graph g(5);
	g.addEdge(0, 2);
	g.addEdge(0, 3, 5);
	g.printGraph();
	g.addVertices();
	g.printGraph();
	g.addTwoWayEdge(1, 3, 2);
	g.addEdge(2, 3, 4);
	g.printGraph();
	// g.disjoinVertex(3);
	// g.printGraph();
	g.complete(3);
	g.printGraph();
	g.removeLastVertex();
	g.printGraph();
	Graph b = createComplete(4);
	b.printGraph();
}

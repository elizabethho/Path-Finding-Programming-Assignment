#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

class Graph{
private:
	int vertices;
	int edges;
	vector<list<int>> matrix;
	
public:
	
	Graph(int v, int e) : vertices(v), edges(e){
		for(int i = 0; i < vertices; i++){
			matrix.push_back(list<int>());
		}
		for(int i = 0; i < vertices; i++){
			for(int j = 0; j < vertices; j++){
				matrix[i].push_back(0);
			}
		}
	}
	void insert(int r, int c); 
	void output();
	bool adjacencyList();
	bool canDraw();
};
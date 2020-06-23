#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Graph{
private:
	int vertices;
	int edges;
	bool oddVert;
	int start;
	int calc;
	vector<vector<int>> matrix;
	vector<int> path;
	
public:
	
	Graph(int v, int e) : vertices(v), edges(e){
		for(int i = 0; i < vertices; i++){
			matrix.push_back(vector<int>());
			for(int j = 0; j < vertices; j++){
				matrix[i].push_back(0);
			}
		}
		start = 6;
		calc = 0;
	}
	void insert(int r, int c); 
	void output();
	void adjacencyList();
	bool canDraw();
	int getStart(){return start;}
	bool findNext(int row, int col);
	void goBack(int r, int c);
	bool isEmpty();
	void printPath();
};
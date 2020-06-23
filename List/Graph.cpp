#include "Graph.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void Graph::insert(int r, int c){
	matrix[r-1][c-1] = 1;
	matrix[c-1][r-1] = 1;
}

void Graph::output(){
	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

bool Graph::adjacencyList(){
	bool oneStroke = false;
	int numStrokes = 1;
	for(int i = 0; i < vertices; i++){
		cout << (i + 1);
		numStrokes = 0;
		for(int j = 0; j < vertices; j++){
			if(matrix[i][j] == 1){
				cout << " -> " << (j+1);
				numStrokes++;
			}
		}
		if((numStrokes+1) == vertices){
			oneStroke = true;
		}
		cout << endl;
	}
	return oneStroke;
}

bool Graph::canDraw(){
	for(int i = 0; i < vertices; i++){
		cout << (i + 1);
		numStrokes = 0;
		for(int j = 0; j < vertices; j++){
			if(matrix[i][j] == 1){
				cout << " -> " << (j+1);
				numStrokes++;
			}
		}
		if((numStrokes+1) == vertices){
			oneStroke = true;
		}
		cout << endl;
	}
}
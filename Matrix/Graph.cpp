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

void Graph::adjacencyList(){
	for(int i = 0; i < vertices; i++){
		cout << (i + 1);
		for(int j = 0; j < vertices; j++){
			if(matrix[i][j] == 1){
				cout << " -> " << (j+1);
			}
		}
		cout << endl;
	}
}

bool Graph::canDraw(){
	int numStrokes = 0;
	int numOdd = 0;
	bool noOdd = true;
	start = 1;
	for(int i = 0; i < vertices; i++){
		numStrokes = 0;
		for(int j = 0; j < vertices; j++){
			if(matrix[i][j] == 1){
				numStrokes++;
			}
		}
		if(numStrokes % 2 == 1/* && noOdd*/){
			numOdd++;
			start = i+1;
			noOdd = false;
		}
		// else if(numStrokes % 2 == 1){
			// numOdd++;
		// }
	}
	if(numOdd == 0){
		oddVert = false;
		start = 1;
		return true;
	}
	else if(numOdd == 2){
		oddVert = true;
		return true;
	}
	
	return false;
}

bool Graph::findNext(int row, int col){
	bool notFound = true;
	for(col; col < vertices; col++){
		calc++;
		if(matrix[row][col] == 1){
			notFound = false;
			path.push_back(col);
			matrix[row][col] = 0;
			matrix[col][row] = 0;
			if(isEmpty() && path.size() == edges){
				return true;
			}
			findNext(col, 0);
		}
	}
	if(isEmpty() && path.size() == edges){
		return true;
	}
	if(notFound){
		goBack(row, col-1);
	}
	return false;
}

void Graph::goBack(int r, int c){
	calc++;
	int last = path.back();
	//path.erase(--path.end());
	path.pop_back();
	int newLast = path.back();
	matrix[last][newLast] = 1;
	matrix[newLast][last] = 1;
	findNext(newLast, last + 1);
}

bool Graph::isEmpty(){
	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			if(matrix[i][j] == 1){
				return false;
			}
		}
	}
	return true;
}

void Graph::printPath(){
	cout << start << " ";
	for(int i = 0; i < path.size(); i++){
		cout << path[i] + 1 << " ";
	}
	cout << endl << start << " -> " << path[0] + 1 << endl;
	for(int i = 0; i < path.size() - 1; i++){
		cout << path[i] + 1 << " -> " << path[i+1] + 1 << endl;
	}
	
}
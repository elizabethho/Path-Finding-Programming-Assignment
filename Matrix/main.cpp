#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main(int argc, char* argv[]){
	
	if (argc != 2) {
        cout << "Incorrect number of inputs" << endl;
    }
    
	string filename = argv[1];
	ifstream in;
	in.open(filename);
	if (!in.is_open()) {
		cout << "Error: Unable to open file " << filename << endl;
	}
	
	string dimensions;
	int vertices;
	int edges;
	getline(in, dimensions);
	vertices = stoi(dimensions.substr(0, dimensions.find(' ')));
	edges = stoi(dimensions.substr(dimensions.find(" ")));
	
	Graph g1(vertices, edges);
	
	for(int i = 0; i < edges; i++){
		string nums;
		int r;
		int c;
		getline(in, nums);
		r = stoi(nums.substr(0, nums.find(' ')));
		c = stoi(nums.substr(nums.find(" ")));
		g1.insert(c, r);	
	}
	//g1.adjacencyList();
	//g1.output();
	bool hasOneStroke = g1.canDraw();
	
	if(hasOneStroke){
		cout << "True" << endl;
		cout << "Start at: " << g1.getStart() << endl;
		g1.findNext(g1.getStart() - 1, 0);
		cout << "Path: ";
		g1.printPath();
	}
	else{
		cout << "False" << endl;
	}
	
}
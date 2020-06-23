#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main(){
	
	string filename;
	cout << "input file name: ";
	cin >> filename;
	
	ifstream in;
	in.open(filename);
	
	string dimensions;
	int vertices;
	int edges;
	getline(in, dimensions);
	vertices = stoi(dimensions.substr(0, dimensions.find(' ')));
	edges = stoi(dimensions.substr(dimensions.find(" ")));
	
	Graph g1 (vertices, edges);
	g1.output();
	cout << endl;
	
	for(int i = 0; i < edges; i++){
		string nums;
		int r;
		int c;
		getline(in, nums);
		r = stoi(nums.substr(0, nums.find(' ')));
		c = stoi(nums.substr(nums.find(" ")));
		//g1.insert(c, r);	
	}
	//g1.output();
	// cout << endl;
	// bool hasOneStroke = g1.adjacencyList();
	
	// if(hasOneStroke){
		// cout << "True" << endl;
	// }
	// else{
		// cout << "False" << endl;
	// cout << endl;
	// bool hasOneStroke = g1.adjacencyList();
	
	// if(hasOneStroke){
		// cout << "True" << endl;
	// }
	// else{
		// cout << "False" << endl;
	// }
	
}
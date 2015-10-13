/*
Course: Artificial Intelligence CSC 520 ( 001 )
Instructor: Dennis Bahler
Description: Fall 2015, Homework 2 Solutions.
Student Name: Himangshu Ranjan Borah
Student ID: 200105222
Unity ID: hborah

##Code for the problem in question no. 1
##Author : Himangshu Ranjan Borah

This code implements a Uniform Cost Search, GreedySearch and A Star Search on the US map given in the question.
Please call SearchUSA searchtype srccityname destcityname as given in the question where searchtype can be astar, greedy or uniform.

This code uses some data structures and constructs from the C++ Standard Template Library(STL)
The code can be built and run in any compilation environment with STL C++11 support.


VERY IMPORTANT :: PLEASE include -std=gnu++0x in your compiler options if running in Remote Server as the 
compiler of the server is little outdated.
Example command for compiling:
g++ -std=gnu++0x graph.cpp node.cpp SearchUS.cpp -o SearchUSA

Where SearchUSA is the executable. You can also compile the source suing the makefile given in the same directory. run "make all" from the directory where the source code is. 

*/

#include "node.h"

Node::Node(){
	key = "";
	visited = false;
	latitude = 0.00;
	longitude = 0.00;
	pathCostTillNow = 0;
	parentNode = NULL;
	potentialCost = 0.00;
}


Node::Node(string key, bool visited, double latitude, double longitude){
		this->key = key;
		this->visited = visited;
		this->latitude = latitude;
		this->longitude = longitude;
		this->pathCostTillNow = 0;
		this->parentNode = NULL;
		this->potentialCost = 0.00;
}

Node::Node(string key){
		this->key = key;
		visited = false;
		latitude = 0.00;
		longitude = 0.00;
		pathCostTillNow = 0;
		parentNode = NULL;
		potentialCost = 0.00;
}

void Node::addEdgeToNextNode(Node* nextNode, int cost){
	adjacency.insert(pair<Node*, int>(nextNode,cost));
}

void Node::addLatLongData(double latitude, double longitude){
	this->latitude = latitude;
	this->longitude = longitude;
}

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

#ifndef GRAPH_H_
#define GRAPH_H_

#include "node.h"
#include <queue>

#define PI 3.141593

enum FrontierStatus { NOT_IN_FRONTIER, IN_FRONTIER_WITH_LESS_COST, IN_FRONTIER_WITH_MORE_COST };

class Graph {
public:
	Graph();
	virtual ~Graph();
	unordered_map<string,Node> graph;
	queue<Node*> expansion;
	void addEdgeUnidirectional(string src, string dest, int cost);
	void addEdgeBidirectional(string src, string dest, int cost);
	void addNode(Node node);
	void addLatLongData(string nodeKey, double latitude, double longitude);
	void printAdjacency(string node);
	void printAdjacencyAll();
	void printPath(Node* endNode);
	void printExpansion();
	int UniformCostSearch(string start, string end);//return 0 when found, or else -1
	int GreedySearch(string start, string end);//return 0 when found, or else -1
	int AstarSearch(string start, string end);//return 0 when found, or else -1
	FrontierStatus checkFrontierStatus(vector<Node*> queue, Node* node, double estimatedCost);
	double calculateHeuristicEstimate(Node* current, Node* goal);
	void cleanup();/*After using this, you have to re initialize the Graph*/
};

#endif /* GRAPH_H_ */

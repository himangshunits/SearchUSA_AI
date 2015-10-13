/*


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

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <map>


using namespace std;

class Node {
public:
	Node();
	Node(string key, bool visited, double latitude, double longitude);
	Node(string key);
	void addEdgeToNextNode(Node* nextNode, int cost);
	void addLatLongData(double latitude, double longitude);

	bool operator==(const Node& other) const{
			if(this->key == other.key)
				return true;
			else
				return false;
		}

	bool operator<(const Node& other) const{
				if(this->key < other.key)
					return true;
				else
					return false;
			}
	bool operator>(const Node& other) const{
				if(this->key > other.key)
					return true;
				else
					return false;
			}
	bool operator<=(const Node& other) const{
				if(this->key <= other.key)
					return true;
				else
					return false;
			}
	bool operator>=(const Node& other) const{
				if(this->key >= other.key)
					return true;
				else
					return false;
			}
	string key;//key to identify the node
	map<Node*,int> adjacency;//to keep track of the childreb and associated values
	bool visited;
	double latitude;
	double longitude;
	int pathCostTillNow;
	Node* parentNode;
	double potentialCost;
};

//Comparision function to be used by the priority Q
struct PotentialCostCompare
{
	bool operator()(const Node* t1, const Node* t2) const
	{
		return t1->potentialCost > t2->potentialCost;
	}
};

#endif /* NODE_H_ */

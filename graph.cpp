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

#include <queue>
#include <stack>
#include <cmath>
#include "graph.h"

Graph::Graph() {
	// TODO Auto-generated constructor stub

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

void Graph::addEdgeUnidirectional(string src, string dest, int cost){
	graph[src].addEdgeToNextNode(&graph[dest],cost);
}

void Graph::addEdgeBidirectional(string src, string dest, int cost){
	graph[src].addEdgeToNextNode(&graph[dest],cost);
	graph[dest].addEdgeToNextNode(&graph[src],cost);
}

void Graph::addNode(Node node){
	graph.insert(pair<string , Node>(node.key , node));
}

void Graph::addLatLongData(string nodeKey, double latitude, double longitude){
	graph[nodeKey].addLatLongData(latitude, longitude);
}

void Graph::printAdjacency(string node){
	//prints the adcency list of Node node
	cout<<"The current node is with key = "<<graph[node].key<<" :: The adcacencies are ::"<<endl;
	for(map<Node*,int>::iterator it = graph[node].adjacency.begin();it != graph[node].adjacency.end();it++){
		cout<<it->first->key<<" :: "<<it->second<<"   ###  ";
	}
	cout<<endl;
}

void Graph::printAdjacencyAll(){
	//TODO
}

void Graph::printPath(Node* endNode){
	string endKey = endNode->key;
	cout<<endl<<endl<<"The cost(total distance from A to B in the solution path) of the found path is = "<<endNode->pathCostTillNow<<endl;
	
	stack<string> printLine;
	while(endNode != NULL){
		//cout<<endNode->key<<" :: ";
		printLine.push(endNode->key);
		endNode = endNode->parentNode;
	}
	cout<<endl<<"The number of Nodes in the solution Path = "<<printLine.size();
	cout<<endl<<endl<<"The Solution Path is given below ::"<<endl<<endl;
	while(!printLine.empty()){
		if(printLine.top() == endKey){
			cout<<printLine.top()<<endl;
			printLine.pop();
			return;
		}
		cout<<printLine.top()<<" , ";
		printLine.pop();
	}
	cout<<endl<<endl;
	return;
}

void Graph::printExpansion(){
	/* TODO :: test code to check if the expansion has duplicates which is a fatal error!*/
	cout<<endl<<endl<<"The number of Nodes expanded(Cities Visited) = "<<expansion.size()<<endl;
	cout<<endl<<endl<<"The expansion sequence is given below(The Closed List) ::"<<endl<<endl;
	while(!expansion.empty()){
		cout<<expansion.front()->key;
		expansion.pop();
		if(!expansion.empty())
			cout<<" , ";
	}


	cout<<endl<<endl;
	return;
}

int Graph::UniformCostSearch(string start, string end){
	Node* startNode = &graph[start];
	Node* endNode = &graph[end];	
	vector<Node*> queue;
	startNode->pathCostTillNow = 0;
	queue.push_back(startNode);
	std::push_heap(queue.begin(), queue.end(), PotentialCostCompare());
	
	while(!queue.empty()){
		Node* curr = queue.front();

		std::pop_heap(queue.begin(), queue.end(), PotentialCostCompare());
		queue.pop_back();
		
		//cout<<"Current Node going to expand  :: "<<curr->key<<endl;
		expansion.push(curr);
		curr->visited = true;
		if(curr != startNode)
			curr->pathCostTillNow = curr->parentNode->pathCostTillNow + curr->parentNode->adjacency[curr];

		if(curr == endNode){
			//cout<<"path found !!!"<<endl;
			printPath(endNode);
			return 0;
		}
		else {
			map<Node*,int>::iterator iterator;//iterator for curr's adjacency list
			for (iterator = (*curr).adjacency.begin(); iterator != (*curr).adjacency.end(); ++iterator) {
				if(iterator->first->visited == false){
					
					/*Check the Frontier status before doing anything*/
					int tempCostEstimate = curr->pathCostTillNow + curr->adjacency[iterator->first];
					FrontierStatus status = checkFrontierStatus(queue, iterator->first, tempCostEstimate );
					switch(status){
					case NOT_IN_FRONTIER:
						/*Simple insert*/
						iterator->first->parentNode = curr;
						iterator->first->potentialCost = tempCostEstimate;
						//cout<<" NOT_IN_FRONTIER "<<iterator->first->key<<" :: "<<iterator->first->potentialCost<<endl;
						queue.push_back(iterator->first);
						std::push_heap(queue.begin(), queue.end(), PotentialCostCompare());
						break;
					case IN_FRONTIER_WITH_MORE_COST:
						/*Replcament update, basically don't insert anything, just update the node and re heapify*/
						iterator->first->parentNode = curr;
						iterator->first->potentialCost = tempCostEstimate;
						//cout<<" IN_FRONTIER_WITH_LESS_COST "<<iterator->first->key<<" :: "<<iterator->first->potentialCost<<endl;
						//std::push_heap(queue.begin(), queue.end(), PotentialCostCompare());
						std::make_heap(queue.begin(), queue.end(), PotentialCostCompare());
						break;
					case IN_FRONTIER_WITH_LESS_COST:
						continue;/*skip this child as it will lead ito costlier paths*/
						break;
					default:
						cerr<<"NEVER NEVER REACH HERE!";
						break;				
					
					}
				}
			}
		}
			
	}
	return -1;//search failed

}



int Graph::GreedySearch(string start, string end){
	Node* startNode = &graph[start];
	Node* endNode = &graph[end];	
	vector<Node*> queue;
	startNode->pathCostTillNow = 0;
	startNode->potentialCost = calculateHeuristicEstimate(startNode, endNode);//inital distance is from start node, strive to minimize this
	queue.push_back(startNode);
	std::push_heap(queue.begin(), queue.end(), PotentialCostCompare());
	
	while(!queue.empty()){
		Node* curr = queue.front();

		std::pop_heap(queue.begin(), queue.end(), PotentialCostCompare());
		queue.pop_back();
		
		//cout<<"Current Node going to expand  :: "<<curr->key<<endl;
		expansion.push(curr);
		curr->visited = true;
		if(curr != startNode)
			curr->pathCostTillNow = curr->parentNode->pathCostTillNow + curr->parentNode->adjacency[curr];

		if(curr == endNode){
			//cout<<"path found !!!"<<endl;
			printPath(endNode);
			return 0;
		}
		else {
			map<Node*,int>::iterator iterator;//iterator for curr's adjacency
			for (iterator = (*curr).adjacency.begin(); iterator != (*curr).adjacency.end(); ++iterator) {
				if(iterator->first->visited == false){
					
					/*Check the Frontier status before doing anything*/
					//int tempCostEstimate = curr->pathCostTillNow + curr->adjacency[iterator->first];
					double tempCostEstimate = calculateHeuristicEstimate(iterator->first, endNode);
					FrontierStatus status = checkFrontierStatus(queue, iterator->first, tempCostEstimate );
					switch(status){
					case NOT_IN_FRONTIER:
						/*Simple insert*/
						iterator->first->parentNode = curr;
						iterator->first->potentialCost = tempCostEstimate;
						//cout<<iterator->first->key<<" :: "<<iterator->first->potentialCost<<endl;
						queue.push_back(iterator->first);
						std::push_heap(queue.begin(), queue.end(), PotentialCostCompare());
						break;
					case IN_FRONTIER_WITH_MORE_COST:
						/*Replcament update, basically don't insert anything, just update the node and re heapify*/
						iterator->first->parentNode = curr;
						iterator->first->potentialCost = tempCostEstimate;
						//cout<<iterator->first->key<<" :: "<<iterator->first->potentialCost<<endl;
						//std::push_heap(queue.begin(), queue.end(), PotentialCostCompare());
						std::make_heap(queue.begin(), queue.end(), PotentialCostCompare());
						break;
					case IN_FRONTIER_WITH_LESS_COST:
						continue;/*skip this child as it will lead ito costlier paths*/
						break;
					default:
						cerr<<"NEVER NEVER REACH HERE!";
						break;				
					
					}
				}
			}
		}
			
	}
	return -1;//Search failed
}

int Graph::AstarSearch(string start, string end){
	Node* startNode = &graph[start];
	Node* endNode = &graph[end];	
	vector<Node*> queue;
	startNode->pathCostTillNow = 0;
	startNode->potentialCost = calculateHeuristicEstimate(startNode, endNode);//inital distance is from start node, strive to minimize this
	queue.push_back(startNode);
	std::push_heap(queue.begin(), queue.end(), PotentialCostCompare());
	
	while(!queue.empty()){
		Node* curr = queue.front();

		std::pop_heap(queue.begin(), queue.end(), PotentialCostCompare());
		queue.pop_back();
		
		//cout<<"Current Node going to expand  :: "<<curr->key<<endl;
		expansion.push(curr);
		curr->visited = true;
		if(curr != startNode)
			curr->pathCostTillNow = curr->parentNode->pathCostTillNow + curr->parentNode->adjacency[curr];

		if(curr == endNode){
			//cout<<"path found !!!"<<endl;
			printPath(endNode);
			return 0;
		}
		else {
			map<Node*,int>::iterator iterator;//iterator for curr's adjacency
			for (iterator = (*curr).adjacency.begin(); iterator != (*curr).adjacency.end(); ++iterator) {
				if(iterator->first->visited == false){
					
					/*Check the Frontier status before doing anything*/
					//int tempCostEstimate = curr->pathCostTillNow + curr->adjacency[iterator->first];
					double tempCostEstimate = calculateHeuristicEstimate(iterator->first, endNode) + \
						curr->pathCostTillNow + curr->adjacency[iterator->first];
					FrontierStatus status = checkFrontierStatus(queue, iterator->first, tempCostEstimate );
					switch(status){
					case NOT_IN_FRONTIER:
						/*Simple insert*/
						iterator->first->parentNode = curr;
						iterator->first->potentialCost = tempCostEstimate;
						//cout<<iterator->first->key<<" :: "<<iterator->first->potentialCost<<endl;
						queue.push_back(iterator->first);
						std::push_heap(queue.begin(), queue.end(), PotentialCostCompare());
						break;
					case IN_FRONTIER_WITH_MORE_COST:
						/*Replcament update, basically don't insert anything, just update the node and re heapify*/
						iterator->first->parentNode = curr;
						iterator->first->potentialCost = tempCostEstimate;
						//cout<<iterator->first->key<<" :: "<<iterator->first->potentialCost<<endl;
						//std::push_heap(queue.begin(), queue.end(), PotentialCostCompare());
						std::make_heap(queue.begin(), queue.end(), PotentialCostCompare());
						break;
					case IN_FRONTIER_WITH_LESS_COST:
						continue;/*skip this child as it will lead ito costlier paths*/
						break;
					default:
						cerr<<"NEVER NEVER REACH HERE!";
						break;				
					
					}
				}
			}
		}
			
	}
	return -1;//Search failed
}



FrontierStatus Graph::checkFrontierStatus(vector<Node*> queue, Node* node, double estimatedCost){
	for (std::vector<Node*>::iterator it = queue.begin() ; it != queue.end(); ++it){
		if(*it == node){
			/*We found a hit , Now check if it has more or less value*/
			if((*it)->potentialCost > estimatedCost){
				/*Better case, which will need a replacement in the next phase*/
				return IN_FRONTIER_WITH_MORE_COST;
			}
			else{
				/* Bad scene, no replcement needed*/
				return IN_FRONTIER_WITH_LESS_COST;
			}
		}
	}
	return NOT_IN_FRONTIER;
}

double Graph::calculateHeuristicEstimate(Node* current, Node* goal){
	double Lat1, Lat2, Long1, Long2;
	double result;
	Lat1 = current->latitude;
	Long1 = current->longitude;
	Lat2 = goal->latitude;
	Long2 = goal->longitude;
	result = sqrt(pow((69.5 * (Lat1 - Lat2)), 2) + pow((69.5 * cos((Lat1 + Lat2)/360 * PI) * (Long1 - Long2)), 2));
	return result;
}


void Graph::cleanup(){
	graph.clear();
}

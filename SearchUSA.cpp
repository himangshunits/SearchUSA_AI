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

#include <time.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include "node.h"
#include "graph.h"
#include "graph_builder.h"

using namespace std;


int main(int argc, char *argv[]){
	Graph myUSA;
	BuildGraph(myUSA);

	if(argc <= 3){
		cout<<"Error !!! Please enter the arguments properly according to assignment instruction/readme file !"<<endl;
		return -1;
	}
	vector<string> params(argv, argv+argc);
	
	string srcType, startCity, endCity;
	srcType = params[1];
	startCity = params[2];
	endCity = params[3];
	//cout<<"You have entered Search Type = "<<srcType<<endl<<endl;
	//cout<<"Source City = "<<startCity<<" and Destination City = "<<endCity<<endl<<endl;

	if(myUSA.graph.find(startCity) == myUSA.graph.end() || myUSA.graph.find(endCity) == myUSA.graph.end())
	{
		cout<<"Invalid City Name, please try again !!!"<<endl<<endl;
		return -1;
	}
	int result;
	//clock_t t1,t2;
    //t1 = clock();

	if(srcType == "astar"){
		//cout<<"************************************ A-STAR SEARCH ***********************************"<<endl;
		result = myUSA.AstarSearch(startCity,endCity);
		myUSA.printExpansion();
		if(result != 0)
			cout<<endl<<"NO PATHS FOUND !!!"<<endl;
		myUSA.cleanup();
		//cout<<"Success = "<<result<<endl;
	}
	else if(srcType == "greedy"){
		//cout<<"*********************************** GREEDY SEARCH ************************************"<<endl;
		result = myUSA.GreedySearch(startCity,endCity);	
		myUSA.printExpansion();
		if(result != 0)
			cout<<endl<<"NO PATHS FOUND !!!"<<endl;
		myUSA.cleanup();
		//cout<<"Success = "<<result<<endl;
	}
	else if(srcType == "uniform"){	
		//cout<<"******************************* UNIFORM SEARCH ****************************************"<<endl;
		result = myUSA.UniformCostSearch(startCity,endCity);
		myUSA.printExpansion();
		if(result != 0)
			cout<<endl<<"NO PATHS FOUND !!!"<<endl;
		myUSA.cleanup();
		//cout<<"Success = "<<result<<endl;
	}
	else{
		cout<<"Invalid Search Type, please try again!"<<endl<<endl;
	}

    //t2 = clock();
    //float diff ((float)t2-(float)t1);
    //cout<<endl<<"Time of Execution(Mili Seconds) = "<<(diff/CLOCKS_PER_SEC)*1000<<endl;
	//system("pause");
	return 0;
}

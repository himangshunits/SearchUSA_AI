# SearchUSA_AI
Solution to a Pathfinding Agent problem which keeps travelling between different cities of USA and Canada. Reference to AI Class


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
g++ -std=gnu++0x graph.cpp node.cpp SearchUSA.cpp -o SearchUSA

Where SearchUSA is the executable. 

You can also compile the source using the makefile given in the same directory. run "make all" or "make" from the directory where the source code is. The compilation will create the executable SearchUSA which can be used for search queries in the format requested in the question.

the folder should contain the following files for the whole code to run

1. graph_builder.h -> helper to set up the graph Data Structure in memory using HashMaps of Nodes
2. graph.cpp -> Parent class which hold the graph and the search algorithms
3. node.cpp -> The class designed for the cities which are the nodes of the graph. Evry node will have an Adjacency list for move generation
4. SearchUSA -> Master Driver program 
*/

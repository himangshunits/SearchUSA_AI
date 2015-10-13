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
//This file builds the graph from the input

#ifndef GRAPH_BUILDER_
#define GRAPH_BUILDER_

#include "graph.h"

void BuildGraph(Graph& myUSA){
//Add the nodes
myUSA.addNode(Node("albanyGA"));        
myUSA.addNode(Node("albanyNY"));        
myUSA.addNode(Node("albuquerque"));     
myUSA.addNode(Node("atlanta"));         
myUSA.addNode(Node("augusta"));         
myUSA.addNode(Node("austin"));          
myUSA.addNode(Node("bakersfield"));     
myUSA.addNode(Node("baltimore"));       
myUSA.addNode(Node("batonRouge"));      
myUSA.addNode(Node("beaumont"));        
myUSA.addNode(Node("boise"));           
myUSA.addNode(Node("boston"));          
myUSA.addNode(Node("buffalo"));         
myUSA.addNode(Node("calgary"));         
myUSA.addNode(Node("charlotte"));       
myUSA.addNode(Node("chattanooga"));     
myUSA.addNode(Node("chicago"));         
myUSA.addNode(Node("cincinnati"));      
myUSA.addNode(Node("cleveland"));       
myUSA.addNode(Node("coloradoSprings")); 
myUSA.addNode(Node("columbus"));        
myUSA.addNode(Node("dallas"));          
myUSA.addNode(Node("dayton"));          
myUSA.addNode(Node("daytonaBeach"));    
myUSA.addNode(Node("denver"));          
myUSA.addNode(Node("desMoines"));       
myUSA.addNode(Node("elPaso"));          
myUSA.addNode(Node("eugene"));          
myUSA.addNode(Node("europe"));          
myUSA.addNode(Node("ftWorth"));         
myUSA.addNode(Node("fresno"));          
myUSA.addNode(Node("grandJunction"));   
myUSA.addNode(Node("greenBay"));        
myUSA.addNode(Node("greensboro"));      
myUSA.addNode(Node("houston"));         
myUSA.addNode(Node("indianapolis"));    
myUSA.addNode(Node("jacksonville"));    
myUSA.addNode(Node("japan"));           
myUSA.addNode(Node("kansasCity"));      
myUSA.addNode(Node("keyWest"));         
myUSA.addNode(Node("lafayette"));       
myUSA.addNode(Node("lakeCity"));        
myUSA.addNode(Node("laredo"));          
myUSA.addNode(Node("lasVegas"));        
myUSA.addNode(Node("lincoln"));         
myUSA.addNode(Node("littleRock"));      
myUSA.addNode(Node("losAngeles"));      
myUSA.addNode(Node("macon"));           
myUSA.addNode(Node("medford"));         
myUSA.addNode(Node("memphis"));         
myUSA.addNode(Node("mexia"));           
myUSA.addNode(Node("mexico"));          
myUSA.addNode(Node("miami"));           
myUSA.addNode(Node("midland"));         
myUSA.addNode(Node("milwaukee"));       
myUSA.addNode(Node("minneapolis"));     
myUSA.addNode(Node("modesto"));         
myUSA.addNode(Node("montreal"));        
myUSA.addNode(Node("nashville"));       
myUSA.addNode(Node("newHaven"));        
myUSA.addNode(Node("newOrleans"));      
myUSA.addNode(Node("newYork"));         
myUSA.addNode(Node("norfolk"));         
myUSA.addNode(Node("oakland"));         
myUSA.addNode(Node("oklahomaCity"));    
myUSA.addNode(Node("omaha"));           
myUSA.addNode(Node("orlando"));         
myUSA.addNode(Node("ottawa"));          
myUSA.addNode(Node("pensacola"));       
myUSA.addNode(Node("philadelphia"));    
myUSA.addNode(Node("phoenix"));         
myUSA.addNode(Node("pittsburgh"));      
myUSA.addNode(Node("pointReyes"));      
myUSA.addNode(Node("portland"));        
myUSA.addNode(Node("providence"));      
myUSA.addNode(Node("provo"));           
myUSA.addNode(Node("raleigh"));         
myUSA.addNode(Node("redding"));         
myUSA.addNode(Node("reno"));            
myUSA.addNode(Node("richmond"));        
myUSA.addNode(Node("rochester"));       
myUSA.addNode(Node("sacramento"));      
myUSA.addNode(Node("salem"));           
myUSA.addNode(Node("salinas"));         
myUSA.addNode(Node("saltLakeCity"));    
myUSA.addNode(Node("sanAntonio"));      
myUSA.addNode(Node("sanDiego"));        
myUSA.addNode(Node("sanFrancisco"));    
myUSA.addNode(Node("sanJose"));         
myUSA.addNode(Node("sanLuisObispo"));   
myUSA.addNode(Node("santaFe"));         
myUSA.addNode(Node("saultSteMarie"));   
myUSA.addNode(Node("savannah"));        
myUSA.addNode(Node("seattle"));         
myUSA.addNode(Node("stLouis"));         
myUSA.addNode(Node("stamford"));        
myUSA.addNode(Node("stockton"));        
myUSA.addNode(Node("tallahassee"));     
myUSA.addNode(Node("tampa"));           
myUSA.addNode(Node("thunderBay"));      
myUSA.addNode(Node("toledo"));          
myUSA.addNode(Node("toronto"));         
myUSA.addNode(Node("tucson"));          
myUSA.addNode(Node("tulsa"));           
myUSA.addNode(Node("uk1"));             
myUSA.addNode(Node("uk2"));             
myUSA.addNode(Node("vancouver"));       
myUSA.addNode(Node("washington"));      
myUSA.addNode(Node("westPalmBeach"));   
myUSA.addNode(Node("wichita"));         
myUSA.addNode(Node("winnipeg"));        
myUSA.addNode(Node("yuma"));    


//Add lat long data

myUSA.addLatLongData("albanyGA",        31.58,  84.17);
myUSA.addLatLongData("albanyNY",        42.66,  73.78);
myUSA.addLatLongData("albuquerque",     35.11, 106.61);
myUSA.addLatLongData("atlanta",         33.76,  84.40);
myUSA.addLatLongData("augusta",         33.43,  82.02);
myUSA.addLatLongData("austin",          30.30,  97.75);
myUSA.addLatLongData("bakersfield",     35.36, 119.03);
myUSA.addLatLongData("baltimore",       39.31,  76.62);
myUSA.addLatLongData("batonRouge",      30.46,  91.14);
myUSA.addLatLongData("beaumont",        30.08,  94.13);
myUSA.addLatLongData("boise",           43.61, 116.24);
myUSA.addLatLongData("boston",          42.32,  71.09);
myUSA.addLatLongData("buffalo",         42.90,  78.85);
myUSA.addLatLongData("calgary",         51.00, 114.00);
myUSA.addLatLongData("charlotte",       35.21,  80.83);
myUSA.addLatLongData("chattanooga",     35.05,  85.27);
myUSA.addLatLongData("chicago",         41.84,  87.68);
myUSA.addLatLongData("cincinnati",      39.14,  84.50);
myUSA.addLatLongData("cleveland",       41.48,  81.67);
myUSA.addLatLongData("coloradoSprings", 38.86, 104.79);
myUSA.addLatLongData("columbus",        39.99,  82.99);
myUSA.addLatLongData("dallas",          32.80,  96.79);
myUSA.addLatLongData("dayton",          39.76,  84.20);
myUSA.addLatLongData("daytonaBeach",    29.21,  81.04);
myUSA.addLatLongData("denver",          39.73, 104.97);
myUSA.addLatLongData("desMoines",       41.59,  93.62);
myUSA.addLatLongData("elPaso",          31.79, 106.42);
myUSA.addLatLongData("eugene",          44.06, 123.11);
myUSA.addLatLongData("europe",          48.87,  -2.33);
myUSA.addLatLongData("ftWorth",         32.74,  97.33);
myUSA.addLatLongData("fresno",          36.78, 119.79);
myUSA.addLatLongData("grandJunction",   39.08, 108.56);
myUSA.addLatLongData("greenBay",        44.51,  88.02);
myUSA.addLatLongData("greensboro",      36.08,  79.82);
myUSA.addLatLongData("houston",         29.76,  95.38);
myUSA.addLatLongData("indianapolis",    39.79,  86.15);
myUSA.addLatLongData("jacksonville",    30.32,  81.66);
myUSA.addLatLongData("japan",           35.68, 220.23);
myUSA.addLatLongData("kansasCity",      39.08,  94.56);
myUSA.addLatLongData("keyWest",         24.56,  81.78);
myUSA.addLatLongData("lafayette",       30.21,  92.03);
myUSA.addLatLongData("lakeCity",        30.19,  82.64);
myUSA.addLatLongData("laredo",          27.52,  99.49);
myUSA.addLatLongData("lasVegas",        36.19, 115.22);
myUSA.addLatLongData("lincoln",         40.81,  96.68);
myUSA.addLatLongData("littleRock",      34.74,  92.33);
myUSA.addLatLongData("losAngeles",      34.03, 118.17);
myUSA.addLatLongData("macon",           32.83,  83.65);
myUSA.addLatLongData("medford",         42.33, 122.86);
myUSA.addLatLongData("memphis",         35.12,  89.97);
myUSA.addLatLongData("mexia",           31.68,  96.48);
myUSA.addLatLongData("mexico",          19.40,  99.12);
myUSA.addLatLongData("miami",           25.79,  80.22);
myUSA.addLatLongData("midland",         43.62,  84.23);
myUSA.addLatLongData("milwaukee",       43.05,  87.96);
myUSA.addLatLongData("minneapolis",     44.96,  93.27);
myUSA.addLatLongData("modesto",         37.66, 120.99);
myUSA.addLatLongData("montreal",        45.50,  73.67);
myUSA.addLatLongData("nashville",       36.15,  86.76);
myUSA.addLatLongData("newHaven",        41.31,  72.92);
myUSA.addLatLongData("newOrleans",      29.97,  90.06);
myUSA.addLatLongData("newYork",         40.70,  73.92);
myUSA.addLatLongData("norfolk",         36.89,  76.26);
myUSA.addLatLongData("oakland",         37.80, 122.23);
myUSA.addLatLongData("oklahomaCity",    35.48,  97.53);
myUSA.addLatLongData("omaha",           41.26,  96.01);
myUSA.addLatLongData("orlando",         28.53,  81.38);
myUSA.addLatLongData("ottawa",          45.42,  75.69);
myUSA.addLatLongData("pensacola",       30.44,  87.21);
myUSA.addLatLongData("philadelphia",    40.72,  76.12);
myUSA.addLatLongData("phoenix",         33.53, 112.08);
myUSA.addLatLongData("pittsburgh",      40.40,  79.84);
myUSA.addLatLongData("pointReyes",      38.07, 122.81);
myUSA.addLatLongData("portland",        45.52, 122.64);
myUSA.addLatLongData("providence",      41.80,  71.36);
myUSA.addLatLongData("provo",           40.24, 111.66);
myUSA.addLatLongData("raleigh",         35.82,  78.64);
myUSA.addLatLongData("redding",         40.58, 122.37);
myUSA.addLatLongData("reno",            39.53, 119.82);
myUSA.addLatLongData("richmond",        37.54,  77.46);
myUSA.addLatLongData("rochester",       43.17,  77.61);
myUSA.addLatLongData("sacramento",      38.56, 121.47);
myUSA.addLatLongData("salem",           44.93, 123.03);
myUSA.addLatLongData("salinas",         36.68, 121.64);
myUSA.addLatLongData("saltLakeCity",    40.75, 111.89);
myUSA.addLatLongData("sanAntonio",      29.45,  98.51);
myUSA.addLatLongData("sanDiego",        32.78, 117.15);
myUSA.addLatLongData("sanFrancisco",    37.76, 122.44);
myUSA.addLatLongData("sanJose",         37.30, 121.87);
myUSA.addLatLongData("sanLuisObispo",   35.27, 120.66);
myUSA.addLatLongData("santaFe",         35.67, 105.96);
myUSA.addLatLongData("saultSteMarie",   46.49,  84.35);
myUSA.addLatLongData("savannah",        32.05,  81.10);
myUSA.addLatLongData("seattle",         47.63, 122.33);
myUSA.addLatLongData("stLouis",         38.63,  90.24);
myUSA.addLatLongData("stamford",        41.07,  73.54);
myUSA.addLatLongData("stockton",        37.98, 121.30);
myUSA.addLatLongData("tallahassee",     30.45,  84.27);
myUSA.addLatLongData("tampa",           27.97,  82.46);
myUSA.addLatLongData("thunderBay",      48.38,  89.25);
myUSA.addLatLongData("toledo",          41.67,  83.58);
myUSA.addLatLongData("toronto",         43.65,  79.38);
myUSA.addLatLongData("tucson",          32.21, 110.92);
myUSA.addLatLongData("tulsa",           36.13,  95.94);
myUSA.addLatLongData("uk1",             51.30,   0.00);
myUSA.addLatLongData("uk2",             51.30,   0.00);
myUSA.addLatLongData("vancouver",       49.25, 123.10);
myUSA.addLatLongData("washington",      38.91,  77.01);
myUSA.addLatLongData("westPalmBeach",   26.71,  80.05);
myUSA.addLatLongData("wichita",         37.69,  97.34);
myUSA.addLatLongData("winnipeg",        49.90,  97.13);
myUSA.addLatLongData("yuma",            32.69, 114.62);

//Add edges
myUSA.addEdgeBidirectional("albanyNY", "montreal", 226); myUSA.addEdgeBidirectional("albanyNY", "boston", 166); myUSA.addEdgeBidirectional("albanyNY", "rochester", 148);
myUSA.addEdgeBidirectional("albanyGA", "tallahassee", 120); myUSA.addEdgeBidirectional("albanyGA", "macon", 106);
myUSA.addEdgeBidirectional("albuquerque", "elPaso", 267);  myUSA.addEdgeBidirectional("albuquerque", "santaFe", 61);
myUSA.addEdgeBidirectional("atlanta", "macon", 82); myUSA.addEdgeBidirectional("atlanta", "chattanooga", 117);
myUSA.addEdgeBidirectional("augusta", "charlotte", 161);  myUSA.addEdgeBidirectional("augusta", "savannah", 131);
myUSA.addEdgeBidirectional("austin", "houston", 186);  myUSA.addEdgeBidirectional("austin", "sanAntonio", 79);
myUSA.addEdgeBidirectional("bakersfield", "losAngeles", 112);  myUSA.addEdgeBidirectional("bakersfield", "fresno", 107);
myUSA.addEdgeBidirectional("baltimore", "philadelphia", 102);  myUSA.addEdgeBidirectional("baltimore", "washington", 45);
myUSA.addEdgeBidirectional("batonRouge", "lafayette", 50);  myUSA.addEdgeBidirectional("batonRouge", "newOrleans", 80);
myUSA.addEdgeBidirectional("beaumont", "houston", 69);  myUSA.addEdgeBidirectional("beaumont", "lafayette", 122);
myUSA.addEdgeBidirectional("boise", "saltLakeCity", 349); myUSA.addEdgeBidirectional("boise", "portland", 428);
myUSA.addEdgeBidirectional("boston", "providence", 51);
myUSA.addEdgeBidirectional("buffalo", "toronto", 105); myUSA.addEdgeBidirectional("buffalo", "rochester", 64);  myUSA.addEdgeBidirectional("buffalo", "cleveland", 191);
myUSA.addEdgeBidirectional("calgary", "vancouver", 605);  myUSA.addEdgeBidirectional("calgary", "winnipeg", 829);
myUSA.addEdgeBidirectional("charlotte", "greensboro", 91);
myUSA.addEdgeBidirectional("chattanooga", "nashville", 129);
myUSA.addEdgeBidirectional("chicago", "milwaukee", 90);  myUSA.addEdgeBidirectional("chicago", "midland", 279);
myUSA.addEdgeBidirectional("cincinnati", "indianapolis", 110);  myUSA.addEdgeBidirectional("cincinnati", "dayton", 56);
myUSA.addEdgeBidirectional("cleveland", "pittsburgh", 157);  myUSA.addEdgeBidirectional("cleveland", "columbus", 142);
myUSA.addEdgeBidirectional("coloradoSprings", "denver", 70);  myUSA.addEdgeBidirectional("coloradoSprings", "santaFe", 316);
myUSA.addEdgeBidirectional("columbus", "dayton", 72);
myUSA.addEdgeBidirectional("dallas", "denver", 792);  myUSA.addEdgeBidirectional("dallas", "mexia", 83);
myUSA.addEdgeBidirectional("daytonaBeach", "jacksonville", 92);  myUSA.addEdgeBidirectional("daytonaBeach", "orlando", 54);
myUSA.addEdgeBidirectional("denver", "wichita", 523);  myUSA.addEdgeBidirectional("denver", "grandJunction", 246);
myUSA.addEdgeBidirectional("desMoines", "omaha", 135);  myUSA.addEdgeBidirectional("desMoines", "minneapolis", 246);
myUSA.addEdgeBidirectional("elPaso", "sanAntonio", 580); myUSA.addEdgeBidirectional("elPaso", "tucson", 320);
myUSA.addEdgeBidirectional("eugene", "salem", 63);  myUSA.addEdgeBidirectional("eugene", "medford", 165);
myUSA.addEdgeBidirectional("europe", "philadelphia", 3939);
myUSA.addEdgeBidirectional("ftWorth", "oklahomaCity", 209);
myUSA.addEdgeBidirectional("fresno", "modesto", 109);
myUSA.addEdgeBidirectional("grandJunction", "provo", 220);
myUSA.addEdgeBidirectional("greenBay", "minneapolis", 304); myUSA.addEdgeBidirectional("greenBay", "milwaukee", 117);
myUSA.addEdgeBidirectional("greensboro", "raleigh", 74);
myUSA.addEdgeBidirectional("houston", "mexia", 165);
myUSA.addEdgeBidirectional("indianapolis", "stLouis", 246);
myUSA.addEdgeBidirectional("jacksonville", "savannah", 140);  myUSA.addEdgeBidirectional("jacksonville", "lakeCity", 113);
myUSA.addEdgeBidirectional("japan", "pointReyes", 5131);  myUSA.addEdgeBidirectional("japan", "sanLuisObispo", 5451);
myUSA.addEdgeBidirectional("kansasCity", "tulsa", 249);  myUSA.addEdgeBidirectional("kansasCity", "stLouis", 256); myUSA.addEdgeBidirectional("kansasCity", "wichita", 190);
myUSA.addEdgeBidirectional("keyWest", "tampa", 446);
myUSA.addEdgeBidirectional("lakeCity", "tampa", 169);  myUSA.addEdgeBidirectional("lakeCity", "tallahassee", 104);
myUSA.addEdgeBidirectional("laredo", "sanAntonio", 154); myUSA.addEdgeBidirectional("laredo", "mexico", 741);
myUSA.addEdgeBidirectional("lasVegas", "losAngeles", 275);  myUSA.addEdgeBidirectional("lasVegas", "saltLakeCity", 486);
myUSA.addEdgeBidirectional("lincoln","wichita", 277);  myUSA.addEdgeBidirectional("lincoln", "omaha", 58);
myUSA.addEdgeBidirectional("littleRock", "memphis", 137); myUSA.addEdgeBidirectional("littleRock", "tulsa", 276);
myUSA.addEdgeBidirectional("losAngeles", "sanDiego", 124);  myUSA.addEdgeBidirectional("losAngeles", "sanLuisObispo", 182);
myUSA.addEdgeBidirectional("medford", "redding", 150);
myUSA.addEdgeBidirectional("memphis", "nashville", 210);
myUSA.addEdgeBidirectional("miami", "westPalmBeach", 67);
myUSA.addEdgeBidirectional("midland", "toledo", 82);
myUSA.addEdgeBidirectional("minneapolis", "winnipeg", 463);
myUSA.addEdgeBidirectional("modesto", "stockton", 29);
myUSA.addEdgeBidirectional("montreal", "ottawa", 132);
myUSA.addEdgeBidirectional("newHaven", "providence", 110);  myUSA.addEdgeBidirectional("newHaven", "stamford", 92);
myUSA.addEdgeBidirectional("newOrleans", "pensacola", 268);
myUSA.addEdgeBidirectional("newYork", "philadelphia", 101);
myUSA.addEdgeBidirectional("norfolk", "richmond", 92);  myUSA.addEdgeBidirectional("norfolk", "raleigh", 174);
myUSA.addEdgeBidirectional("oakland", "sanFrancisco", 8); myUSA.addEdgeBidirectional("oakland", "sanJose", 42);
myUSA.addEdgeBidirectional("oklahomaCity", "tulsa", 105);
myUSA.addEdgeBidirectional("orlando", "westPalmBeach", 168); myUSA.addEdgeBidirectional("orlando", "tampa", 84);
myUSA.addEdgeBidirectional("ottawa", "toronto", 269);
myUSA.addEdgeBidirectional("pensacola", "tallahassee", 120);
myUSA.addEdgeBidirectional("philadelphia", "pittsburgh", 319); myUSA.addEdgeBidirectional("philadelphia", "newYork", 101); myUSA.addEdgeBidirectional("philadelphia", "uk1", 3548);
myUSA.addEdgeBidirectional("philadelphia", "uk2", 3548);
myUSA.addEdgeBidirectional("phoenix", "tucson", 117);  myUSA.addEdgeBidirectional("phoenix", "yuma", 178);
myUSA.addEdgeBidirectional("pointReyes", "redding", 215);  myUSA.addEdgeBidirectional("pointReyes", "sacramento", 115);
myUSA.addEdgeBidirectional("portland", "seattle", 174);  myUSA.addEdgeBidirectional("portland", "salem", 47);
myUSA.addEdgeBidirectional("reno", "saltLakeCity", 520);  myUSA.addEdgeBidirectional("reno", "sacramento", 133);
myUSA.addEdgeBidirectional("richmond", "washington", 105);
myUSA.addEdgeBidirectional("sacramento", "sanFrancisco", 95);  myUSA.addEdgeBidirectional("sacramento", "stockton", 51);
myUSA.addEdgeBidirectional("salinas", "sanJose", 31);  myUSA.addEdgeBidirectional("salinas", "sanLuisObispo", 137);
myUSA.addEdgeBidirectional("sanDiego", "yuma", 172);
myUSA.addEdgeBidirectional("saultSteMarie", "thunderBay", 442);  myUSA.addEdgeBidirectional("saultSteMarie", "toronto", 436);
myUSA.addEdgeBidirectional("seattle", "vancouver", 115);
myUSA.addEdgeBidirectional("thunderBay", "winnipeg", 440);
}

#endif /*GRAPH_BUILDER_*/

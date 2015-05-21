/*Paul Morales
*/
#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include "Winery.h"
#include "ParseWineries.h"
#include <string>
#include <iostream>
using namespace std;

class WeightedGraph
{
public:
	WeightedGraph();
	~WeightedGraph();
	void remove(int);
	void buildFromFile(string);
	Winery& getWinery(int);
	void shortestPath(int);
	void printNames();
	void printNamesDistance();
	int getClosest();
	void printPath(int);
	void printMatrix();
	void getDistance(int, double&);
	string getName(int);
	int getNumMatrix();
	void setStart(int);
private:
	double matrix[31][31];
	Winery canyonValley; 
	Winery wineryList[31];
	int numMatrix;
	int path[31];
	int prev[31];
	double distance[31];
	bool visited[31];
	int start;
	int stop;
};

#endif
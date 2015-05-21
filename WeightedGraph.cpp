/*Paul Morales
*/
#include "WeightedGraph.h"
#include "Winery.h"
#include "ParseWineries.h"
#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;



WeightedGraph::WeightedGraph()
{
	
	stop = 1;
	wineryList[0].setName("Canyon Valley");
	for (int row = 0; row < 31; row++)
	{
		for (int col = 0; col < 31; col++)
		{
			matrix[row][col] = 999;
		}
	}
	numMatrix = 0;

		matrix[0][0] = 0;
		start = 0;
}


WeightedGraph::~WeightedGraph()
{
}



void WeightedGraph::remove(int n)
{

}

void WeightedGraph::buildFromFile(string fn)
{

	

	ParseWineries p(fn);
	p.parseW(wineryList,numMatrix);
	
	for (int i = stop; i <= numMatrix; i++)
	{

		if (matrix[0][i] == 999)
		{
			matrix[0][i] = wineryList[i].getMilesToAWinery(0);
			matrix[i][0] = wineryList[i].getMilesToAWinery(0);
		}
		for (int j = 1; j <= numMatrix; j++)
		{

			
			try{

			matrix[i][j] = wineryList[i].getMilesToAWinery(j);
			}
			catch (...)
			{
				
			}
		}
	}
	stop = numMatrix+1;
}


int WeightedGraph::getClosest()
{
	

	double minDist = 999;
	int closest;
	for (int i = 0; i <= numMatrix; i++)
	{
		
		if ((!visited[i]) && (minDist >= distance[i]))
		{
			minDist = distance[i];
			closest = i;
		}
	}
	return closest;
	cout << " ";
}
void WeightedGraph::shortestPath(int src)
{
	start = src;

	
	for (int i = 0; i <= numMatrix; i++)
	{
		visited[i] = false;
		prev[i] = -1;
		distance[i] = 999;
	}
	distance[start] = 0;

	double min = 999;
	int closest;
	int e = 0;
	while (e < numMatrix)
	{
		closest = getClosest();
		visited[closest] = true;
		for (int i = 0; i <= numMatrix; i++)
		{
			if ((!visited[i]) && (matrix[closest][i] > 0))
			{
				if (distance[i] > distance[closest] + matrix[closest][i])
				{
					distance[i] = distance[closest] + matrix[closest][i];
					prev[i] = closest;
				}
			}
		}
		e++;
	}
	
	

}

void WeightedGraph::printPath(int src)
{
	if (src == start)
		cout << wineryList[src].getName().c_str() << " to ";
	else if (prev[src] == -1)
		cout << " No Path" << endl;
	else
	{
		printPath(prev[src]);
		cout << wineryList[src].getName().c_str() << " to " << endl;
		cout << distance[src] << endl;
	}



}

void WeightedGraph::getDistance(int src, double &traveled)
{
	if (src == start)
		traveled += 0;
	else if (prev[src] == -1)
		traveled += 0;
	else
	{
		getDistance(prev[src], traveled);
		traveled += distance[src];
	}
}

Winery& WeightedGraph::getWinery(int index)
{
	if (index > 0 && index <= numMatrix)
	{
		return wineryList[index];
	}
	else throw 20;
}

void WeightedGraph::printNames()
{
	for (int i = 1; i <= numMatrix; i++)
	{
		cout << i << ". " << wineryList[i].getName() << endl;
	}
}
void WeightedGraph::printNamesDistance()
{
	for (int i = 1; i <= numMatrix; i++)
	{
		cout << i << ". " << wineryList[i].getName() << endl;
		cout << "Distance: " << wineryList[i].getMilesToCV()
			<< endl;
	}
}



void WeightedGraph::printMatrix()
{
	

	for (int row = 0; row <= numMatrix; row++)
	{
			cout << wineryList[row].getName() << endl;
		for (int col = 0; col <= numMatrix; col++)
		{
			cout << "(" << col << ", " << row << "): " << matrix[row][col] << "  ";
				cout << endl;
		}
	}
}

int WeightedGraph::getNumMatrix()
{
	return numMatrix;
}

void WeightedGraph::setStart(int s)
{
	start = s;
}


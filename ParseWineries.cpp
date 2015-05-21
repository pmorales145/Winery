/*Paul Morales
*/
#include <iostream>
#include <fstream>
#include "Winery.h"
#include "ParseWineries.h"
#include <string>
#include "WeightedGraph.h"
#include <sstream>
using namespace std;




ParseWineries::ParseWineries(string fn)
{


	inf.open(fn.c_str());

	
}

ParseWineries::~ParseWineries()
{
	
}

void ParseWineries::parseW(Winery *arr, int &aMax)
{
	string x;
	Winery t;
	int k;
	double l;
	double *distance;
	wine * f;

	while (!inf.eof())
	{

		if (inf.peek() == '\n')
		{
			inf.get();
			if ((inf.peek() == '\n'))
				throw 10;
		}

		
			inf.ignore(16);
			getline(inf,x);
			t.setName(x);

			inf.ignore(14);
			getline(inf, x);
			//k = atoi(x.c_str());
			istringstream(x) >> k;
			t.setNumber(k);

			inf.ignore(29);
			getline(inf, x);
			//k = atoi(x.c_str());
			istringstream(x) >> k;
			t.setNumOfOtherWineries(k);
			distance = new double[k+1];

			
			for (int i = 0; i < k; i++)
			{
				inf.ignore(10, ' ');
				getline(inf, x);
				//l = stod(x);
				istringstream(x) >> l;
				distance[i+1] = l;
				
			}

			

			getline(inf, x, ' ');
			inf.ignore(999, '\n');
			//l = stod(x);
			istringstream(x) >> l;
			t.setMilesToCV(l);
			distance[0] = l;

			t.setWineries(distance);
			delete[]distance;
			getline(inf, x, ' ');
			inf.ignore(999, '\n');
			//k = atoi(x.c_str());
			istringstream(x) >> k;
			t.setNumWines(k);
			f = new wine[k];

			for (int i = 0; i < k; i++)
			{
				string s;
				int y;
				double p;
				getline(inf, s);
				getline(inf, x);
				//y = atoi(x.c_str());
				istringstream(x) >> y;
				getline(inf, x);
				//p = stod(x);
				istringstream(x) >> p;
				wine newWine(s, y, p);
				f[i] = newWine;
			}
			t.setWines(f);

		
			
			
			arr[t.getNumber()] = t;
			

			
			if (inf.peek() == '\n')
			{
				inf.get();
				if ((inf.peek() == '\n'))
					break;
				
			}
	}
	aMax = t.getNumber();

}

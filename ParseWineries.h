/*Paul Morales
*/
#ifndef PARSEWINERIES_H
#define PARSEWINERIES_H
#include <iostream>
#include <fstream>
#include "Winery.h"
using namespace std;


class ParseWineries
{
private:
	ifstream inf;
public:
	ParseWineries(string);
	~ParseWineries();
	void parseW(Winery *arr, int &);
};


#endif
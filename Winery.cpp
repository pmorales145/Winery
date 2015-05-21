/*Paul Morales
*/
#include "Winery.h"
#include <iostream>
#include <string>
using namespace std;

class NullArrayException{};
Winery::Winery()
{ 
	name = "NONE";
	number = -1;
	numOfOtherWineries = -1;
	wineries = NULL;
	milesToCV = -1;
	numWines = -1;
	wines = NULL;

}


Winery::~Winery()
{
	if (wineries != NULL)
		delete[]wineries;
	if (wines != NULL)
		delete[]wines;
}

void Winery::setMilesToCV(double m)
{
	milesToCV = m;
}

void Winery::setName(string n)
{
	name = n;
}

void Winery::setNumber(unsigned n)
{
	number = n;
}
void Winery::setNumOfOtherWineries(unsigned n)
{
	numOfOtherWineries = n;
}

void Winery::setNumWines(unsigned n)
{
	numWines = n;
}
void Winery::setWines(wine * w)
{
	if (wines != NULL)
		delete[]wines;

	try
	{
	
		wines = new wine[numWines];
		for (int i = 0; i < numWines; i++)
			wines[i] = w[i];

	
	}
	catch (...)
	{
		cout  << "caught something" << endl;
	}

}

void Winery::setWineries(double* w)
{
	if (wineries != NULL)
		delete[]wineries;

	wineries = new double[numOfOtherWineries+1];
	for (int i = 0; i < numOfOtherWineries+1; i++)
		wineries[i] = w[i];
}

string Winery::getName()
{
	return name;
}
unsigned Winery::getNumber()
{
	return number;
}
unsigned Winery::getNumOfOtherWineries()
{
	return numOfOtherWineries;
}
double * Winery::getWineries()
{
	return wineries;
}

double Winery::getMilesToCV()
{
	return milesToCV;
}
unsigned Winery::getNumWines()
{
	
	return numWines;
}

wine * Winery::getWines()
{
	return wines;
}

bool operator ==(const Winery lhs, const Winery rhs)
{
	return lhs.milesToCV == rhs.milesToCV;
}

bool operator >(const Winery lhs, const Winery rhs)
{
	return lhs.milesToCV > rhs.milesToCV;
}

bool operator<(const Winery lhs, const Winery rhs)
{
	return lhs.milesToCV < rhs.milesToCV;
}

bool operator !=(const Winery lhs, const Winery rhs)
{
	return !(lhs == rhs);
}

bool operator <=(const Winery lhs, const Winery rhs)
{
	return !(lhs > rhs);
}

bool operator >=(const Winery lhs, const Winery rhs)
{
	return (lhs < rhs);
}

double Winery::getMilesToAWinery(unsigned m)
{
	if (wineries != NULL)
		return wineries[m];
	//else throw NullArrayException();		
}

wine Winery::getAWine(int w)
{
	if (wines != NULL)
		return wines[w];
	//else throw NullArrayException();
}
Winery::Winery(const Winery &rhs )
{
	
	*this = rhs;
	
}

Winery& Winery::operator=(const Winery &rhs)
{
	name = rhs.name;
	number = rhs.number;
	numOfOtherWineries = rhs.numOfOtherWineries;
	numWines = rhs.numWines;
	milesToCV = rhs.milesToCV;
	setWineries(rhs.wineries);
	setWines(rhs.wines);

	return *this;
}

void Winery::setAWine(string nm, double pr, unsigned yr)
{
	if (wines == NULL)
	{
		numWines = 1;
		wines = new wine[1];
		wines[0] = wine(nm,yr,pr);
	}
	else
	{
		
		wine temp(nm, yr, pr);
		wine* wineptr = new wine[numWines+1];
		for (int i = 0; i < numWines; i++)
			wineptr[i] = wines[i];
		wineptr[numWines] = temp;
		numWines++;
		setWines(wineptr);
		
	}
}

void Winery::setAWineName(unsigned index,string nm)
{
	if (index <= numWines)
		wines[index].name = nm;
	//else throw NullArrayException();
}

void Winery::setAWinePrice(unsigned index, double pr)
{
	if (index <= numWines)
		wines[index].price = pr;
	//else throw NullArrayException();
}

void Winery::setAWineYear(unsigned index, unsigned yr)
{
	if (index <= numWines)
		wines[index].year = yr;
	//else throw NullArrayException();
}

void Winery::printWines()
{
	
	for (int i = 0; i < numWines; i++)
	{

		cout << i+1  <<
			". " << wines[i].name << endl;
		cout << "Price: " <<
			wines[i].price << endl;
		cout << "Year: " << 
			wines[i].year << endl;
	}
}
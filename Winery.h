/*Paul Morales
*/
#ifndef WINERY_H
#define WINERY_H
#include <iostream>
using namespace std;
struct wine
{
	string name;
	unsigned year;
	double price;
	wine(string s, unsigned y, double p)
	{
		name = s;
		year = y;
		price = p;
	}
	wine(){}

};
class Winery
{
public:

	Winery();
	~Winery();
	void setName(string);
	void setNumber(unsigned);
	void setNumOfOtherWineries(unsigned);
	void setWineries(double*);
	void setMilesToCV(double);
	void setNumWines(unsigned);
	void setWines(wine*);
	void setAWine(string, double, unsigned);
	void setAWineName(unsigned,string);
	void setAWinePrice(unsigned,double);
	void setAWineYear(unsigned,unsigned);
	void printWines();
	string getName();
	unsigned getNumber();
	unsigned getNumOfOtherWineries();
	double * getWineries();
	double getMilesToAWinery(unsigned);
	double getMilesToCV();
	unsigned getNumWines();
	wine * getWines();
	wine getAWine(int);
	Winery(const Winery&);
	Winery& operator=(const Winery &rhs);
	friend bool operator ==(const Winery, const Winery);
	friend bool operator>(const Winery, const Winery);
	friend bool operator <(const Winery, const Winery);
	friend bool operator!=(const Winery, const Winery);
	friend bool operator <=(const Winery, const Winery);
	friend bool operator >=(const Winery, const Winery);

private:
	string name;
	int number;
	int numOfOtherWineries;
	double *wineries; //dynamic array of doubles
	double milesToCV;
	int numWines;
	wine *wines; //dynamic array of wines
	

};

#endif

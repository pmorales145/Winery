Main/*Paul Morales
*/
#ifndef MAINMENU_H
#define MAINMENU_H
#include "Winery.h"
#include "WeightedGraph.h"
#include <iostream>
#include <string>
class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void run();
	void homescreen(bool&);
	bool password(string);
	void maintenance();
	void buyWine();
	void shortest();
	void all();
private:
	double traveled;
	int start, current;
	WeightedGraph W;
	double grandtotal;

};

#endif
/*Paul Morales
*/
#include "MainMenu.h"
#include <iomanip>
#include <iostream>
using namespace std;

MainMenu::MainMenu()
{
	W.buildFromFile("wineries.txt");
	grandtotal = 0;
	start = 0;
	traveled = 0;
}


MainMenu::~MainMenu()
{
}


void MainMenu::run()
{
	bool run=true;
	while (run)
	{
		homescreen(run);
	}
}

void MainMenu::homescreen(bool &r)
{
	int udi;
	cout << "1. List Wineries" << endl;
	cout << "2. Shortest Trip" << endl;
	cout << "3. Visit All Wineries" << endl;
	cout << "4. Purchase Wine" << endl;
	cout << "5. Maintenance" << endl;
	cout << "6. Quit" << endl;

	cin >> udi;

	switch (udi)
	{
	case 1:
		W.printNamesDistance();
		cout << endl;
		break;
	case 2:
		shortest();
		break;
	case 3:
		all();
		break;
	case 4:
		buyWine();
		break;
	case 5:
		maintenance();
		break;
	case 6:
		r = false;
		break;
	default:
		break;

	}
}
bool MainMenu::password(string s)
{
	if (s == "password")
		return true;
	else
		return false;
}

void MainMenu::maintenance()
{
	string pass;
	cout << "Enter Password" << endl;
	cin.ignore(999, '\n');
	getline(cin, pass);
	if (password(pass))
	{
		int udi;
		int winery, wn, year;
		string s, name;
		double price;

		cout << "1. Add new Wineries" << endl;
		cout << "2. Add Wines" << endl;
		cout << "3. Change Wine Prices" << endl;
		cin >> udi;
		switch (udi)
		{
		case 1:
			cout << "Enter File Name " << endl;
			cin >> s;
			try
			{
				W.buildFromFile(s);
			}
			catch (...)
			{
				cout << "File not found" << endl;
			}
			break;
		case 2:
			W.printNames();
			cout << "Select A Winery" << endl;
			cin >> winery;
			
			if (winery > 0 && winery <= W.getNumMatrix())
			{
				cin.ignore(999, '\n');
				cout << "Enter Name of Wine" << endl;
				getline(cin, name);
				cout << "Enter Price of Wine" << endl;
				cin >> price;
				cout << "Enter Year of wine" << endl;
				cin >> year;


				W.getWinery(winery).setAWine(name, price, year);
				W.getWinery(winery).printWines();
			}
			break;
		case 3:
			W.printNames();
			cout << "Select A Winery" << endl;
			cin >> winery;
			if (winery > 0 && winery <= W.getNumMatrix())
			{
				W.getWinery(winery).printWines();
				cout << "Select Wine" << endl;
				cin >> wn;
				cout << "Enter Price" << endl;
				cin >> price;
				W.getWinery(winery).setAWinePrice(wn - 1, price);
				W.getWinery(winery).printWines();
			}

			break;
		default:
			break;

		}
	}
	else
	{
		cout << "Invalid Password" << endl;
	}


}


void MainMenu::buyWine()
{



	int wineNum;

	if (current == 0)
		cout << "Must Travel To A Winery First" << endl;
	else
	{
		cout << "0. None" << endl;
		W.getWinery(current).printWines();
		cout << "Select Wine To Purchase" << endl;
		cin >> wineNum;
		if (wineNum > 0 && wineNum <= W.getWinery(current).getNumWines())
		{
			cout << "Price is: " << W.getWinery(current).getAWine(wineNum - 1).price << endl;
			grandtotal += W.getWinery(current).getAWine(wineNum - 1).price;
		}

	}


	

	cout << "Your Total is: " << grandtotal << endl;

}

void MainMenu::shortest()
{
	
	
	W.printNames();
	cout << endl << "Enter Winery To Visit" << endl;
	cin >> current;
	if (current > 0 && current <= W.getNumMatrix())
	{
		W.shortestPath(start);
		W.printPath(current);
		W.getDistance(current, traveled);
		
		start = current;
		cout << "Traveled: " << traveled << endl;
	}
}

void MainMenu::all()
{
	start = 0;
	current = 0;
	for (int i = 0; i <= W.getNumMatrix(); i++)
	{
		W.shortestPath(i);
		W.printPath(current);
		W.getDistance(current, traveled);
		start = current;
	}
	cout << "Traveled: " << traveled << endl;
}
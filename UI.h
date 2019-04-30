#pragma once
#include "Taxi.h"
#include <list>

class UI											// 2 a)
{
public:
	void printMenu()const;							// 4 c)
	int chooseTaxi(std::list<Taxi*> Taxis);
	void menu();
	void listofTaxi(std::list<Taxi*>* Taxis);
	void DELETElistofTaxi(std::list<Taxi*>* Taxis);
	int checkInput(int choose);
	double checkDist(double distance);
	UI();
	~UI();
};


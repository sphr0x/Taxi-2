#pragma once
#include "Taxi.h"
#include <list>

class UI											
{
public:
	void printMenu()const;							
	int chooseTaxi(std::list<Taxi*>& Taxis);
	void menu();
	void listofTaxi(std::list<Taxi*>* Taxis);				// 4 a)
	void DELETElistofTaxi(std::list<Taxi*>* Taxis);			// 4 a) -> free RAM
	int checkInput(int choose)const;
	double checkDist(double distance)const;
	UI();
	~UI();
};


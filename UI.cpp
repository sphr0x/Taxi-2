#pragma once
#include "UI.h"
#include <list>

void UI::printMenu()const {												
	std::cout << "\n\t\t\t__/ Bitte Aktion via Nummerierung waehlen : \n\n" << "\t\t\t1 : Fahrt mit Fahrgast verbuchen\n";
	std::cout << "\t\t\t2 : Fahrt ohne Fahrgast verbuchen\n" << "\t\t\t3 : Tanken\n";
	std::cout << "\t\t\t4 : Taxistatus ausgeben\n" << "\t\t\t5 : Beenden\n";
	std::cout << "\t\t\t6 : Bildschirm bereinigen & Menu erneut zeigen\n" << std::endl;
}
int UI::chooseTaxi(std::list<Taxi*>& Taxis) {													
	int choose;

	std::cout << "\t\t\tBitte Taxi waehlen: ( 1 oder 2 )" << std::endl;
	while (1) {
		std::cout << "\tEingabe: ";
		std::cin >> choose;
		choose = checkInput(choose);
		if (choose == 1) {
			std::cout << "\t\t\tTaxi-Bez: " << Taxis.front()->getName() << std::endl;		// 1 d)
			return choose;
		}
		else if(choose == 2) {
			std::cout << "\t\t\tTaxi-Bez: " << Taxis.back()->getName() << std::endl;		// 1 d)
			return choose;
		}
		else {
			std::cerr << "\t\t\tFehler: Bitte 1 oder 2 waehlen!" << std::endl;
		}
	}
}
void UI::menu() {								
	int choose;
	double distance;
	std::list<Taxi*> Taxis;
	
	listofTaxi(&Taxis);
	printMenu();
	while (1) {
		std::cout << "\tEingabe: ";
		std::cin >> choose;
		choose = checkInput(choose);
		switch (choose) {
		case 1:
			std::cout << "\t\t\tGewuenschte Reisestrecke eingeben ( in km ):" << std::endl;
			std::cout << "\tEingabe: ";
			std::cin >> distance;
			distance = checkDist(distance);
			if (chooseTaxi(Taxis) == 1) {
				Taxis.front()->bookTrip(1, distance);
			}
			else{
				Taxis.back()->bookTrip(1, distance);
			}
			break;
		case 2:
			std::cout << "\t\t\tGewuenschte Reisestrecke eingeben ( in km ):" << std::endl;
			std::cout << "\tEingabe: ";
			std::cin >> distance;
			distance = checkDist(distance);
			if (chooseTaxi(Taxis) == 1) {
				Taxis.front()->bookTrip(0, distance);
			}
			else {
				Taxis.back()->bookTrip(0, distance);
			}
			break;
		case 3:
			if (chooseTaxi(Taxis) == 1) {
				Taxis.front()->fillUp();
			}
			else{
				Taxis.back()->fillUp();
			}
			break;
		case 4:
			if (chooseTaxi(Taxis) == 1) {
				std::cout << Taxis.front()->getState() << std::endl;		// 2 b)
			}
			else {
				std::cout << Taxis.back()->getState() << std::endl;			// 2 b)
			}
			break;
		case 5:
			DELETElistofTaxi(&Taxis);			// hier delete list ! 
			//std::cout << m_count2;
			std::cout << "\n\t\t\t\t\t\tBeende Programm!" << std::endl;
			return;
		case 6:		
			system("cls");			
			std::cout << "\n\n\t\t\tBildschrim bereinigt! ( Taxidaten sind gespeichert )\n\n" << std::endl;
			UI::printMenu();
			break;
		default:
			std::cerr << "\t\t\tFehler: Bitte 1-6 waehlen!" << std::endl;
			break;
		}
	}
}
void UI::listofTaxi(std::list<Taxi*>* Taxis) {
	Taxi *car3 = new Taxi(75, 7.2, 0.7);
	Taxis->push_back(car3);
	Taxi *car4 = new Taxi(90, 12.5, 0.95);
	Taxis->push_back(car4);
	std::cout << "\t\t\t Taxi 1 hat den Bezeichner: " << car3->getName() << std::endl << "\t\t\t Taxi 2 hat den Bezeichner: " << car4->getName() << std::endl;

	//std::list<Taxi*>::iterator it = Taxis.begin(); it != Taxis.end(); ++it;		// zugriff auf n-tes element
}
void UI::DELETElistofTaxi(std::list<Taxi*>* Taxis) {
	int i = 1;
	while ((Taxis->size()) != 0) {
		delete(Taxis->front());
		Taxis->pop_front();
		std::cout << "\t\t\tInfo: Listenelement "<< i++ << " geloescht via \"delete\" !" << std::endl;
	}
}
int UI::checkInput(int choose)const {
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(30, '\n');
		std::cerr << "\t\t\tFehler: Bitte eine Ziffer eingeben: " << std::endl;
		std::cout << "\tEingabe: ";
		std::cin >> choose;
	}
	return choose;
};
double UI::checkDist(double distance)const {
	while ((distance < 0) || (std::cin.fail())) {
		std::cin.clear();
		std::cin.ignore(30, '\n');
		std::cerr << "\t\t\tFehler: Bitte eine positive Zahl eingeben: " << std::endl;
		std::cout << "\tEingabe: ";
		std::cin >> distance;
	}
	return distance;
};
UI::UI()
{
}
UI::~UI()
{
}

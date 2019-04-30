#include "UI.h"
#include "Taxi.h"
#include <list>

void UI::printMenu()const {												// 3 a+b)
	std::cout << "\n\t\t\t__/ Bitte Aktion via Nummerierung waehlen : \n\n" << "\t\t\t1 : Fahrt mit Fahrgast verbuchen\n";
	std::cout << "\t\t\t2 : Fahrt ohne Fahrgast verbuchen\n" << "\t\t\t3 : Tanken\n";
	std::cout << "\t\t\t4 : Taxistatus ausgeben\n" << "\t\t\t5 : Beenden\n";
	std::cout << "\t\t\t6 : Bildschirm bereinigen & Menu erneut zeigen\n" << std::endl;
}
int UI::chooseTaxi(std::list<Taxi*> Taxis) {													// 3 a+b)
	int choose;

	std::cout << "\t\t\tBitte Taxi waehlen: ( 1 oder 2 )" << std::endl;
	while (1) {
		std::cout << "\tEingabe: ";
		std::cin >> choose;
		choose = checkInput(choose);
		if (choose == 1) {
			std::cout << "\t\t\tTaxi-Bez: " << Taxis.front()->getName() << std::endl;
			return choose;
		}
		else if(choose == 2) {
			std::cout << "\t\t\tTaxi-Bez: " << Taxis.back()->getName() << std::endl;
			return choose;
		}
		else {
			std::cerr << "\t\t\tFehler: Bitte 1 oder 2 waehlen!" << std::endl;
		}
	}
}
void UI::menu() {								// 2 b) -> 3 a+b)
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
				std::cout << Taxis.front()->getState() << std::endl;		// 3.2 b) works
			}
			else {
				std::cout << Taxis.back()->getState() << std::endl;		// 3.2 b) works
			}
			break;
		case 5:
			DELETElistofTaxi(&Taxis);			// hier delete list ! 
			std::cout << "\n\t\t\t\t\t\tBeende Programm!" << std::endl;
			return;
		case 6:		
			system("cls");			// da curses.h / conio.h nicht existent
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
	Taxi *car3 = new Taxi("nummer1", 75, 7.2, 0.7);
	Taxi *car4 = new Taxi("nummer2", 90, 12.5, 0.95);
	std::cout << "\t\t\tTaxi_001 Bez: " << car3->getName() << std::endl << "\t\t\tTaxi_002 Bez: " << car4->getName() << std::endl;
	Taxis->push_back(car3);
	Taxis->push_back(car4);
	//std::cout << Taxis.front().toString() << std::endl;	// zugriff auf 1. listenelement ? ref
	//std::cout << car3.toString() << std::endl;			// zg via ref
	//std::cout << Taxis->front()->toString() << std::endl;	// zugriff auf 1. listenelement ? ptr
	//std::cout << car4->toString() << std::endl;			// zugriff via ptr
	//std::list<Taxi*>::iterator it = Taxis.begin(); it != Taxis.end(); ++it;		// zugriff auf n-tes element
};
void UI::DELETElistofTaxi(std::list<Taxi*>* Taxis) {
	int i = 1;
	while ((Taxis->size()) != 0) {
		delete(Taxis->front());
		Taxis->pop_front();
		std::cout << "\t\t\tInfo: Listenelement "<< i++ << " geloescht via \"delete\" !" << std::endl;
	}
	
};
int UI::checkInput(int choose) {
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(30, '\n');
		std::cerr << "\t\t\tFehler: Bitte eine Ziffer eingeben: " << std::endl;
		std::cout << "\tEingabe: ";
		std::cin >> choose;
	}
	return choose;
};
double UI::checkDist(double distance) {
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

#include <iostream>
#include "Taxi.h"
#include <cstdlib>													// std::rand() 
#include <string>													// std::to_string
#include <iomanip>													// std::setw(), std::fixed() etc...
#include <sstream>													// std::ostringstream
#include <list>														// std::list<typ> bezeichner
/*
void Taxi::initialize(double fuelM, double consump, double price) {		// 1 a)
	m_consumpKM = consump/100;
	m_costKM = price;
	m_fuelMAX = fuelM;
	m_mileageDAY = 0.0;
	m_fuelACT = m_fuelMAX;
	m_balance = 0.0;
}
*/
void Taxi::bookTrip(bool guest, double distance) {						// 1 a)
	double fuelR = std::rand() % 35 + 130;								// random number from 130 - 165
														
	if ((m_fuelACT >= (m_consumpKM*distance)) && (distance >= 0)){
		m_mileageDAY += distance;
		m_fuelACT -= (m_consumpKM*distance);
		if (guest == 1) {
			m_balance += (distance * m_costKM);
			std::cout << "\t\t\tGebucht mit Fahrgast!" << std::endl;
		}
		else if (guest == 0) {
			std::cout << "\t\t\tGebucht ohne Fahrgast!" << std::endl;
		}
	}
	else if (distance < 0) {
		std::cerr << "\t\t\tFehler: Reisestrecke im negativen Bereich !" << std::endl;
		std::cout << "\t\t\tAchtung: Bitte neue Aktion waehlen !" << std::endl;
		return;
	}
	else {
		std::cerr << "\t\t\tFehler: Tankfuellung nicht ausreichend!" << std::endl;
		std::cout << "\t\t\tAchtung: Bitte neue Aktion waehlen !" << std::endl;
		return;
	}
}
void Taxi::fillUp(double fPrice ) {										// 1 a)
	if (m_fuelACT == m_fuelMAX) {
		std::cerr << "\t\t\tFehler: Tank voll!" << std::endl;
	}
	else if ((m_balance >= ((fPrice/100)*(m_fuelMAX - m_fuelACT)))) {
		m_balance -= (fPrice/100) * (m_fuelMAX - m_fuelACT);
		m_fuelACT = m_fuelMAX;
		std::cout << "\t\t\tAufgetankt!" << std::endl;
	}
	else {
		std::cerr << "\t\t\tFehler: Unzureichende Finanzmittel!" << std::endl;
	}
}
std::string Taxi::toString()const {										// 1 a)
	return "\t\t\tTageskilometerstand: " + std::to_string(m_mileageDAY) + "\n\t\t\tTankinhalt: " + std::to_string(m_fuelACT)
		+ "\n\t\t\tGeldbilanz: " + std::to_string(m_balance);
}
Taxi::Taxi(std::string name, double fuelMax, double consump, double price, double balance )
	: m_consumpKM(consump / 100), m_costKM(price), m_fuelMAX(fuelMax), m_mileageDAY(0.0), m_fuelACT(fuelMax),
	m_balance(balance) {
	setName(name);
}
Taxi::Taxi(const Taxi &input) 
	: m_number(input.m_number), m_consumpKM(input.m_consumpKM), m_costKM(input.m_costKM), m_fuelMAX(input.m_fuelMAX), m_mileageDAY(0.0), m_fuelACT(input.m_fuelMAX),
	m_balance(0.0) {
}
	/*							Beschreibung und Erklärung Aufgabe 3.3 b) :
	Um überhaupt kompillieren zu können, muss eine Initialisierungsliste im Defaultkonstruktor angelegt werden, 
	in dem mindestens alle konstanten Membervariablen initialisiert werden, da dieser Typ von Variable eine 
	sofortige Initialisierung erfordert. Die Instanzierung eines Objekts erfolgt dann anhand der 
	Initialisierungsliste des Defaultkonstruktors, solang ein Objekt nur mit dem Bezeichner erstellt wird. 
	Bsp: Taxi car;																								*/
Taxi::Taxi()															// 3.3 c)
	: m_number("Taxi_001"), m_consumpKM(7.2 / 100), m_costKM(0.7), m_fuelMAX(75), m_mileageDAY(0.0), m_fuelACT(75),
	m_balance(0.0) {
}
Taxi::~Taxi(){
}
void Taxi::setName(std::string name) {					// 3.1 b)
	std::cout << "\t\t\tBitte eine Taxibezeichnung eingeben: " << std::endl << "\tEingabe:";
	while (1) {
		std::cin >> name;
		if (name.length() <= 8) {
			m_number = name;
			return;
		}
		else {
			std::cerr << "\t\t\tFehler: Die Eingabe darf nicht mehr als 8 Zeichen beinhalten!" << std::endl << "\tEingabe:";
		}
	}
}
std::string Taxi::getName()const {
	return m_number;
}
std::string Taxi::getState()const {
	const char seperate = ' ';
	const int widthNum = 8;
	std::ostringstream out;
	
	out << "\t\t\t" << std::left << std::setw(widthNum) << std::setfill(seperate) << m_number << " >>" <<
	std::right << std::setw(widthNum) << std::setfill(seperate) << std::fixed << std::setprecision(2) << m_mileageDAY << " km," <<
	std::right << std::setw(widthNum) << std::setfill(seperate) << std::fixed << std::setprecision(2) << m_fuelACT << " l," <<
	std::right << std::setw(widthNum) << std::setfill(seperate) << std::fixed << std::setprecision(2) << m_balance << " Euro" << std::endl;
	return out.str();

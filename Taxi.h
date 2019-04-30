#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <list>

class Taxi																			// 1 a)
{
private:
	double m_mileageDAY;
	double m_fuelACT;
	const double m_fuelMAX;															// 4 b)
	const double m_consumpKM;														// 4 b)
	const double m_costKM;															// 4 b)
	double m_balance;

	std::string m_number;	// 3.1 a) works
	
public:
	// void initialize(double fuelM, double consump, double price = 0.0);			// 4 a)
	void bookTrip(bool guest, double distance = 0.0);
	void fillUp(double fPrice = std::rand() % 35 + 130);
	std::string toString()const;													// 4 c)
	Taxi(std::string name, double fuelMax, double consump, double price, double balance = 0.0);	// 4 a) | 3.3 b)
	Taxi();
	Taxi(const Taxi &input);														// 4 a)
	~Taxi();

	void setName(std::string name);
	std::string getName()const;
	std::string getState()const;	// 3.2 a) works
	// std::stringstream getState2()const;
};


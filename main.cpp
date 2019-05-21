#pragma once
#include <iostream>
#include "UI.h"


		/* ### C23 � Labor�bung 3 - Stringstreams, Kosmetik, Liste, dynamischer Speicher & statische Variablen ### */

int main()
{	
	UI program;
	Taxi car1(75, 7.2, 0.7,"123456789");					// 1 c) check length of description				
	Taxi car2(car1);										// 5 b)
	Taxi car5;

	program.menu();

	std::cout << "\n\t\t\tWeitere Ausgaben bzgl diverser Aufgabenstellungen:\n" << std::endl;
	std::cout << car1.getState();
	std::cout << car2.getState() << "\n";					// 5 b) copy proove
	std::cout << "\n\t\t\tAnzahl aller erzeugten Objekte: " << car1.getCountofTaxis() << std::endl;	// whole counter proove
	return 0;
}

		/*					Beschreibung und Erkl�rung -> Aufgabe 3.3 b) :
Um �berhaupt kompillieren zu k�nnen, muss eine Initialisierungsliste im Defaultkonstruktor angelegt werden,
in dem mindestens alle konstanten Membervariablen initialisiert werden, da dieser Typ von Variable eine
sofortige Initialisierung erfordert. Die Instanzierung eines Objekts erfolgt dann anhand der
Initialisierungsliste des Defaultkonstruktors, solang ein Objekt nur mit dem Bezeichner erstellt wird.
Bsp: Taxi car;
		*/

		/*								Kommentar zu 5 c) :
Ich habe alle Kontruktoren mit der Iteration der Variable "m_countEver" versehen, um zu gew�hrleisten, dass
auch alle _jemals_ erzeugten Taxis im Programm gez�hlt werden.
		*/

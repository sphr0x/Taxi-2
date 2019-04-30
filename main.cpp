#include "Taxi.h"
#include <iostream>
#include "UI.h"


		/* ### C23 – Laborübung 2 - Konstruktoren im angewandten Beispiel: Taxiunternehmen ### */

int main()
{	
	UI program;

	program.menu();
	return 0;
}


/* aufg 3:
- mileage,fuelACT,balance for every single car

1) 
X m_bezeichner taxi
X set/get name f neue vari
X konstruktor neue vari parameter -------------------> 8 chars in const ?? how ?? -> fkt in const, nciht ü init-liste
X auswahl der taxis -> bezeichner anzeige
2)
X print() von taxi into getstate() - stringstream tabelle 
X getstate() in whole program
3)
X balance into default para @ konst
X reaction of programm after 3.1)
X txi object via standart konstr init
4)
X taxi obj in list | List of pointer @ taxi obj | dynamic ! ( new / delete ? )
X whole prog access via list -.- | delete after !
5)
- count taxi obj  with static m_vari  | use constr to increase and deconstr to decrease
- check correct count with specific initialization -> Taxi a (...); Taxi b(a) 
  fix programm, as b shall be a copy of b
- def constr uses static m_var to count generating the "001...002" in: "Taxi_001" 
  count ALL obj ever produced | do NOT use static m_var from 5 a) as its decreased by deconstr

			 XXXXXXXXXXXXXXXXXXXXXXXXXXX
					 DONT FORGET:
  implement the checkDist&checkInput fkt from labor 2 !!!
*/
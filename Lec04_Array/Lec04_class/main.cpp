//#include "Complex.h"
#include "Car.h"
#include "SportsCar.h"
int main()
{
	//	Complex a, b, c;
//	a.read("A=");
//	a.print("A =");

	Car myCar;
	Car momsCar(10, "k5", 2);
	SportsCar mySecondCar(100, "Tycan", 3);


	myCar.whereAmI();
	momsCar.whereAmI();
	myCar.changeGear(3);
	momsCar.speedUp();
	momsCar.display();

	mySecondCar.setTurbo(true);
	
}
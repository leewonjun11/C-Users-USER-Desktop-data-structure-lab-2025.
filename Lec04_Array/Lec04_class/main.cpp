//#include "Complex.h"
//#include "Car.h"
//#include "SportsCar.h"
#include "Music.h"
int main()
{
	//music streaming service¸¦ »ý¼º
	MusicStreamingService my_service("spotify");
	my_service.addMusic("polaroidLove", "ENHYPEN", "DIMENSION", 2022);
	my_service.addMusic("Ditto", "NewJeans", "ALBUM", 2023); 
	my_service.addMusic("CAKE", "ITZY", "ALBUM", 2023);
	my_service.addMusic("sundayMorning", "asdasd", "ALBUM", 2023);
	// search music by title
	string music_title;
	cout << "Enter the Music Title; ";
	cin >> music_title;
	Music* result = my_service.searchByTitle(music_title);
	if (result != NULL) {
		cout << "Found: << result ->getTitle() << "by" <<result->
	}


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

Music* result = my_service.searchByTitle(music_title);
if (result != NULL) {
	cout<< "Found:" << result->getTitle() << "by" << result.size() << "somgs by" << artist_name << ";" << endl;
	for(int i = 0)
}

#include <iostream>
#include "Date.h"
#include "Car.h"
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int CarsCount = 0;
	printf("Cars: ");
	cin >> CarsCount;
	Car* cars = new Car[CarsCount];
	for (int i = 0; i < CarsCount; i++)
	{
		cout << "Car " << i + 1 << endl;
		string color;
		int wheelsCount, seatsCount;
		int year, month, day;
		cin >> color >> wheelsCount >> seatsCount;
		cin >> year >> month >> day;

		Date date;
		date.setDate(year, month, day);
		cars[i].setDate(date);
		cars[i].setColor(color);

		//Get Wheels
		cout << "Wheels of Car " << i + 1 << endl;
		for (int j = 0; j < wheelsCount; j++)
		{
			cin >> year >> month >> day;
			date.setDate(year, month, day);
			CarWheel cw(date);
			cars[i].addWheel(cw);
		}
		//Get Seats
		cout << "Seats of Car " << i + 1 << endl;
		for (int j = 0; j < seatsCount; j++)
		{
			string material;
			cin >> color >> material >> year >> month >> day;
			date.setDate(year, month, day);
			CarSeat cs(color, material, date);
			cars[i].addSeat(cs);
		}
	}

	cout << endl << endl;
	for (int i = 0; i < CarsCount; i++)
	{
		int wheelsCount, seatsCount;
		wheelsCount = cars[i].getWheelsCount();
		seatsCount = cars[i].getSeatsCount();
		cout << "Car " << i + 1 << endl;
		cars[i].print();
		cout << wheelsCount << endl;
		CarWheel* wheels = cars[i].getWheels();
		CarSeat* seats = cars[i].getSeats();
		for (int j = 0; j < wheelsCount; j++)
			wheels[j].print();
		cout << seatsCount << endl;
		for (int j = 0; j < seatsCount; j++)
			seats[j].print();
		cout << endl << endl;
	}
	delete[] cars;
}
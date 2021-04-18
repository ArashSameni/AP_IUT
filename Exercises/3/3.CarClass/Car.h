#include <iostream>
#include "Date.h"
using namespace std;

class CarWheel {
	Date productionDate;
public:
	CarWheel(Date _date = Date());
	Date getDate();
	void setDate(Date date);
	void print();
};

class CarSeat {
	string color;
	string material;
	Date productionDate;
public:
	CarSeat(string _color = "", string _material = "", Date date = Date());
	string getColor();
	string getMaterial();
	Date getDate();
	void setColor(string _color);
	void setMaterial(string _material);
	void setDate(Date date);
	void print();
};

class Car
{
	CarWheel* wheels = nullptr;
	int wheelsCount = 0;
	CarSeat* seats = nullptr;
	int seatsCount = 0;
	Date productionDate;
	string color;
public:
	void addWheel(CarWheel& carwheel);
	void addSeat(CarSeat& seat);
	void setColor(string _color);
	void setDate(Date& date);
	void removeWheel(int pos);
	void removeSeat(int pos);
	int getWheelsCount();
	int getSeatsCount();
	CarWheel* getWheels();
	CarSeat* getSeats();
	string getColor();
	Date getDate();
	void print();
	~Car();
};
#include "Car.h"

//Car

void Car::addWheel(CarWheel& carwheel) {
	CarWheel* tmp = new CarWheel[++wheelsCount];
	for (int i = 0; i < wheelsCount - 1; i++)
		tmp[i] = wheels[i];
	tmp[wheelsCount - 1] = carwheel;
	delete[] wheels;
	wheels = tmp;
}

void Car::addSeat(CarSeat& seat) {
	CarSeat* tmp = new CarSeat[++seatsCount];
	for (int i = 0; i < seatsCount - 1; i++)
		tmp[i] = seats[i];
	tmp[seatsCount - 1] = seat;
	delete[] seats;
	seats = tmp;
}

void Car::setColor(string _color) {
	color = _color;
}

void Car::setDate(Date& date) {
	productionDate = date;
}

void Car::removeWheel(int pos) {
	CarWheel* tmp = new CarWheel[--wheelsCount];
	for (int i = 0; i <= wheelsCount; i++)
		if(i != pos)
			tmp[i] = wheels[i];
	delete[] wheels;
	wheels = tmp;
}
void Car::removeSeat(int pos) {
	CarSeat* tmp = new CarSeat[--seatsCount];
	for (int i = 0; i <= seatsCount; i++)
		if (i != pos)
			tmp[i] = seats[i];
	delete[] seats;
	seats = tmp;
}

int Car::getWheelsCount() { return wheelsCount; }
int Car::getSeatsCount() { return seatsCount; }
CarWheel* Car::getWheels() { return wheels; }
CarSeat* Car::getSeats() { return seats; }
string Car::getColor() { return color; }
Date Car::getDate() { return productionDate; }

void Car::print() {
	cout << color << " " << productionDate.getStrDate() << endl;
}

Car::~Car() {
	delete[] wheels;
	delete[] seats;
}

//Car Wheel
CarWheel::CarWheel(Date _date) { productionDate = _date; }
Date CarWheel::getDate() { return productionDate; }
void CarWheel::setDate(Date date) { productionDate = date; }
void CarWheel::print() {
	cout << productionDate.getDate() << endl;
}


//Car Seat
CarSeat::CarSeat(string _color, string _material, Date date) {
	color = _color;
	material = _material;
	productionDate = date;
}
string CarSeat::getColor() { return color; }
string CarSeat::getMaterial() { return material; }
Date CarSeat::getDate() { return productionDate; }
void CarSeat::setColor(string _color) { color = _color; }
void CarSeat::setMaterial(string _material) { material = _material; }
void CarSeat::setDate(Date date) { productionDate = date; }
void CarSeat::print() {
	cout << material << " " << productionDate.getDate() << " " << color << endl;
}
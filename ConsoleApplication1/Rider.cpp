#include "Rider.h"
#include <iostream>
using namespace std;

Rider::Rider(int num, Elevator *e, int start) {
	s = Waiting;
	startFloor = start;
	number = num;
	PushButton(e, startFloor);
	cout << "\nPassenger " << number << " is waiting at floor " << startFloor<<"\n";
	Respond(e);
}

void Rider::Respond(Elevator *e) {
	if ((s == Waiting) && (e->CurrentFloor == startFloor)) {
		GetOn(e);
		return;
	}

	if ((s == Abroad) && (e->CurrentFloor == destinationFloor)) {
		GetOff(e);
		return;
	}
}

void Rider::GetOn(Elevator* e) {
	s = Abroad;
	cout << "/nPassenger " << number << " enters elevator at floor" << e->CurrentFloor << endl;
	SelectFloor(e);
}

void Rider::GetOff(Elevator *e) {
	s = Served;
	cout << "/nPassenger " << number << " leaves elevator at floor" << e->CurrentFloor << endl;
}

void Rider::PushButton(Elevator *e, int thisFloor) {
	e->FloorButtons[thisFloor] = ON;
}

void Rider::SelectFloor(Elevator *e) {
	cout << "\Traveling to which floor(1-" << FLOORSINBLDG << ")?";
	cin >> destinationFloor;
	PushButton(e, destinationFloor);
}

#include <iostream>
#include "elevator.h"
using namespace std;

//first commit test

Elevator::Elevator() {
	CurrentFloor = 1;
	Going = UP;
	for (int i = 0; i < FLOORSINBLDG + 1; i++)
		FloorButtons[i] = OFF;
}

int Elevator::ButtonPushed() {
	for (int i = 0; i < FLOORSINBLDG + 1; i++)
		if (FloorButtons[i] == ON) return 1;
	return 0;
}

int Elevator::ChooseMove() {
	for (int t = 1; t <= 2; t++) {
		if (Going == UP) {
			for (int i = CurrentFloor; i < FLOORSINBLDG + 1; i++)
				if (FloorButtons[i] == ON) return i;
			Going = DOWN;
			continue;
		}
		else {
			for (int i = CurrentFloor; i > 0; i--)
				if (FloorButtons[i] == ON) return i;
			Going = UP;
			continue;
		}
	}
	return -1;
}

void Elevator::MoveToNextFloor() {
	int newFloor = ChooseMove();
	if (newFloor == -1)
		cout << "Elevator stopped at floor" << CurrentFloor;
	else {
		CurrentFloor = newFloor;
		FloorButtons[CurrentFloor] = OFF;
		DisplayStatus();
	}
}

void Elevator::DisplayStatus() {
	cout << "\nElevator is currently stopped at floor " << CurrentFloor << " heading ";
	if (Going == UP)
		cout << "up\n";
	else
		cout << "down\n";
	
	char check;
	cout << "Please key in any character to continue. ";
	cin >> check;
}

void main()
{
	Elevator e;
	e.DisplayStatus();

	e.FloorButtons[4] = ON;
	e.FloorButtons[7] = ON;
	
	e.MoveToNextFloor();

	e.FloorButtons[2] = ON;

	e.MoveToNextFloor();
	e.MoveToNextFloor();

	cout << "Complete";

}
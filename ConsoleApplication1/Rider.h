#include "Elevator.h"

enum Status { Waiting, Abroad, Served};

class Rider {
public:
	Rider(int num, Elevator* e, int start = 1);
	void GetOn(Elevator *e);
	void GetOff(Elevator *e);
	void PushButton(Elevator *e, int thisfloor);
	void SelectFloor(Elevator *e);
	void Respond(Elevator *e);
	Status s;

private:
	int startFloor;
	int destinationFloor;
	int number;
};


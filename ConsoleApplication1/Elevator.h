
enum Direction { DOWN, UP };
enum Button { OFF, ON };
const int FLOORSINBLDG = 10;

class Elevator{

public:
	Elevator();
	int ButtonPushed();
	void MoveToNextFloor();
	Button FloorButtons[FLOORSINBLDG + 1];
	int CurrentFloor;
	Direction Going;
	void DisplayStatus();

private:
	int ChooseMove();
	

};
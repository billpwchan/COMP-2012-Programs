const int MAX_ALTITUDE = 11000; 
const int MAX_SPEED = 960;

struct Airplane
{
    int altitude;       // in feet
    int speed;          // in km/h
};

void takeoff(Airplane& B747);
void descend(Airplane& B747, int feet);

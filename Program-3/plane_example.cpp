const int MAX_ALTITUDE = 11000; const int MAX_SPEED = 960;
const int MAX_RUNWAY_SPEED = 400; 
const int MIN_FLY_SPEED = 350;

struct Airplane { int altitude; int speed; };

void takeoff(Airplane& B747)
{
    // Initial state: speed == 0, altitude == 0
    B747.speed = (MAX_RUNWAY_SPEED + MIN_FLY_SPEED)/2;

    // Accelerate and climb to 1000 ft
    B747.altitude += 1000;
    B747.speed += 200;

    // Cruising speed and altitude
    B747.altitude = MAX_ALTITUDE;
    B747.speed = MAX_SPEED;
}

void descend(Airplane& B747, int feet);

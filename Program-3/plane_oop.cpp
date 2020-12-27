class Airplane 
{
  public:
    int set_speed(int new_speed);
    int set_altitude(int new_altitude);

  private:
    int altitude;
    int speed;
};

void some_function()
{
    Airplane B747;
    B747.set_speed(340);
    B747.set_altitude(1500);
    B747.speed = 3441873923; // Error: speed is private!
}


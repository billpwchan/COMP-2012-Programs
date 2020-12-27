class Airplane
{ 
  public:
    int get_speed() { return speed; }
    int get_altitude() { return altitude; }
    void set_speed(int x) { speed = x; }
    void set_altitude(int x) { altitude = x; }

  private:
    int speed;
    int altitude;
};

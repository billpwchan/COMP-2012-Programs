struct Airplane
{
    int altitude;
    int speed;

    // Flaps must be extended below a certain speed to
    // gain lift, but they must be retracted before the 
    // speed gets to high, otherwise they will be damaged.
    bool flaps_out;
};

void find_food(Bird *b) /* File: penguin-wrong.cpp */
{
    b->fly();           // Visibility decreases with altitude
    double visibility = 10.0 / b->altitude();
    ...
}

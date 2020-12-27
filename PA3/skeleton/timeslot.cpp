/*
 * Timeslot.cpp
 */

#include "timeslot.h"


// Initialize the static variable
string Timeslot::weekday_string[] = { "Mon", "Tue", "Wed", "Thu", "Fri" };

// Constructor
Timeslot::Timeslot(weekday d1, weekday d2, int stime, int etime)
	: day1(d1), day2(d2), start(stime), end(etime) { }

// Accessors
bool Timeslot::match(weekday day) const
{
	return (day == day1 || day == day2);
}


bool Timeslot::match(int stime, int etime) const
{
	return (start == stime && end == etime);
}



/* TODO
 * Convert the day in enum type to a printable string
 * using the static string weekday_string[5]
 */
string Timeslot::convert(weekday day) const
{
	return Timeslot::weekday_string[static_cast<int>(day)];
}

/* TODO
 * Please refer to the sample output for output format
 */
// Lecture time: Tue|Thu [10:00--12:00]  	Pre-Requisites: 2011 1942
ostream& operator<<(ostream& os, const Timeslot& time)
{
	cout << time.convert(time.day1) << "|" << time.convert(time.day2) << " [" << (time.start < 10 ? "0" : "") << time.start << ":00--" << (time.end < 10 ? "0" : "") << time.end << ":00]";
	return os;
}



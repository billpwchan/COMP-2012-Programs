//submit this file.
//you must use this exact file name.

#include "Timeslot.h"


Timeslot::Timeslot(int startTime, int endTime): startTime(startTime), endTime(endTime) {}

bool Timeslot::hasConflictsWith(const Timeslot& another) const {
	//cases: 3-5 4-6     4-6 3-5   3-7 4-5  4-5 3-7
	//Require further testing!!!!!!!
	if (this->getStartTime() <= another.getStartTime() && this->getEndTime() <= another.getEndTime() && this->getEndTime() > another.getEndTime()) {
		return true;
	}
	if (this->getStartTime() >= another.getStartTime() && this->getStartTime() < another.getEndTime() && this->getEndTime() > another.getEndTime()) {
		return true;
	}
	if (this->getStartTime() <= another.getStartTime() && this->getEndTime() >= another.getEndTime()) {
		return true;
	}
	if (this->getStartTime() >= another.getStartTime() && this->getEndTime() <= another.getEndTime()) {
		return true;
	}
	return false;
}

int Timeslot::getStartTime() const {
	return startTime;
}

int Timeslot::getEndTime() const {
	return endTime;
}


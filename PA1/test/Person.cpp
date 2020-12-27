//submit this file.
//you must use this exact file name.

#include "Person.h"

Person::Person(string name): name(name), activityCount(0), activities(NULL) {}

Person::~Person() {
	for (int i = 0; i < this->activityCount; i++) {
		delete this->activities[i];
	}
	delete [] activities;
}

string Person::getName() const {
	return name;
}


bool Person::addActivity(const Activity& activity) {
	for (int i = 0; i < this->activityCount; i++) {
		if (this->activities[i]->getName() == activity.getName())
			return false;
		if (this->activities[i]->getTimeslot().hasConflictsWith(activity.getTimeslot()))
			return false;
	}
	//Need to duplicate an activity object due to its const-ness
	Activity* newActivity = new Activity(activity.getName(), activity.getTimeslot());
	//When this is the first person to be added
	if (this->activityCount == 0 && activities == NULL) {
		activities = new Activity*[1];
		activities[0] = newActivity;
		activityCount += 1;
		return true;
	}
	//When the pointer is not NULL, find the exact position to be inserted
	int countPosition = 0;
	for (int i = 0; i < this->activityCount; i++) {
		if (activity.getTimeslot().getStartTime() < this->activities[i]->getTimeslot().getStartTime()) {
			countPosition = i;
			break;
		}
	}

	// This is for inserting in the end when the time is the latest
	Activity** new_activities = new Activity*[activityCount + 1];
	if (countPosition == 0 && activity.getTimeslot().getStartTime() > this->activities[0]->getTimeslot().getStartTime()) {
		for (int i = 0; i < activityCount; i++) {
			new_activities[i] = activities[i];
		}
		new_activities[activityCount] = newActivity;
	} else {
		// This is for inserting in the beginning or in the middle
		for (int i = 0; i < countPosition; i++) {
			new_activities[i] = activities[i];
		}
		new_activities[countPosition] = newActivity;
		for (int i = countPosition; i < activityCount; i++) {
			new_activities[i + 1] = activities[i];
		}
	}
	delete [] activities;
	activities = new_activities;
	activityCount += 1;

	return true;
}


bool Person::removeActivity(string activityName) {
	if (activities == NULL)
		return false;
	bool flag = false;
	int countPosition = 0;
	for (int i = 0; i < activityCount; i++) {
		if (activities[i]->getName() == activityName) {
			flag = true;
			countPosition = i;
		}
	}
	if (!flag)
		return flag;
	// For removing activities in the beginning, in the middle, in the end
	if ((activityCount - 1) == 0) {
		delete [] activities;
		activities = NULL;
	}
	Activity** new_activities = new Activity*[activityCount - 1];
	for (int i = 0; i < countPosition; i++) {
		new_activities[i] = activities[i];
	}
	for (int i = countPosition; i < activityCount - 1; i++) {
		new_activities[i] = activities[i + 1];
	}
	delete [] activities;
	activities = new_activities;
	activityCount -= 1;
	return flag;

}

bool Person::isFreeAtHour(int hour) const {
	for (int i = 0; i < activityCount; i++) {
		if (hour >= this->activities[i]->getTimeslot().getStartTime() && hour < this->activities[i]->getTimeslot().getEndTime()) {
			return false;
		}
	}
	return true;
}

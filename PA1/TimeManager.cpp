//submit this file.
//you must use this exact file name.

#include "TimeManager.h"


TimeManager::TimeManager(): persons(NULL), personCount(0) {}

TimeManager::~TimeManager() {
	for (int i = 0; i < this->personCount; i++) {
		delete this->persons[i];
	}
	delete [] persons;
}

bool TimeManager::addPerson(string name) {
	for (int i = 0; i < this->personCount; i++) {
		if (this->persons[i]->getName() == name)
			return false;
	}
	Person* NewPerson = new Person(name);
	if (personCount == 0 && persons == NULL) {
		persons = new Person*[1];
		persons[0] = NewPerson;
	} else {
		Person** new_Person_Array = new Person*[personCount + 1];
		for (int i = 0; i < personCount; i++) {
			new_Person_Array[i] = persons[i];
		}
		new_Person_Array[personCount] = NewPerson;
		delete [] persons;
		persons = new_Person_Array;
	}
	personCount += 1;
	return true;
}


bool TimeManager::addActivityForPerson(string personName, const Activity& activity) {
	if (persons == NULL)
		return false;
	bool flag = false;
	int countPosition = 0;
	for (int i = 0; i < this->personCount; i++) {
		if (this->persons[i]->getName() == personName) {
			flag = true;
			countPosition = i;
		}
	}
	// For considering the first case
	if (!flag)
		return false;
	// For considering the second case
	return this->persons[countPosition]->addActivity(activity);
}


bool TimeManager::removePerson(string name) {
	if (persons == NULL)
		return false;
	bool flag = false;
	int countPosition = 0;
	for (int i = 0; i < this->personCount; i++) {
		if (this->persons[i]->getName() == name) {
			flag = true;
			countPosition = i;
		}
	}
	if (!flag)
		return false;

	if ((personCount - 1) == 0) {
		delete [] persons;
		persons = NULL;
	}

	// For removing person in the beginning, in the middle, in the end
	Person** new_Person_Array = new Person*[personCount - 1];
	for (int i = 0; i < countPosition; i++) {
		new_Person_Array[i] = persons[i];
	}
	for (int i = countPosition; i < personCount - 1; i++) {
		new_Person_Array[i] = persons[i + 1];
	}
	delete [] persons;
	persons = new_Person_Array;
	personCount -= 1;
	return flag;

}


bool TimeManager::removeActivityForPerson(string personName, string activityName) {
	if (persons == NULL)
		return false;
	bool flag = false;
	int countPosition = 0;
	for (int i = 0; i < this->personCount; i++) {
		if (this->persons[i]->getName() == personName) {
			flag = true;
			countPosition = i;
		}
	}
	// For considering the first case
	if (!flag)
		return false;
	// For considering the second case
	return this->persons[countPosition]->removeActivity(activityName);
}


bool TimeManager::doesPersonExist(string name) const {
	for (int i = 0; i < this->personCount; i++) {
		if (this->persons[i]->getName() == name) {
			return true;
		}
	}
	return false;
}


Timeslot* TimeManager::findFirstCommonTimeslot() const {
	if (this->personCount == 0 && this->persons == NULL)
		return NULL;

	int startTime = 0, endTime = 0;
	bool flag = true;

	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < personCount; j++) {
			if (!this->persons[j]->isFreeAtHour(i)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			startTime = i;
			break;
		}
		flag = true;
	}

	//Need to identify whether startTime is free at 0 or startTime is not free for all
	if (!this->persons[0]->isFreeAtHour(0)) {
		//This is the end case
		return NULL;
	}
	endTime = startTime;
	flag = false;
	for (int i = startTime; i <= 24; i++) {
		for (int j = 0; j < personCount; j++) {
			if (!this->persons[j]->isFreeAtHour(i)) {
				flag = true;
				break;
			}
		}
		if (flag || i == 24) {
			endTime = i;
			break;
		}
		flag = false;
	}


	Timeslot* newTime = new Timeslot(startTime, endTime);
	return newTime;
}


void TimeManager::findAllCommonTimeslots(Timeslot**& results, int& timeslotCount) const {
	if (this->findFirstCommonTimeslot() == NULL) {
		results = NULL;
		timeslotCount = 0;
		return;
	}
	results = new Timeslot*[24];

	//To find common timeslot recursively
	int startTime = 0, endTime = 0, slotCount = 0;
	bool flag = true;

	while (startTime < 24) {
		flag = true;
		//Find a valid start time
		for (int i = startTime; i < 24; i++) {
			for (int j = 0; j < personCount; j++) {
				if (!this->persons[j]->isFreeAtHour(i)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				startTime = i;
				break;
			}
			flag = true;
		}


		//Need to identify whether startTime is free at 0 or startTime is not free for all
		if (!this->persons[0]->isFreeAtHour(startTime)) {
			//This is the end case
			break;
		}
		endTime = startTime;
		flag = false;

		for (int i = startTime; i <= 24; i++) {
			for (int j = 0; j < personCount; j++) {
				if (!this->persons[j]->isFreeAtHour(i)) {
					flag = true;
					break;
				}
			}
			if (flag || i == 24) {
				endTime = i;
				break;
			}
			flag = false;
		}
		Timeslot* newTime = new Timeslot(startTime, endTime);
		results[slotCount++] = newTime;
		if (endTime == 24) {
			break;
		}
		startTime = endTime;
		endTime = 0;
	}
	timeslotCount = slotCount;
}

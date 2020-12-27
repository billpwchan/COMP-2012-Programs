#include "StudentList.h"

//     StudentList(int num, string nameList[]);

//     bool findStudent(const string& name) const;
//     bool addStudent(const string& name);
//     bool deleteStudent(const string& name);

//     friend ostream& operator<<(ostream& os, const StudentList& studentList);

// private:
// list<string> nameList;


StudentList::StudentList(int num, string nameList[]) {
	for (int i = 0; i < num; i++) {
		this->nameList.push_back(nameList[i]);
	}
}

bool StudentList::findStudent(const string& name) const {
    list<string>::const_iterator findIter;
    for (findIter=nameList.begin();findIter!=nameList.end();findIter++){
        if (*findIter==name)
            return true;
    }
    
    return false;
}

bool StudentList::addStudent(const string& name) {
	if (this->findStudent(name)) {
		return false;
	}
	this->nameList.push_back(name);
	return true;
}

bool StudentList::deleteStudent(const string& name) {
	if (!this->findStudent(name)) {
		return false;
	}
	nameList.remove(name);
	return true;
}

ostream& operator<<(ostream& os, const StudentList& studentList) {
	cout << "[";
    list<string>::const_iterator findIter=studentList.nameList.begin();
    cout << *findIter;
    findIter++;
    for (; findIter!=studentList.nameList.end();findIter++){
        cout << ", "<<*findIter;
    }
	cout << "]" << endl;
    return os;
}

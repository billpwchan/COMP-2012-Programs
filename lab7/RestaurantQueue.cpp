#include "RestaurantQueue.h"

//  void serveStudent();
//     void addStudent(const string& name);
//     int waitNum() const;

// private:
//     queue<string> nameQueue;
    
void RestaurantQueue::serveStudent(){
    if (nameQueue.empty()){
        return;
    }
	cout << nameQueue.front() << " has been served."<<endl;
	nameQueue.pop();
}

void RestaurantQueue::addStudent(const string& name){
	cout << name << " is get into the queue."<<endl;
	nameQueue.push(name);
}

int RestaurantQueue::waitNum() const {
	return nameQueue.size();
}

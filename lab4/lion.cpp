#include "lion.h"
using namespace std;

Lion::Lion(int heartbeat, int max_heartbeat, int min_heartbeat, int weight, int num_of_legs, int speed)
:Animal(heartbeat, max_heartbeat, min_heartbeat, weight, num_of_legs), speed(speed){
	cout << "Lion is constructed. "<<endl;
}

Lion::~Lion(){cout << "this is the destructor of lion. "<<endl;}

void Lion::move(int time){
	cout << "this lion moved "<<time*this->speed<<" meters in "<<time << " seconds"<<endl;
}

void Lion::grow(int weight){
	Animal::grow(weight);
}

void Lion::print(){
	Animal::print();
}
#include "animal.h"
using namespace std;


Animal::Animal(int heartbeat, int max_heartbeat, int min_heartbeat, int weight, int num_of_legs):
	weight(weight), num_of_legs(num_of_legs), heart(heartbeat, max_heartbeat,  min_heartbeat) {
        cout << "Animal is constructed. "<<endl;
	}

Animal::~Animal() {cout << "This is the destructor of animal. "<<endl;}

void Animal::grow(int weight) {
	this->weight += weight;
	cout << "this animal growed for "<<weight<<" kg and its weight now is "<<this->weight<<" kg"<<endl;
}

void Animal::print() {
	cout << "hearbeat: " << this->heart.check_heartbeat() << " ";
	cout << "max_heartbeat: " << this->heart.get_max_heartbeat() << " ";
	cout << "min_heartbeat: " << this->heart.get_min_heartbeat() << " ";
	cout << "weight: " << this->weight << " ";
	cout << "num_of_legs: " << this->num_of_legs << endl;
}

int Animal::check_heartbeat() {
	return this->heart.check_heartbeat();
}

int Animal::get_max_heartbeat() {
	return this->heart.get_max_heartbeat();
}

int Animal::get_min_heartbeat() {
	return this->heart.get_min_heartbeat();
}

int Animal::get_weight() {
	return this->weight;
}

int Animal::get_legs() {
	return this->num_of_legs;
}

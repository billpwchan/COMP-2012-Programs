#include "corgi.h"

Corgi::Corgi(int heartbeat, int max_heartbeat, int min_heartbeat, int weight, int speed):Dog(heartbeat, max_heartbeat,min_heartbeat,weight,speed){
	cout << "Corgi is constructed"<<endl;
}

Corgi::~Corgi(){
	cout << "This is the destructor of Corgi. "<<endl;
}

void Corgi::print(){
    Dog::print();
}

void Corgi::move(int time){
    cout << "this corgi moved " << time*Dog::get_speed() << " meters in " << time << " seconds" << endl;
}

int Corgi::get_weight(){
	return Dog::get_weight();
}

int Corgi::get_speed(){
	return Dog::get_speed();
}

void Corgi::boost_heartbeat(){
	Dog::boost_heartbeat();
}

void Corgi::decrease_heartbeat(){
	Dog::decrease_heartbeat();
}

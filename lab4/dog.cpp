#include "dog.h"

Dog::Dog(int heartbeat, int max_heartbeat, int min_heartbeat, int weight, int speed):
    Heart(heartbeat, max_heartbeat, min_heartbeat), speed(speed), weight(weight) {
    cout << "Dog is constructed. " << endl;
}

Dog::~Dog() {
    cout << "this is the destructor of dog. " << endl;
}

void Dog::move(int time) {
    cout << "this dog moved " << time*this->speed << " meters in " << time << " seconds" << endl;
}

void Dog::print() {
    this->print_heart_info();
    cout << "weight: " << this->weight << " ";
    cout << "speed: " << this->speed << endl;
}

int Dog::check_heartbeat() {
    return Heart::check_heartbeat();
}

int Dog::get_max_heartbeat() {
    return Heart::get_max_heartbeat();
}

int Dog::get_min_heartbeat() {
    return Heart::get_min_heartbeat();
}

int Dog::get_weight() {
    return this->weight;
}

int Dog::get_speed() {
    return this->speed;
}

void Dog::boost_heartbeat() {
    Heart::boost_heartbeat();
}

void Dog::decrease_heartbeat() {
    Heart::decrease_heartbeat();
}

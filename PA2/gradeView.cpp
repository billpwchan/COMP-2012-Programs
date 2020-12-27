/*
 * View.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: kevinw
 */

#include "View.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;
const int MSG_X = 13;
const int MSG_Y = 6;
const int MSG_W = 4 * MSG_X;
const int MSG_H = MSG_Y;

const int COMM_X = 51;
const int COMM_Y = 2 * MSG_Y;
const int COMM_W = MSG_X * 5 - COMM_X;
const int COMM_H = MSG_Y * 3 - COMM_Y;

const int STAT_X = MSG_X;
const int STAT_Y = MSG_Y + MSG_H;
const int STAT_W = COMM_X - STAT_X;
const int STAT_H = COMM_H;

const int CELLS_X[] = { MSG_X * 5, MSG_X * 4, MSG_X * 3, MSG_X * 2, MSG_X, 0, 0, 0, 0, MSG_X , MSG_X * 2, MSG_X * 3 , MSG_X * 4, MSG_X * 5, MSG_X * 5 ,
		MSG_X * 5 };
const int CELLS_Y[] = { MSG_Y * 3, MSG_Y * 3, MSG_Y * 3, MSG_Y * 3 , MSG_Y * 3, MSG_Y * 3 , MSG_Y * 2, MSG_Y , 0, 0, 0, 0, 0, 0, MSG_Y , MSG_Y *2 };
const int CELL_H = MSG_Y;
const int CELL_W = MSG_X;

View::View() {
}

View::~View() {
}

void View::printCell(int index, const CellModel* cell,
		const PlayerModel* players[]) {
    return;
}

void View::appendMessage(string message) {
    //cout <<"View::appendMessage :" << message << endl;
    return;
}

int View::requestInput(string message, const string options[],
		int numOfOption) const {
    //cout <<"View::requestInput :" << message << endl;
    return 0;
}

void View::renderCommand(const string options[], int numOfOption,
		int selectedOption) const {
    return;
}

void View::displayPlayer(const PlayerModel* p) {
    return;
}

/*
 * mainForTodo.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: kevinw
 *
 */


#include "TodoBoard.h"
#include "TodoPlace.h"
#include "TodoRestaurant.h"
#include "TodoPlayer.h"
#include "TodoProperty.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

//You are not allowed to modify this file
//You are not required to submit this file

int __tc;
int __step;

const string MAP2_NAME[] = {
    "LT-A","LT-B","LT-C","LT-D",
    "LT-E","LT-F","LT-G","LT-H",
    "LT-I","LT-J","LT-K","LT-L",
    "LT-M","LT-N","LT-O","LT-P"
};

const int MAP2_PRICE[] = {
    1212,712,0,1192,1116,552,104,124,456,0,0,0,0,0,0,0
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
	cout << "Which test case you want to try? (1 to 21)" << endl
	    << "(Note: Test case 21 does not give you mark, you need to run the following on a linux terminal" << endl
	    << "valgrind --leak-check=full ./grade.out" << endl;
	cin >> __tc;
    } else {
        __tc = atoi(argv[1]);
    }
    __step = 0;
    BoardController* b = new TodoBoardController;
    b->init();

    b->run();
    delete b;

}

/**
 * Do not move this function to your TodoBoard.cpp. It is here for a reason.
 *
 * There are one constructor needed for each of the following classes. You can have
 * more as long as it compiles.
 *
 * TodoPlaceModel(string, COLOR); First parameter is the name of the cell, second parameter is the
 *      color of the cell.
 * TodoRestaurantModel(string, int, COLOR); First parameter is the name of the cell, second is the
 *      selling price, third is the color of the cell.
 * TodoPropertyModel(string, int, COLOR); First parameter is the name of the cell, second is the
 * 		selling price, third is the color of the cell.
 * TodoPlayerModel(string, int, COLOR); First parameter is the name of the player, second is the
 *      cash that the player to start with, third is the color of the player.
 *
 *
 */
void TodoBoardController::init() {
    long int u = 1 << (__tc - 1);
    //case 1 2 5 6 7 10 11 12 17 21
    if (u & 0b100010000111001110011) // use map1, supported in g++ 4 or c++14
	for (int i = 0; i < BOARD_SIZE; i++) {
	    if (i == 0)
		cells[i] = new TodoPlaceModel(PLACES[i], WHITE);
	    else if (i % 5 == 4)
		cells[i] = new TodoRestaurantModel(PLACES[i], 3000, GREEN);
	    else
		cells[i] = new TodoPropertyModel(PLACES[i], COSTS[i], WHITE);
	}
    else //use map 2
	for (int i = 0; i < BOARD_SIZE; i++) {
	    if (i == 9 || i == 12)
		cells[i] = new TodoPlaceModel(MAP2_NAME[i], RED);
	    else if (i == 1 || i == 5 || i == 6 )
		cells[i] = new TodoRestaurantModel(MAP2_NAME[i], MAP2_PRICE[i], RED);
	    else
		cells[i] = new TodoPropertyModel(MAP2_NAME[i], MAP2_PRICE[i], RED);
	}
    for (int i = 0; i < NUMBER_PLAYERS; i++)
	players[i] = new TodoPlayerModel(PLAYERS_NAME[i], START_CASH, PLAYERS_COLOR[i]);

}



/**
 *  during grading, you are expected this function will be replaced with other functions.
 */
int BoardController::rollDice() {
    double pts = 0;
    __step++;
    if (__tc == 1) {
	if (__step == 1) 
	    return 1;
	if (cells[1]->getColor() == GREEN)
	    pts += 0.75;
	if ((static_cast<PropertyModel*>(cells[1]))->getOwner() == players[0])
	    pts += 0.75;
	if (players[0]->getCash() == START_CASH - COSTS[1])
	    pts += 0.75;
	if (players[0]->getPropertyCount() == 1)
	    pts += 0.75;
	if ((players[0]->getProperties())[0] == cells[1])
	    pts += 0.75;
	
    } else if (__tc == 2) {
	switch (__step) {
	case 1: return 1;
	case 2: case 3: return 2;
	case 4: return 3;
	} 
	if (cells[1]->getColor() == GREEN && cells[4]->getColor() == GREEN)
	    pts += 0.75;
	if ((static_cast<PropertyModel*>(cells[1]))->getOwner() == players[0] 
	   && (static_cast<PropertyModel*>(cells[4]))->getOwner() == players[0] )
	    pts += 0.75;
	if (players[0]->getCash() == START_CASH - COSTS[1] - COSTS[4])
	    pts += 0.75;
	if (players[0]->getPropertyCount() == 2)
	    pts += 0.75;
	if (((players[0]->getProperties())[0] == cells[1] && (players[0]->getProperties())[1] == cells[4])
	 || ((players[0]->getProperties())[0] == cells[4] && (players[0]->getProperties())[1] == cells[1]))
	    pts += 0.75;
	
    } else if (__tc == 3) {
	if (__step == 1)
	    return 4;
	if (cells[4]->getColor() == GREEN)
	    pts += 0.75;
	if ((static_cast<PropertyModel*>(cells[4]))->getOwner() == players[0])
	    pts += 0.75;
	if (players[0]->getCash() == START_CASH - MAP2_PRICE[4])
	    pts += 0.75;
	if (players[0]->getPropertyCount() == 1)
	    pts += 0.75;
	if ((players[0]->getProperties())[0] == cells[4])
	    pts += 0.75;
	
    } else if (__tc == 4) {
	switch (__step) {
	case 1: return 4;
	case 2: case 3: return 2;
	case 4: return 1;
	} 
	if (cells[4]->getColor() == GREEN && cells[5]->getColor() == GREEN)
	    pts += 0.75;
	if ((static_cast<PropertyModel*>(cells[4]))->getOwner() == players[0] 
	   && (static_cast<PropertyModel*>(cells[5]))->getOwner() == players[0] )
	    pts += 0.75;
	if (players[0]->getCash() == START_CASH - MAP2_PRICE[4] - MAP2_PRICE[5])
	    pts += 0.75;
	if (players[0]->getPropertyCount() == 2)
	    pts += 0.75;
	if (((players[0]->getProperties())[0] == cells[4] && (players[0]->getProperties())[1] == cells[5])
	 || ((players[0]->getProperties())[0] == cells[5] && (players[0]->getProperties())[1] == cells[4]))
	    pts += 0.75;
    } else if (__tc == 5) {
	switch (__step) {
	case 1: return 2;
	case 2: case 3: return 3;
	case 4: return 15;
	case 5: case 6: return 4;
	case 7: ta_grading_variable = players[0]->getCash(); return 1;
	} 
	if (players[0]->getCash() == ta_grading_variable - BUILDING_COST)
	    pts += 1.25;
	if ((static_cast<PropertyModel*>(cells[2]))->getHousesCount() == 1)
	    pts += 1.25;
    } else if (__tc == 6) {
	switch (__step) {
	case 1: return 2;
	case 2: case 3: return 3;
	case 4: return 15;
	case 5: case 6: return 4;
	case 7: return 1;
	case 8: return 1;
	case 9: return 2;
	case 10: return 15;
	case 11: case 12: return 2;
	case 13: ta_grading_variable = players[0]->getCash(); return 1;
	} 
	if (players[0]->getCash() == ta_grading_variable - BUILDING_COST)
	    pts += 1.25;
	if ((static_cast<PropertyModel*>(cells[2]))->getHousesCount() == 2)
	    pts += 1.25;
    } else if (__tc == 7) {
	switch (__step) {
	case 1: return 3;
	case 2: return 1;
	case 3: return 2;
	case 4: case 5: return 3;
	case 6: ta_grading_array[0] = players[0]->getCash(); ta_grading_array[1] = players[2]->getCash(); return 1;
	}
	if ((players[0]->getCash() == ta_grading_array[0] + 1500) &&
	    (players[2]->getCash() == ta_grading_array[1] - 1500))
	    pts += 2;
	if ((static_cast<PropertyModel*>(cells[3]))->getRate() == 1500)
	    pts += 1.75;
    } else if (__tc == 8) {
	switch (__step) {
	case 1: return 7;
	case 2: return 3;
	case 3: case 4: return 3;
	case 5: return 5;
	case 6: ta_grading_array[0] = players[0]->getCash(); ta_grading_array[1] = players[2]->getCash(); return 4;
	}
	if ((players[0]->getCash() == ta_grading_array[0] + 93) &&
	    (players[2]->getCash() == ta_grading_array[1] - 93))
	    pts += 2;
	if ((static_cast<PropertyModel*>(cells[7]))->getRate() == 93)
	    pts += 1.75;
	
    } else if (__tc == 9) {
	switch (__step) {
	case 1: return 3;
	case 2: return 1;
	case 3: return 2;
	case 4: return 3;
	case 5: return 3;
	case 6: ta_grading_array[0] = players[0]->getCash(); ta_grading_array[1] = players[2]->getCash(); return 1;
	}
	if ((players[0]->getCash() == ta_grading_array[0] + 894) &&
	    (players[2]->getCash() == ta_grading_array[1] - 894))
	    pts += 2;
	if ((static_cast<PropertyModel*>(cells[3]))->getRate() == 894)
	    pts += 1.75;
    } else if (__tc == 10) {
	switch (__step) {
	case 1: return 2;
	case 2: case 3: return 1;
	case 4: return 13;
	case 5: return 4;
	case 6: return 15;
	case 7: return 3;
	case 8:  case 9: case 10: case 11: return 1;
	case 12: ta_grading_array[0] = players[0]->getCash(); ta_grading_array[1] = players[2]->getCash(); return 1;
	}
	if ((players[0]->getCash() == ta_grading_array[0] + 3000) &&
	    (players[2]->getCash() == ta_grading_array[1] - 3000))
	    pts += 2;
	if ((static_cast<PropertyModel*>(cells[2]))->getRate() == 3000)
	    pts += 1.75;
    } else if (__tc == 11) {
	switch (__step) {
	case 1: return 4;
	case 2: return 1;
	case 3: return 2;
	case 4: return 1;
	case 5: return 2;
	case 6: ta_grading_array[0] = players[0]->getCash(); ta_grading_array[1] = players[2]->getCash(); return 2;
	}
	if ((players[0]->getCash() == ta_grading_array[0] + 3000) &&
	    (players[2]->getCash() == ta_grading_array[1] - 3000))
	    pts += 1.25;
	if ((static_cast<PropertyModel*>(cells[4]))->getRate() == 3000)
	    pts += 1.25;
    } else if (__tc == 12) {
	switch (__step) {
	case 1: return 4;
	case 2: return 1;
	case 3: return 2;
	case 4: return 5;
	case 5: return 2;
	case 6: ta_grading_array[0] = players[0]->getCash(); ta_grading_array[1] = players[2]->getCash(); return 2;
	}
	if ((players[0]->getCash() == ta_grading_array[0] + 6000) &&
	    (players[2]->getCash() == ta_grading_array[1] - 6000))
	    pts += 1.25;
	if ((static_cast<PropertyModel*>(cells[4]))->getRate() == 6000)
	    pts += 1.25;
    } else if (__tc == 13) {
	switch (__step) {
	case 1: return 6;
	case 2: return 2;
	case 3: return 3;
	case 4: return 1;
	case 5: return 2;
	case 6: ta_grading_array[0] = players[0]->getCash(); ta_grading_array[1] = players[2]->getCash(); return 3;
	}
	if ((players[0]->getCash() == ta_grading_array[0] + 104) &&
	    (players[2]->getCash() == ta_grading_array[1] - 104))
	    pts += 1.25;
	if ((static_cast<PropertyModel*>(cells[6]))->getRate() == 104)
	    pts += 1.25;
    } else if (__tc == 14) {
	switch (__step) {
	case 1: return 1;
	case 2: return 2;
	case 3: return 3;
	case 4: return 5;
	case 5: return 10;
	case 6: case 7: case 8: return 1;
	case 9: ta_grading_array[0] = players[0]->getCash(); ta_grading_array[1] = players[2]->getCash(); return 2;
	}
	if ((players[0]->getCash() == ta_grading_array[0] + 208) &&
	    (players[2]->getCash() == ta_grading_array[1] - 208))
	    pts += 1.25;
	if ((static_cast<PropertyModel*>(cells[6]))->getRate() == 208)
	    pts += 1.25;
    } else if (__tc == 15) {
	switch (__step) {
	case 1: return 2;
	case 2: return 2;
	}
	if ((players[0]->getCash() == START_CASH - ROB_CASH ) &&
	    (players[1]->getCash() == START_CASH + ROB_CASH))
	    pts += 2.5;
    } else if (__tc == 16) {
	switch (__step) {
	case 1: return 2;
	case 2: return 2;
	case 3: return 2;
	}
	if ((players[0]->getCash() == START_CASH - 2 * ROB_CASH ) &&
	    (players[1]->getCash() == START_CASH) &&
	    (players[2]->getCash() == START_CASH + 2 * ROB_CASH ))
	    pts += 7.5;
    } else if (__tc == 17) {
	switch (__step) {
	case 1: return 8;
	case 2: case 3: return 2;
	case 4: ta_grading_variable = players[0]->getCash(); return 8;
	}
	if (players[0]->getCash() == ta_grading_variable + PLACE_CASH ) 
	    pts += 2.5;
    } else if (__tc == 18) {
	switch (__step) {
	case 1: return 9;
	case 2: case 3: case 4: return 1;
	}
	if (players[0]->getCash() == START_CASH + PLACE_CASH ) 
	    pts += 2.5;
    } else if (__tc == 19) {
	switch (__step) {
	case 1: return 10;
	}
	if (players[0]->getCash() == START_CASH + PLACE_CASH ) 
	    pts += 2.5;
    } else if (__tc == 20) {
	switch (__step) {
	case 1: return 10;
	case 2: case 3: case 4: return 3;
	case 5: if (players[0]->getCash() != START_CASH + 2*PLACE_CASH) {
		    cout << pts << endl;
		    exit(1);
		}
		return 5;
	case 6: case 7: return 5;
	}
	if (players[0]->getCash() == START_CASH + 2*PLACE_CASH ) 
	    pts += 2.5;
    } else { //case 21
	return __step % 2 + 1;
    }
    cout << pts << endl;
    exit(1);
}



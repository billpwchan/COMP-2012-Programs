/*
 * This should contain the implementation of the class of TodoBoard.
 */

//You need to submit this file
//You need to modify this file

#include "TodoBoard.h"
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

TodoBoardController::TodoBoardController(){}
TodoBoardController::~TodoBoardController(){
    //Inheritance. No need to implement this part
}

void TodoBoardController::run(){
	int turn = 0;
	while (!checkBankrupt()) {
		//Print Board
		printBoard();
		//Row dice
		int x = rollDice();
		PlayerModel* thisTurnPlayer = players[turn];
		int y = thisTurnPlayer->getPosition();
		stringstream s;
		s << thisTurnPlayer->getName() << ", it is your turn." << endl;
		view.appendMessage(s.str());
		view.displayPlayer(thisTurnPlayer);
		thisTurnPlayer->move(x);
		printBoard();
        //Test how many time passes
        
        for (int i=0;i<=x;i++){
            if (dynamic_cast<const TodoPlaceModel*>(cells[(y+i)%BOARD_SIZE])!=NULL){
                cells[(y+i)%BOARD_SIZE]->action(thisTurnPlayer, *this);
//                this->prompt("SUCCESS COLLECTING");
//                thisTurnPlayer->collect(PLACE_CASH);
            }
        }
        if (dynamic_cast<const TodoPlaceModel*>(cells[y])!=NULL){
            thisTurnPlayer->pay(PLACE_CASH);
        }
        
		//Move and Trigger Event
		cells[thisTurnPlayer->getPosition()]->action(thisTurnPlayer, *this);
		//Will consider the rob case.!!!
		for (int i=0;i<NUMBER_PLAYERS;i++){
			if (players[i]->getPosition()==thisTurnPlayer->getPosition()&&i!=turn){
				thisTurnPlayer->collect(ROB_CASH);
				players[i]->pay(ROB_CASH);
                this->prompt(thisTurnPlayer->getName()+ " rob "+players[i]->getName());
			}
		}
        view.displayPlayer(thisTurnPlayer);
        this->prompt(thisTurnPlayer->getName()+": this round complete.");
		//Next player
		turn = (turn + 1) % NUMBER_PLAYERS;
	}
	prompt("End of Game");
}

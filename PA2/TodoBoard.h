/*
 * This should contain the class of TodoBoardController.
 */

//You need to submit this file
//You need to modify this file


#ifndef TODOBOARDCONTROLLER_H_
#define TODOBOARDCONTROLLER_H_
//your code goes here
//
#include "Board.h"
#include "TodoPlace.h"

class TodoBoardController: public BoardController{
public:
	TodoBoardController();
	virtual ~TodoBoardController();
	virtual void run();
	virtual void init();
};

#endif /* TODOBOARDCONTROLLER_H_ */

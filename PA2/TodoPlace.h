/*
 * This should contain the class of TodoPlaceModel.
 */

//You need to submit this file
//You need to modify this file

//your code goes here
#ifndef TODOPLACE_H_
#define TODOPLACE_H_

#include "Cell.h"
#include "param.h"

class PlayerModel;

class TodoPlaceModel: public CellModel{
public:
	TodoPlaceModel(string name, Color color);
	virtual ~TodoPlaceModel();
	virtual void action(PlayerModel* player, const BoardController &board);
};

#endif /* TODOPLACE_H_ */

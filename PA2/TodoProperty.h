/*
 * This should contain the class of TodoPropertyModel.
 */

//You need to submit this file
//You need to modify this file


#ifndef TODOPROPERTY_H_
#define TODOPROPERTY_H_

#include "Property.h"

class PlayerModel;

class TodoPropertyModel:public PropertyModel{
public:
	TodoPropertyModel(string name, int price, Color color) : PropertyModel(name, price, color) {}
    virtual ~TodoPropertyModel(){}
	virtual void action(PlayerModel *player, const BoardController &board);
	virtual int getRate() const;
};

#endif /* TODOPROPERTY_H_ */

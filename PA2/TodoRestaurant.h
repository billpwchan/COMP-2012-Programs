/*
 * This should contain the class of TodoRestaurantModel.
 */

//You need to submit this file
//You need to modify this file

#ifndef TODORESTAURANTMODEL_H_
#define TODORESTAURANTMODEL_H_

#include "Property.h"

class PlayerModel;

class TodoRestaurantModel: public PropertyModel {
public:
	TodoRestaurantModel(string name, int price, Color color):PropertyModel(name, price, color){}
    virtual ~TodoRestaurantModel(){}
	virtual int getRate() const;
	virtual void action(PlayerModel *player, const BoardController &board);
};

#endif /* TODORESTAURANTMODEL_H_ */

/*
 * This should contain the class of TodoPlayerModel.
 */

//You need to submit this file
//You need to modify this file

#ifndef TODOPLAYER_H_
#define TODOPLAYER_H_

#include "Player.h"

class PropertyModel;

class TodoPlayerModel:public PlayerModel {
public:
	TodoPlayerModel(string name, int cash, Color color);
    virtual ~TodoPlayerModel();
	virtual void gainProperty(PropertyModel* pm);
	virtual bool isOwning(PropertyModel* pm) const;
};
#endif /* TODOPLAYER_H_ */

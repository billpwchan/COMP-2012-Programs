/*
 * This should contain the implementation of the class of TodoPlayerModel.
 */

//You need to submit this file
//You need to modify this file


#include "TodoPlayer.h"
TodoPlayerModel::TodoPlayerModel(string name, int cash, Color color):PlayerModel(name, cash, color){}

TodoPlayerModel::~TodoPlayerModel(){}

  /**
     * The player gains a property which is modeled by the class PropertyModel.
     *
     * @param pm: The property that the player is gaining. But in this demo program it does nothing.
     */
void TodoPlayerModel::gainProperty(PropertyModel* pm) {
 	PropertyModel** temp = new PropertyModel* [this->propertyCount+1];
 	for (int i=0;i<this->propertyCount;i++){
 		temp[i]=this->properties[i];
 	} 
 	temp[propertyCount++]=pm;
    delete [] this->properties;
 	this->properties=temp;
}
    /**
     * To check if a property is owned by a player.
     *
     * @param pm: Check the property pm is owned by a player. But in this demo it always says false.
     * @return: True if the property is owned by the player. But in this demo it always return  false.
     *
     */
bool TodoPlayerModel::isOwning(PropertyModel* pm) const {
	if (pm->getOwner()==this)
		return true;
	return false;
};





/*
 * This should contain the implementation of the class of TodoPlaceModel.
 */

//You need to submit this file
//You need to modify this file


#include "TodoPlace.h"
#include "TodoPlayer.h"

TodoPlaceModel::TodoPlaceModel(string name, Color color):CellModel(name, color){}
TodoPlaceModel::~TodoPlaceModel(){}
void TodoPlaceModel::action(PlayerModel* player, const BoardController & board){
    player->collect(PLACE_CASH);
}
//your code goes here

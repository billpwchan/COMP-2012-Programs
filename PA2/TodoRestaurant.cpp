/*
 * This should contain the implementation of TodoRestaurantModel.
 */

//You need to submit this file
//You need to modify this file

//your code goes here

#include "TodoRestaurant.h"
#include "Player.h"
#include "Board.h"
#include <sstream>

	void TodoRestaurantModel::action(PlayerModel *player, const BoardController &board){
        if (this->owner==NULL){
            int option;
            stringstream s;
            s << "Do you want to buy " << name << "?";
            const string options[2] = {"Yes" , "No"};
            
            option = board.requestInput(s.str(), options, 2);
            if (option == 0) {
                if (player->getCash() >= this->price) {
                    // First case, has enough money
                    // !!!!MAYBE PRINTOUT SOMETHING
                    board.prompt(player->getName()+" bought "+ this->name);
                    player->gainProperty(this);
                    player->pay(price);
                    this->owner = player;
                    this->color = player->getColor();
                }
            }
        }else{
            if (this->owner!=player){
                player->pay(this->getRate());
            }
        }
        
	}

	int TodoRestaurantModel::getRate() const{
		//Need to know whether the owner have how many number of restaurants. Can use getProperties which returns
		//a list of properties.
        if (this->owner==NULL)
            return this->price;
        
        int count=0;
        //The following part is for determining how many restaurants owner exists.
        for (int i=0;i<this->owner->getPropertyCount();i++){
            if (dynamic_cast<const TodoRestaurantModel*>(this->owner->getProperties()[i])!=NULL){
                count++;
            }
        }
        return this->price*count;

		return 0;
	}

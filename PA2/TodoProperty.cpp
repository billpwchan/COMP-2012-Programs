/*
 * This should contain the implementation of TodoPropertyModel.
 */

//You need to submit this file
//You need to modify this file

#include "TodoProperty.h"
#include "Player.h"
#include "Board.h"
#include <sstream>


// * The abstract function implemented in this class. When a player steps on it, he can buy it if
// * it is not previously owned. He need to pay for the rent if it is owned by other player. He can build
// * a house if he owned this property before this function is invoked. When there are five houses on
// * this property, no more house can be built.
void TodoPropertyModel::action(PlayerModel *player, const BoardController &board) {
	if (owner == NULL) {
		// If this place hasn't be owned
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
                //Testing Only!!
//                for (int i=0;i<this->owner->getPropertyCount();i++){
//                    board.prompt(this->owner->getProperties()[i]->getName());
//                }
			}
		}
	} else {
		if (this->owner == player) {
			if (this->houses < MAX_HOUSES && player->getCash() >= BUILDING_COST) {
				//Will pay the build_cost
				player->pay(BUILDING_COST);
				this->houses += 1;
			}
//            board.prompt("current house number is "+std::to_string(this->getHousesCount()));
            
            //Testing Only!!
//            for (int i=0;i<this->owner->getPropertyCount();i++){
//                board.prompt(this->owner->getProperties()[i]->getName());
//            }
		} else {
			//Will pay the fee
			int rent = this->price * (this->houses + 1) * 3 / 4;
			this->owner->collect(rent);
			player->pay(rent);
            board.prompt(player->getName()+" pays "+this->owner->getName()+" $"+std::to_string(rent));
		}
	}
    board.prompt("The number of houses is: "+std::to_string(this->houses));
}

int TodoPropertyModel::getRate() const {
	if (owner == NULL)
		return price;
	return price * ( houses + 1)  * 3 / 4;
}

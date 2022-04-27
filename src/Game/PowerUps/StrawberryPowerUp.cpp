#include "StrawberryPowerUp.h"

StrawberryPU::StrawberryPU(){

    isActive = false;

}

void StrawberryPU::activate(){

    isActive = !isActive;

}

bool StrawberryPU::getPassive(){


    if(isActive){
        Invincible = true;
    }
    else{
        Invincible = false;
    }

   return Invincible;


}
/*
void StrawberryPU::tick(){
    if(Invincible){
        InvincibleCounter--;
        if (InvincibleCounter == 0){
            Invincible = false;
            for(Entity* player){
                player->setPassive(false);
            }
        }
    }
}


void StrawberryPU::setPassive(bool I){
    Invincible = true;
    InvincibleCounter=10*ofGetFrameRate();
    for(Entity* entity:player){
        Player* player = dynamic_cast<Player*>(entity); 
        player->setPassive(true);
    }
}
*/
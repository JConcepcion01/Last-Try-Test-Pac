#include "DebuggPowerUp.h"

DebuggPowerUp::DebuggPowerUp(){

    isActive = false;
    speed = 4;

}
void DebuggPowerUp::activate(){

    isActive = !isActive;

}

int DebuggPowerUp::getSpeed(){

    if(isActive){
        speed = 8;
    }
    else{
        speed = 4;
    }

   return speed;
}
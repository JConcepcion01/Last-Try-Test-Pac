#pragma once

#include "Animation.h"
#include "EntityManager.h"
#include "ChoosePlayerState.h"

enum MsMOVING {
	MsUP,
	MsDOWN,
	MsLEFT,
	MsRIGHT,
};
class MsPlayer: public Entity{

    private:
        int spawnX, spawnY;
        unsigned int health=3;
        int Msscore=0;
        bool canMoveUp, canMoveDown, canMoveRight, canMoveLeft;
        int speed = 4;
        bool walking = false;
        MsMOVING moving;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        PlayerSelectState *loadImg;

    public:
        MsPlayer(int, int, int , int, EntityManager*);
        ~MsPlayer();
        int getHealth();
        int getMsScore();
        FACING getFacing();
        void setHealth(int);
        void setMsScore(int);
        void setFacing(FACING facing);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void checkCollisions();
        void die();
        int getDots();

};
#include "MsPlayer.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"

MsPlayer::MsPlayer(int x, int y, int width, int height, EntityManager* em) : Entity(x, y, width, height){
    spawnX = x;
    spawnY = y;
    sprite.load("images/MsPacman.png");
    down.cropFrom(sprite, 0, 48, 16, 16);
    up.cropFrom(sprite, 0, 32, 16, 16);
    left.cropFrom(sprite, 0, 16, 16, 16);
    right.cropFrom(sprite, 0, 0, 16, 16);
    
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 48, 16, 16);
        downAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 32, 16, 16);
        upAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 16, 16, 16);
        leftAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);

    this->em = em;

    moving = MsLEFT;
    
}
void MsPlayer::tick(){

    checkCollisions();

    if (moving == MsUP && canMoveUp) 
        facing = UP;
    else if (moving == MsDOWN && canMoveDown) 
        facing = DOWN;
    else if (moving == MsLEFT && canMoveLeft) 
        facing = LEFT;
    else if (moving == MsRIGHT && canMoveRight)
        facing = RIGHT;

    if(facing == UP && canMoveUp){
        y-= speed;
        walkUp->tick();
    }else if(facing == DOWN && canMoveDown){
        y+=speed;
        walkDown->tick();
    }else if(facing == LEFT && canMoveLeft){
        x-=speed;
        walkLeft->tick();
    }else if(facing == RIGHT && canMoveRight){
        x+=speed;
        walkRight->tick();
    }
}

void MsPlayer::render(){
    ofSetColor(256,256,256);
    // ofDrawRectangle(getBounds());

    if(facing == UP)
        walkUp->getCurrentFrame().draw(x, y, width, height);
    else if(facing == DOWN)
        walkDown->getCurrentFrame().draw(x, y, width, height);
    else if(facing == LEFT)
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    else if(facing == RIGHT)
        walkRight->getCurrentFrame().draw(x, y, width, height);
    
    ofSetColor(102, 255, 255);
    ofDrawBitmapString("Health: ", ofGetWidth()/2 + 100, 50);

    for(unsigned int i=0; i<health; i++){
        ofDrawCircle(ofGetWidth()/2 + 25*i +200, 50, 10);
    }
    ofDrawBitmapString("Score:"  + to_string(Msscore), ofGetWidth()/2-200, 50);
}

void MsPlayer::keyPressed(int key){
    switch(key){
        case 'w':
            moving = MsUP;
            break;
        case 's':
            moving = MsDOWN;
            break;
        case 'a':
            moving = MsLEFT;;
            break;
        case 'd':
            moving = MsRIGHT;;
            break;
        case 'n':
            die();
            break;
        case 'm':
            if (MsPlayer::getHealth() < 3){
             health++;
            }
            break;
        case 'y':
            for (Entity *entity : em->entities){
                if (dynamic_cast<Dot *>(entity) || dynamic_cast<BigDot *>(entity)){
                    entity->remove = true;
                }
            }
        case ' ':
            em->setKillable(true);
            break;
    }
}

void MsPlayer::keyReleased(int key){
    if(key == 'w' || key =='s' || key == 'a' || key == 'd'){
        walking = false;
    }
}
void MsPlayer::mousePressed(int x, int y, int button){

}

int MsPlayer::getHealth(){ return health; }
int MsPlayer::getMsScore(){ return Msscore; }
FACING MsPlayer::getFacing(){ return facing; }
void MsPlayer::setHealth(int h){ health = h; }
void MsPlayer::setFacing(FACING facing){ this->facing = facing; }
void MsPlayer::setMsScore(int h){ Msscore = h; }

void MsPlayer::checkCollisions(){
    canMoveUp = true;
    canMoveDown = true;
    canMoveLeft = true;
    canMoveRight = true;

    for(BoundBlock* boundBlock: em->boundBlocks){
        if(this->getBounds(x, y-speed).intersects(boundBlock->getBounds()))
            canMoveUp = false;
        if(this->getBounds(x, y+speed).intersects(boundBlock->getBounds()))
            canMoveDown = false;
        if(this->getBounds(x-speed, y).intersects(boundBlock->getBounds()))
            canMoveLeft = false;
        if(this->getBounds(x+speed, y).intersects(boundBlock->getBounds()))
            canMoveRight = false;
    }
    for(Entity* entity:em->entities){
        if(collides(entity)){
            if(dynamic_cast<Dot*>(entity) || dynamic_cast<BigDot*>(entity)){
                entity->remove = true;
                Msscore += 10;
            }
            if(dynamic_cast<BigDot*>(entity)){
                Msscore +=20;
                em->setKillable(true);
            }
        }
    }
    for(Entity* entity:em->ghosts){
        if(collides(entity)){
            Ghost* ghost = dynamic_cast<Ghost*>(entity);
            if(ghost->getKillable())
                ghost->remove = true;
            else
                die();
        }
    }

    
}

void MsPlayer::die(){
    health--;
    x = spawnX;
    y = spawnY;

}

MsPlayer::~MsPlayer(){
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
}

int MsPlayer::getDots(){

    int numdots;
    for (Entity *d : em->entities){
        if (dynamic_cast<Dot *>(d) || dynamic_cast<BigDot *>(d))
        {
            numdots++;
        }
    }
    return numdots;
}
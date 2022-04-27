#include "Random.h"

RandomPU::RandomPU(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet,550,49, 16, 16);
}

// sprite.cropFrom(spriteSheet,600,49, 16, 16); --Key Sprite
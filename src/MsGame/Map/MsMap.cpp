#include "MsMap.h"

MsMap::MsMap(EntityManager* em){
    entityManager = em;
}

void MsMap::tick(){
	entityManager->tick();
	player->tick();
	gs->tick();

}
void MsMap::render(){
    ofSetBackgroundColor(0, 0, 0);
	entityManager->render();
	player->render();

}

void MsMap::keyPressed(int key){
	player->keyPressed(key);
	gs->keyPressed(key);

}

void MsMap::mousePressed(int x, int y, int button){
	player->mousePressed(x, y, button);
}

void MsMap::keyReleased(int key){
	player->keyReleased(key);
}
void MsMap::addBoundBlock(BoundBlock* e){
    entityManager->boundBlocks.push_back(e);
}
void MsMap::addEntity(Entity* e){
	entityManager->entities.push_back(e);
}
void MsMap::setPlayer(MsPlayer* p){
    player = p;
}

MsPlayer* MsMap::getPlayer(){
	return player;
}
void MsMap::setGhostSpawner(GhostSpawner* p){
    gs = p;
}

MsMap::~MsMap(){
	delete player;
	delete entityManager;
	delete gs;
}
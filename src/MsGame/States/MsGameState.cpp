#include "MsGameState.h"
#include "Entity.h"

MsGameState::MsGameState() {
	music.load("music/MsPacManMatch.mp3");
	mapImage.load("images/map1.png");
	map = MsMapBuilder().createMap(mapImage);
}
void MsGameState::tick() {
	map->tick();
	if(map->getPlayer()->getHealth() == 0){
		setFinished(true);
		setNextState("MsOver");
		map->getPlayer()->setHealth(3);
		finalMsScore = map->getPlayer()->getMsScore();
		map->getPlayer()->setMsScore(0);
		MsGameState(); {
		music.load("music/MsPacManMatch.mp3");
		mapImage.load("images/map1.png");
		map = MsMapBuilder().createMap(mapImage);
		}
	}

	// First Win State Mode (Not Used)
	if(map->getPlayer()->getDots() == 0){
		setFinished(true);
		setNextState("Win");
		mapImage.load("images/map1.png");
		map = MsMapBuilder().createMap(mapImage);
	}
	

}
void MsGameState::render() {
	map->render();
}

void MsGameState::keyPressed(int key){
	map->keyPressed(key);
	if (key == 'p'){
		setFinished(true);
		music.setPaused(true);
		setNextState("MsPause");
	}
	else if (key == 'y'){
		setFinished(true);
		music.setPaused(true);
		setNextState("Win");
		mapImage.load("images/map1.png");
		map = MsMapBuilder().createMap(mapImage);
		
	}
}

void MsGameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void MsGameState::keyReleased(int key){
	map->keyReleased(key);
}

void MsGameState::reset(){
	music.setPaused(false);
	setFinished(false);
	setNextState("");
}

int MsGameState::getFinalMsScore(){
	return finalMsScore;
}

MsGameState::~MsGameState(){
	delete map;
}
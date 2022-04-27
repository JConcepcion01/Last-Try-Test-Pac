#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);
}
void GameState::tick() {
	if(!music.isPlaying()){
			music.play();
	}
	map->tick();
	if(map->getPlayer()->getHealth() == 0){
		setFinished(true);
		setNextState("Over");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
		GameState(); {
		mapImage.load("images/map1.png");
		map = MapBuilder().createMap(mapImage);
		}
	}

	// First Win State Mode (Not Used)
	if(map->getPlayer()->getDots() == 0){
		setFinished(true);
		setNextState("Win");
		mapImage.load("images/map1.png");
		map = MapBuilder().createMap(mapImage);
	}
	

}
void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
	if (key == 'p'){
		setFinished(true);
		setNextState("Pause");
	}
	else if (key == 'y'){
		setFinished(true);
		setNextState("Win");
		mapImage.load("images/map1.png");
		map = MapBuilder().createMap(mapImage);
		
	}
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	music.setPaused(false);
	setFinished(false);
	setNextState("");
}

int GameState::getFinalScore(){
	return finalScore;
}

GameState::~GameState(){
	delete map;
}
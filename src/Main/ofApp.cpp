#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofSetWindowTitle("Pac-Man++");
	//States
	menuState = new MenuState();
	msMenuState = new MsMenuState();
	playerSelectState = new PlayerSelectState();
	gameState = new GameState();
	gameOverState = new GameOverState();
	msGameOverState = new MsGameOverState();
	winState = new WinState();
	pauseState = new PauseState();
	msGameState = new MsGameState();
	msPauseState = new MsPauseState();
	// Initial State
	currentState = playerSelectState;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				currentState = menuState;
			}else if(currentState->getNextState() == "MsMenu"){
				currentState = msMenuState;
			}else if(currentState->getNextState() == "Select"){
				currentState = playerSelectState;
			}else if(currentState->getNextState() == "Game"){
				currentState = gameState;
				music.load("music/PacManMatch.mp3");
				music.play();	
			}else if(currentState->getNextState() == "MsGame"){
				currentState = msGameState;
				music.load("music/MsPacManMatch.mp3");
				music.play();
			}else if(currentState->getNextState() == "Over"){
				gameOverState->setScore(gameState->getFinalScore());
				currentState = gameOverState;
				music.unload();
			}else if(currentState->getNextState() == "MsOver"){
				msGameOverState->setMsScore(msGameState->getFinalMsScore());
				currentState = msGameOverState;
				music.unload();
			}else if(currentState->getNextState() == "Win"){
				currentState = winState;
				music.unload();
			}else if(currentState->getNextState() == "Pause"){
				currentState = pauseState;
				music.unload();
				music.load("music/PauseSound.mp3");
				music.play();
			}else if(currentState->getNextState() == "MsPause"){
				currentState = msPauseState;
				music.unload();
			}
			currentState->reset();
		}
	}
		
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr)
		currentState->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}

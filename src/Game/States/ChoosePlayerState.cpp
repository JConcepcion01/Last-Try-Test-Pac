#include <ChoosePlayerState.h>

PlayerSelectState::PlayerSelectState(){
    music.stop();
    MrButton = new Button(ofGetWindowWidth()/4, ofGetWindowHeight()/2, 64, 50, "Play as Pacman");
    MsButton = new Button(ofGetWindowWidth()/1.5, ofGetWindowHeight()/2, 64, 50, "Play as Ms. Pacman");
    Close = new Button(ofGetWindowWidth()/2.2, ofGetWindowHeight()/1.5, 64, 50, "Exit");
    Players.load("images/Mr&Ms.png");

}

void PlayerSelectState::tick(){
    MrButton->tick();
    MsButton->tick();
    Close->tick();
    if(MrButton->wasPressed()){      
        setNextState("Menu");
        setFinished(true);
    }
    if(MsButton->wasPressed()){
        setNextState("MsMenu");
        setFinished(true);
    }
    if(Close->wasPressed()){      
        ofExit();
    }
}

void PlayerSelectState::render(){
    Players.draw(ofGetWidth()/2-110, ofGetHeight()/2-200, 200, 200);
    ofDrawBitmapString("Player Selection Screen", ofGetWidth()/2 - 100, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	MrButton->render();
    MsButton->render();
    Close->render();
}

void PlayerSelectState::keyPressed(int key){
	
}

void PlayerSelectState::mousePressed(int x, int y, int button){
	MrButton->mousePressed(x, y);
    MsButton->mousePressed(x, y);
    Close->mousePressed(x, y);
}

void PlayerSelectState::reset(){
	setFinished(false);
	setNextState("");
	MrButton->reset();
    MsButton->reset();
    Close->reset();
}

PlayerSelectState::~PlayerSelectState(){
    delete MrButton;
    delete MsButton;
    delete Close;
}
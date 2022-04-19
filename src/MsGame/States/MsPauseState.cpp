#include "MsPauseState.h"

MsPauseState::MsPauseState(){
    music.stop();
    resumeButton = new MsButton(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 64, 50, "Resume");
    quitButton = new MsButton(ofGetWindowWidth()/2, ofGetWindowHeight()/2 + 60, 64, 50, "Quit");
}
void MsPauseState::tick(){
    resumeButton->tick();
    quitButton->tick();
    if(resumeButton->wasPressed()){      
        setNextState("MsGame");
        setFinished(true);
    }
    if(quitButton->wasPressed()){
        setNextState("Select");
        setFinished(true);
    }
}
void MsPauseState::render(){
    ofDrawBitmapString("Pause", ofGetWidth()/2 - 10, ofGetHeight()/2-300, 50);
    ofDrawBitmapString("Score: " + to_string(Msscore), ofGetWidth()/2 + 250, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	resumeButton->render();
    quitButton->render();
}
void MsPauseState::keyPressed(int key){
    
}
void MsPauseState::reset(){
    music.load("music/PauseSound.mp3");
    music.play();
    setFinished(false);
    setNextState("");
    resumeButton->reset();
    quitButton->reset();
}
void MsPauseState::mousePressed(int x, int y, int button){
    resumeButton->mousePressed(x,y);
    quitButton->mousePressed(x,y);
}
MsPauseState::~MsPauseState(){
    delete resumeButton;
    delete quitButton;
}

void MsPauseState::setMsScore(int sc){
    Msscore = sc;
}
#include "WinState.h"

WinState::WinState(){
menuButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Return to Main Menu");
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    anim = new Animation(10,rightAnimframes);
}

void WinState::tick(){
    menuButton->tick();
    anim->tick();
    if(menuButton->wasPressed()){
        setNextState("Select");
        setFinished(true);
    }
}

void WinState::render(){
    ofDrawBitmapString("Game Set! You win!", ofGetWidth()/2, 200);
    ofSetBackgroundColor(0,0,0);
    ofSetColor(256,256,256);
    anim->getCurrentFrame().draw(ofGetWidth()/2, ofGetHeight()/2-100, 100, 100);
    menuButton->render();
}

void WinState::keyPressed(int key){

}

void WinState::mousePressed(int x, int y, int button){
    menuButton->mousePressed(x, y);
}

void WinState::reset(){
    setFinished(false);
    setNextState("");
    menuButton->reset();
}

void WinState::setScore(int sc){
    score = sc;
}

WinState::~WinState(){
    delete menuButton;
    delete anim;
}
int WinState::getFinalScore(){
    return finalScore;
}
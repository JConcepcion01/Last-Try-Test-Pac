#include "MsGameOverState.h"

MsGameOverState::MsGameOverState() {
	startButton = new MsButton(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start");
	img1.load("images/MsPacman.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	anim = new Animation(10,rightAnimframes);

}
void MsGameOverState::tick() {
	startButton->tick();
	anim->tick();
	if(startButton->wasPressed()){
		setNextState("MsGame");
		setFinished(true);

	}
}
void MsGameOverState::render() {
	ofDrawBitmapString("Score: " + to_string(Msscore), ofGetWidth()/2, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2, ofGetHeight()/2-100, 100, 100);
	startButton->render();


}

void MsGameOverState::keyPressed(int key){
	
}

void MsGameOverState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MsGameOverState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}

void MsGameOverState::setMsScore(int sc){
    Msscore = sc;
}

MsGameOverState::~MsGameOverState(){
	delete startButton;
	delete anim;
}
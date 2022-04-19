#include "MsMenuState.h"
#include "chrono"
#include "thread"

MsMenuState::MsMenuState() {
	startButton = new MsButton(ofGetWidth()/2-32, ofGetHeight()/2, 64, 50, "Start");
	img1.load("images/MsPacman.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	anim = new Animation(10,rightAnimframes);

}
void MsMenuState::tick() {
	startButton->tick();
	anim->tick();
	if(startButton->wasPressed()){
		setNextState("MsGame");
		setFinished(true);
		music.load("music/MsStart-Up.mp3");
		music.play();
		std::this_thread::sleep_for(std::chrono::milliseconds(6250));

	}
}
void MsMenuState::render() {
	string title = "MsPacman Project";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2-50, ofGetHeight()/2-100, 100, 100);
	startButton->render();


}

void MsMenuState::keyPressed(int key){
	
}

void MsMenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MsMenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}

MsMenuState::~MsMenuState(){
	delete startButton;
	delete anim;
}
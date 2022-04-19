#pragma once

#include "State.h"
#include "MsButton.h"
#include "Animation.h" 
#include "ChoosePlayerState.h"
class MsGameOverState : public State {
private:
	ofImage img1;
	MsButton *startButton;
	Animation* anim;
	int Msscore=0;
	PlayerSelectState* loadImg;
public:
	MsGameOverState();
	~MsGameOverState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	void setMsScore(int);
};

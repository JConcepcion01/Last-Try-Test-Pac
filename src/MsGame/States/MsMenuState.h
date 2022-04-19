#pragma once

#include "State.h"
#include "MsButton.h"
#include "Animation.h"
#include "ChoosePlayerState.h"

class MsMenuState : public State {
private:
	ofSoundPlayer music;
	ofImage img1;
	MsButton *startButton;
	Animation* anim;
	PlayerSelectState* loadImg;
public:
	MsMenuState();
	~MsMenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};

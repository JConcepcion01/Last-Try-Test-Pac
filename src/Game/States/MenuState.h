#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h"
#include "ChoosePlayerState.h"

class MenuState : public State {
private:
	ofSoundPlayer music;
	ofImage img1;
	Button *startButton;
	Animation* anim;
public:
	MenuState();
	~MenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};

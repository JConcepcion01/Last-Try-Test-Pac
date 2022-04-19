#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h"

class WinState : public State{

private:
    ofImage img1;
    Button *menuButton;
    Animation* anim;
    int score = 0;
    int finalScore = 0;

public:
    WinState();
    ~WinState();
    void tick();
    void render();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    void reset();
    int getFinalScore();
    void setScore(int);
};
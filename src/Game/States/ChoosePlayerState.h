#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 

class PlayerSelectState : public State {
    private:
        Button *MrButton;
        Button *MsButton;
        Button *Close;
        ofSoundPlayer music;
        ofImage img1;
        ofImage Players;
        Animation* anim;

    public:

        PlayerSelectState();
        ~PlayerSelectState();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
        int score = 0;
        void setScore(int);

       

};
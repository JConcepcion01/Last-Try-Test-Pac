#pragma once
#include "State.h"
#include "MsButton.h"

class MsPauseState : public State{
    private:
        MsButton *resumeButton;
        MsButton *quitButton;
        ofSoundPlayer music;
    public:
        MsPauseState();
        ~MsPauseState();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
        int Msscore = 0;
        void setMsScore(int);
};
#pragma once

#include "State.h"
#include "MsPlayer.h"
#include "MsMapBuilder.h"

class MsGameState: public State{
    public: 
        MsGameState();
		~MsGameState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		int getFinalMsScore();
	
	private:
		ofSoundPlayer music;
		ofImage mapImage;
		MsMap* map;
		int finalMsScore=0;

};
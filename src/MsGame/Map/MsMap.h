#pragma once

#include "MsPlayer.h"
#include "GhostSpawner.h"

class MsMap{
    public:
      MsMap(EntityManager*);
      ~MsMap();
      void addBoundBlock(BoundBlock*);
      void addEntity(Entity*);
      MsPlayer* getPlayer();
      void setPlayer(MsPlayer*);
      void setGhostSpawner(GhostSpawner*);
      void tick();
      void render();
      void keyPressed(int key);
		  void mousePressed(int x, int y, int button);
		  void keyReleased(int key);

    private:
      EntityManager *entityManager;
      MsPlayer *player;
      GhostSpawner* gs;
};
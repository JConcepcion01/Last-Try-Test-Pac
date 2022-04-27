#include "PowerUp.h"

class DebuggPowerUp: public PowerUp{

    public:
    DebuggPowerUp();
    ~DebuggPowerUp();
    void activate();
    int getSpeed();

    private:

    int speed;
    bool isActive;

};
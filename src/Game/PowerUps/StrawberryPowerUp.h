#include "Entity.h"
#include "PowerUp.h"

class StrawberryPU: public PowerUp{

    public:

    StrawberryPU();
    ~StrawberryPU();
    void activate();
    bool getPassive();
    void setPassive(bool);
    void tick();


    private:

    bool Invincible = false;
    bool isActive;
    int InvincibleCounter;

};
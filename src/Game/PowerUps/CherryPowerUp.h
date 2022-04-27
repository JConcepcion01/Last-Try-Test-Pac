#include "Entity.h"
#include "PowerUp.h"

class CherryPU: public PowerUp{

    public:

    CherryPU();
    ~CherryPU();
    void activate();

    private:

    bool isActive;

};
#include "Weapon.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Weapon::Weapon() : Level(0), XP(0) {}
    // Methods
    void Weapon::AddXP(){
        if(this->XP < 9){
            this->XP += 1;
        }else {
            this->XP = 0;
            LevelUp();
        }
    }
    void Weapon::LevelUp(){
        this->Level+=1;
    }
}
#include "Weapon.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Weapon::Weapon() : IItem("no_name", false) {
        this->Level = 0;
        this->XP = 0;
    }
    Weapon::Weapon(std::string _name, int _price, bool _canBeStacked) : IItem(_name, _price, _canBeStacked) {
        this->Level = 0;
        this->XP = 0;
    }
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
        cout << "Weapon up to level " << this->Level << endl;
    }
}
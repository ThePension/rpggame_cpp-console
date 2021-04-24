#include "Staff.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Staff::Staff() : Weapon("no_name", false) {
        this->HealAmount = 0;
    }
    Staff::Staff(int HealAmount, std::string _name) : Weapon(_name, false) {
        this->HealAmount = HealAmount;
    }
    // Methods
    void Staff::Stats(){
        cout << "--- Staff ---" << endl;
        cout << "Heal Amount : " << this->HealAmount << endl;
        cout << "Level       : " << this->Level << endl;
        cout << "XP          : " << this->XP << endl;
    }
    int Staff::GetHealAmount() const {
        return this->HealAmount;
    }
}
#include "Sword.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Sword::Sword() : Weapon("no_name", false) {
        this->Damage = 0;
    }
    Sword::Sword(int Damage, int _price, std::string _name) : Weapon(_name, _price, false) {
        this->Damage = Damage;
    }
    // Methods
    void Sword::Stats(){
        cout << "--- Sword ---" << endl;
        cout << "Damage : " << this->Damage << endl;
        cout << "Level  : " << this->Level << endl;
        cout << "XP     : " << this->XP << endl;
    }
    int Sword::GetDamage() const {
        return this->Damage;
    }
}
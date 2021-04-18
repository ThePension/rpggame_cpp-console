#include "Sword.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Sword::Sword(){
        this->Damage = 0;
    }
    Sword::Sword(int Damage){
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
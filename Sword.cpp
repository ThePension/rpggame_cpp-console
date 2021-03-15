#include "Sword.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Sword::Sword(int Damage){
        this->Damage = Damage;
    }
    // Methods
    int Sword::GetDamage() const {
        return this->Damage;
    }
}
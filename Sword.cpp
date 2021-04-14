#include "Sword.h"
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
    int Sword::GetDamage() const {
        return this->Damage;
    }
}
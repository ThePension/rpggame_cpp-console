#include "Nordic.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Nordic::Nordic( RPG::Sword _sword, int _strength, int _agility, int _intelligence, double _hp, std::string _name, RPG::Dagger* _dagger) 
    : Hero(_strength, _agility, _intelligence, _hp, _name, _dagger){
        this->Sword = _sword;
        this->Stamina = 100;
    }
    // Methods
    void Nordic::Interact(const Hero &other)
    {
        cout << "Hello valiant " << other.GetName() << " !" << " I'm " << this->Name << " !" << endl;
    }
    void Nordic::Show()
    {
        cout << "=================" << endl;
        cout << "Nordic : " << this->Name << endl;
        cout << "=================" << endl;
        cout << "strength : " << this->Strength << endl;
        cout << "agility : " << this->Agility << endl;
        cout << "intelligence : " << this->Intelligence << endl;
        cout << "HP : " << this->HP << endl;
        cout << "Weapon : " << endl;
        this->Sword.Stats();
    }
}
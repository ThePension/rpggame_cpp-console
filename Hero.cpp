#include "Hero.h"
using namespace std;
namespace He_Arc::RPG
{
    void Hero::Interact(const Hero &other)
    {
        cout << "Bonjour " << other.Name << " !" << endl;
        cout << "Bonjour " << this->Name << " !" << endl;
    }
    void Hero::Show()
    {
        cout << "=================" << endl;
        cout << "HERO : " << this->Name << endl;
        cout << "=================" << endl;
        cout << "strength : " << this->Strength << endl;
        cout << "agility : " << this->Agility << endl;
        cout << "intelligence : " << this->Intelligence << endl;
        cout << "HP : " << this->HP << endl;
    }
}
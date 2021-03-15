#include "Hero.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Hero::Hero(){
        this->Strength = 0;
        this->Agility = 0;
        this->Intelligence = 0;
        this->HP = 0;
        this->Name = "no_name";
    }
    Hero::Hero(const Hero & hero){
        this->Strength = hero.Strength;
        this->Agility = hero.Agility;
        this->Intelligence = hero.Intelligence;
        this->HP = hero.HP;
        this->Name = hero.Name;
    }
    Hero::Hero(int _strength, int _agility, int _intelligence, double _hp, std::string _name):Strength(_strength), Agility(_agility), Intelligence(_intelligence), HP(_hp), Name(_name) { }
    // Methods
    void Hero::Interact(const Hero &other)
    {
        cout << "Hello valiant " << other.Name << " !" << " I'm " << this->Name << " !" << endl;
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
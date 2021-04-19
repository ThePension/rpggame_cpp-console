#include "Necromancer.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Necromancer::Necromancer(RPG::Staff _staff, int _strength, int _agility, int _intelligence, double _hp, std::string _name, RPG::Dagger* _dagger) 
    : Wizard(_staff, _strength, _agility, _intelligence, _hp, _name, _dagger){ }
    void Necromancer::RiseUndeads(){
        if(this->Mana >= 2){
            cout << "Rising undead" << endl;
            this->Mana -=2;
            cout << "Remaining mana : " << this->Mana << endl;
        }else{
            cout << "Not enough mana" << endl;
        }
    }
    // Methods
    void Necromancer::Show()
    {
        cout << "=================" << endl;
        cout << "Necromancer : " << this->Name << endl;
        cout << "=================" << endl;
        cout << "strength : " << this->Strength << endl;
        cout << "agility : " << this->Agility << endl;
        cout << "intelligence : " << this->Intelligence << endl;
        cout << "HP : " << this->HP << endl;
        cout << "Mana : " << this->Mana << endl;
        cout << "Weapons : " << endl;
        this->Staff.Stats();
        cout << "--- Spells ---" << endl; 
        cout << "- Cast Spell" << endl;
        cout << "- Rise Undeads" << endl;
        this->Dagger->Stats();
    }
}
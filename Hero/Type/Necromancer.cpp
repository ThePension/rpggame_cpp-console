#include "Necromancer.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Necromancer::Necromancer(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name) 
    : Wizard(x, y, charac, _strength, _agility, _intelligence, _hp, _name){ }
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
    void Necromancer::Show(int x, int y)
    {
        cout << "=================" << endl;
        cout << "Necromancer : " << this->Name << endl;
        cout << "=================" << endl;
        cout << "strength : " << this->Strength << endl;
        cout << "agility : " << this->Agility << endl;
        cout << "intelligence : " << this->Intelligence << endl;
        cout << "HP : " << this->HP << endl;
        cout << "Mana : " << this->Mana << endl;
        cout << "Current weapon :" << endl; GotoXY(x, y); x++;
        cout << " - " << this->CurrentWeapon->GetName() << " (lvl. " << this->CurrentWeapon->GetLevel() << ")" << endl; 
        cout << "--- Spells ---" << endl; 
        cout << "- Cast Spell" << endl;
        cout << "- Rise Undeads" << endl;
    }
}
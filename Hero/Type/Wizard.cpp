#include "Wizard.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Wizard::Wizard(int _strength, int _agility, int _intelligence, double _hp, std::string _name, RPG::Dagger* _dagger) 
    : Hero(_strength, _agility, _intelligence, _hp, _name, _dagger){
        this->Mana = 100;
    }
    void Wizard::CastSpell(){
        if(this->Mana >= 2){
            cout << "Fireball" << endl;
            this->Mana -=2;
            cout << "Remaining mana : " << this->Mana << endl;
        }else{
            cout << "Not enough mana" << endl;
        }
    }
    // Methods
    void Wizard::Interact(const Hero &other)
    {
        cout << "Hello valiant " << other.GetName() << " !" << " I'm " << this->Name << " !" << endl;
    }
    void Wizard::Show()
    {
        cout << "=================" << endl;
        cout << "Wizard : " << this->Name << endl;
        cout << "=================" << endl;
        cout << "strength : " << this->Strength << endl;
        cout << "agility : " << this->Agility << endl;
        cout << "intelligence : " << this->Intelligence << endl;
        cout << "HP : " << this->HP << endl;
        cout << "Mana : " << this->Mana << endl;
        cout << "--- Spells ---" << endl;
        cout << "- Cast Spell" << endl;
        this->Dagger->Stats();
    }
}
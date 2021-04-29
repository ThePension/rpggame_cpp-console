#include "Wizard.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Wizard::Wizard(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name) 
    : Hero(x, y, charac, _strength, _agility, _intelligence, _hp, _name){
        this->Mana = 100;
    }
    void Wizard::CastSpell(){
        if(this->Mana >= 2){
            cout << "Fireball" << endl;
            this->Mana -= 2;
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
    void Wizard::Show(int x, int y)
    {
        cout << "=================" << endl;
        cout << "Wizard : " << this->Name << endl;
        cout << "=================" << endl;
        cout << "strength : " << this->Strength << endl;
        cout << "agility : " << this->Agility << endl;
        cout << "intelligence : " << this->Intelligence << endl;
        cout << "HP : " << this->HP << endl;
        cout << "Mana : " << this->Mana << endl;
        cout << "Golds : " << this->GoldAmount << endl; GotoXY(x, y); x++;
        cout << "Current weapon :" << endl; GotoXY(x, y); x++;
        if(this->CurrentWeapon != nullptr) cout << " - " << this->CurrentWeapon->GetName() << " (lvl. " << this->CurrentWeapon->GetLevel() << ")" << endl; 
        else cout << " - None" << endl; 
        cout << "--- Spells ---" << endl;
        cout << "- Cast Spell" << endl;
    }
}
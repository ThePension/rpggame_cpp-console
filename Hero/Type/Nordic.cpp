#include "Nordic.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Nordic::Nordic(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name) 
    : Hero(x, y, charac, _strength, _agility, _intelligence, _hp, _name){
        this->Stamina = 100;
    }
    // Methods
    void Nordic::Interact(const Hero &other)
    {
        cout << "Hello valiant " << other.GetName() << " !" << " I'm " << this->Name << " !" << endl;
    }
    void Nordic::Show(int x1 = 0, int y1 = 0)
    {
        int x = x1, y = y1;
        GotoXY(x, y); x++;
        cout << "=================" << endl; GotoXY(x, y); x++;
        cout << "Nordic : " << this->Name << endl;  GotoXY(x, y); x++;
        cout << "=================" << endl;  GotoXY(x, y); x++;
        cout << "strength : " << this->Strength << endl;  GotoXY(x, y); x++;
        cout << "agility : " << this->Agility << endl;  GotoXY(x, y); x++;
        cout << "intelligence : " << this->Intelligence << endl;  GotoXY(x, y); x++;
        cout << "HP : " << this->HP << endl;  GotoXY(x, y); x++;
        cout << "Stamina : " << this->Stamina << endl;  GotoXY(x, y); x++;
        cout << "Current weapon :" << endl; GotoXY(x, y); x++;
        if(this->CurrentWeapon != nullptr) cout << " - " << this->CurrentWeapon->GetName() << " (lvl. " << this->CurrentWeapon->GetLevel() << ")" << endl; 
        else cout << " - None" << endl;
    }
}
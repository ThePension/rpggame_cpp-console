#include "Hero.h"
#include "../Items/Items/Potion.h"
#include "../Items/Items/Gold.h"
#include <windows.h>
using namespace std;
namespace He_Arc::RPG
{
    Hero::Hero() {
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
    Hero::Hero(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name) : RoomObject(x, y, charac)
    {
        this->Strength = _strength;
        this->Agility = _agility;
        this->Intelligence = _intelligence;
        this->HP = _hp;
        this->Name = _name;
    }
    Hero::~Hero() {
        while(!this->Inventory.GetContent().empty()) delete this->Inventory.GetContent().front(), this->Inventory.GetContent().pop_front();
    }            
    ostream& operator<<(ostream& os, const Hero & _Hero)
    {
        os << "=================" << endl;
        os << "HERO : " << _Hero.Name << endl;
        os << "=================" << endl;
        os << "strength : " << _Hero.Strength << endl;
        os << "agility : " << _Hero.Agility << endl;
        os << "intelligence : " << _Hero.Intelligence << endl;
        os << "HP : " << _Hero.HP << endl;
        return os;
    }
    Hero & Hero::operator=(const Hero & hero){
        if(this != &hero){
        this->Strength = hero.Strength;
            this->Agility = hero.Agility;
            this->Intelligence = hero.Intelligence;
            this->HP = hero.HP;
            this->Name = hero.Name;
        }
        return *this;
    }
    void Hero::Interact(RoomObject * RO) {
        char c = RO->GetChar();
        // std::list<IItem*> _ROInvent = RO->GetInventory();
        if(c == 'C'){ // If object if a chest
            if(RO->GetInventory()->GetContent().size() <= 10 - this->Inventory.GetContent().size()){ // If Inventory isn't full
                Gold * g;
                for(IItem * i : RO->GetInventory()->GetContent()){ // Control if there is gold
                    if(typeid(*i).name() == typeid(Gold).name()){
                        g = (Gold *)i;
                    }
                }
                if(g != nullptr){
                    RO->GetInventory()->GetContent().remove(g);
                    this->GoldAmount += g->GetGoldAmount();
                    delete g;
                    g = nullptr;
                }
                this->Inventory.AddItems(RO->GetInventory()->GetContent());
            }else{
                cout << "Not enough space" << endl;
            }
            RO->GetInventory()->DeleteInventory();
        }
    }
    void Hero::Interact(IItem * i){
        if(i->GetName().find("potion") != -1){ // If Item is a potion
            Potion * p = (Potion *)i; // Utiliser du dynamic_cast pour pouvoir caster l'item en potion
            this->HP += p->GetHealAmount();
            this->Inventory.GetContent().remove(p);
            delete p;
            p = nullptr;
        }else if(i->GetFeature().find("Weapon") != -1){ // If Item is Weapon
            Weapon * w = (Weapon *)i;
            this->CurrentWeapon = w;
        }
    }
    std::list<IItem*> Hero::GetInventoryContent() {
        return this->Inventory.GetContent();
    }
    Inventory * Hero::GetInventory() {
        return &this->Inventory;
    }
    void Hero::AddGold(int Gold){
        this->GoldAmount += Gold;
    }
}
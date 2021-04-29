#include "Hero.h"
#include "../Items/Items/Potion.h"
#include "../Items/Items/Gold.h"
#include <windows.h>
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Hero::Hero() {
        this->Strength = 0;
        this->Agility = 0;
        this->Intelligence = 0;
        this->HP = 0;
        this->Name = "no_name";
    }
    Hero::~Hero() {
        while(!this->Inventory.GetContent().empty()) delete this->Inventory.GetContent().front(), this->Inventory.GetContent().pop_front();
    }
    Hero::Hero(const Hero & hero){
        this->Strength = hero.Strength;
        this->Agility = hero.Agility;
        this->Intelligence = hero.Intelligence;
        this->HP = hero.HP;
        this->Name = hero.Name;
    }
    Hero::Hero(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name)
                : RoomObject(x, y, charac) // :Strength(_strength), Agility(_agility), Intelligence(_intelligence), HP(_hp), Name(_name), Dagger(_dagger) { }
    {
        this->Strength = _strength;
        this->Agility = _agility;
        this->Intelligence = _intelligence;
        this->HP = _hp;
        this->Name = _name;
    }
                
    // Methods
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
        if(c == 'C'){ // Si l'objet est un coffre
            if(RO->GetInventory()->GetContent().size() <= 10 - this->Inventory.GetContent().size()){ // Si l'inventaire n'est pas plein
                Gold * g;
                for(IItem * i : RO->GetInventory()->GetContent()){ // Contrôler s'il y a du gold
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
        if(i->GetName().find("potion") != -1){ // Si l'objet est une potion
            Potion * p = (Potion *)i; // Implémenter du dynamic_cast pour pouvoir caster l'item en potion
            this->HP += p->GetHealAmount();
            this->Inventory.GetContent().remove(p);
            delete p;
            p = nullptr;
        }else if(i->GetFeature().find("Weapon") != -1){ // Si l'objet est une arme
            // if(CurrentWeapon != nullptr){ // Si le joueur tient une arme dans ses mains
                Weapon * w = (Weapon *)i;
                this->CurrentWeapon = w;
            // }
        }
    }
    std::list<IItem*> Hero::GetInventoryContent() {
        return this->Inventory.GetContent();
    }
    Inventory * Hero::GetInventory() {
        return &this->Inventory;
    }
    /*void Hero::Interact(const Hero &other)
    {
        cout << "Hello valiant " << other.Name << " !" << " I'm " << this->Name << " !" << endl;
    }*/
    /*void Hero::Show()
    {
        cout << "=================" << endl;
        cout << "HERO : " << this->Name << endl;
        cout << "=================" << endl;
        cout << "strength : " << this->Strength << endl;
        cout << "agility : " << this->Agility << endl;
        cout << "intelligence : " << this->Intelligence << endl;
        cout << "HP : " << this->HP << endl;
    }*/
    void Hero::AddGold(int Gold){
        this->GoldAmount += Gold;
    }
}
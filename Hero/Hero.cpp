#include "Hero.h"
#include "../Items/Items/Potion.h"
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
        while(!this->Inventory.empty()) delete this->Inventory.front(), this->Inventory.pop_front();
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
    void Hero::ShowInventory(int y, int x){
        int x1 = x, j = 0;
        int y1 = y;
        GotoXY(1,25);
        cout << "Inventory : ("<<this->Inventory.size() << "/10)" << endl;
        if(this->Inventory.size() == 0){
            GotoXY(y1, x1);
            cout <<" Empty"<< endl;
        }else{
            for(const IItem * i : this->Inventory) {
                GotoXY(y1, x1); y1++;
                if(i->GetFeature().find("Weapon") != -1){ // Si l'objet est une arme
                    Weapon * w = (Weapon *)i;
                    if(w == CurrentWeapon){ // Si l'arme est l'arme tenue dans les mains du joueur
                        // Afficher l'arme en rouge
                        HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
                        HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hstdout, 0x0C);
                        cout <<" "<< j << ". " << i->GetName() << endl;
                        SetConsoleTextAttribute(hstdout, 0x0F);
                        FlushConsoleInputBuffer(hstdin);
                        j++;
                    }
                    else{
                         cout <<" "<< j << ". " << i->GetName() << endl;
                        j++;
                    }
                }else{
                    cout <<" "<< j << ". " << i->GetName() << endl;
                    j++;
                }
                
            }
        }
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
            if(RO->GetInventory().size() <= 10 - this->Inventory.size()){ // Si l'inventaire n'est pas plein
                this->AddItems(RO->GetInventory());
            }else{
                cout << "Not enough space" << endl;
            }
            RO->DeleteInventory();
        }
    }
    void Hero::Interact(IItem * i){
        if(i->GetName().find("potion") != -1){ // Si l'objet est une potion
            Potion * p = (Potion *)i; // Implémenter du dynamic_cast pour pouvoir caster l'item en potion
            this->HP += p->GetHealAmount();
            this->Inventory.remove(p);
            delete p;
            p = nullptr;
        }else if(i->GetFeature().find("Weapon") != -1){ // Si l'objet est une arme
            // if(CurrentWeapon != nullptr){ // Si le joueur tient une arme dans ses mains
                Weapon * w = (Weapon *)i;
                this->CurrentWeapon = w;
            // }
        }
    }
    IItem * Hero::GetInventoryItemAtIndex(int i){
         return *std::next(this->Inventory.begin(), i);
    }
    void Hero::DeleteInventory() {
        while(!this->Inventory.empty()) this->Inventory.pop_front();
    }
    void Hero::AddItems(const std::list<IItem*> _content){
        for(IItem * i : _content){
            this->Inventory.push_back(i);
        }
        // this->Inventory = _content;
    }
    void Hero::AddItem(IItem * i){
        this->Inventory.push_back(i);
    }
    std::list<IItem*> Hero::GetInventory() {
        return this->Inventory;
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
}
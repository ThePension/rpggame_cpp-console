#include "Chest.h"
#include <algorithm>
#include <windows.h>
using namespace std;
namespace He_Arc::RPG
{
    Chest::~Chest(){
        while(!this->Inventory.empty()) delete this->Inventory.front(), this->Inventory.pop_front();
    }
    void Chest::SetChestContent(const std::list<IItem*> _content){
        /*for(IItem *i : _content){
            this->Inventory.push_back(i);
        }*/
        this->Inventory = _content;
    }
    void Chest::AddItem(IItem * i){
        this->Inventory.push_back(i);
    }
    void Chest::Show(int x, int y) {
        int x1 = x;
        int y1 = y;
        for(const IItem * i : this->Inventory) {
            GotoXY(y1, x1); y1++;
            cout << " - " << i->GetName() << endl;
        }
    }
    void Chest::DeleteInventory() {
        while(!this->Inventory.empty()) this->Inventory.pop_front();
    }
    std::list<IItem*> Chest::GetInventory() {
        return this->Inventory;
    }
}
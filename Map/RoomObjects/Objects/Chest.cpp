#include "Chest.h"
#include <algorithm>
#include <windows.h>
using namespace std;
namespace He_Arc::RPG
{
    Chest::~Chest(){
        while(!this->Inventory.GetContent().empty()) delete this->Inventory.GetContent().front(), this->Inventory.GetContent().pop_front();
    }
    void Chest::Show(int x, int y) {
        int x1 = x;
        int y1 = y;
        if(this->Inventory.GetContent().size() == 0){
            GotoXY(y1, x1);
            cout <<" Empty"<< endl;
        }else{
            for(const IItem * i : this->Inventory.GetContent()) {
                GotoXY(y1, x1); y1++;
                cout << " - " << i->GetName() << endl;
            }   
        }
    }
    Inventory * Chest::GetInventory() {
        return &this->Inventory;
    }
    std::list<IItem*> Chest::GetInventoryContent() {
        return this->Inventory.GetContent();
    }
}
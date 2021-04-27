#include "Inventory.h"
#include <algorithm>
#include <windows.h>
#include "../Items/Items/Potion.h"
using namespace std;
namespace He_Arc::RPG
{
    Inventory::Inventory(){
        this->Size = 10;
    }
    Inventory::~Inventory(){
        while(!this->Content.empty()) delete this->Content.front(), this->Content.pop_front();
    }
    void Inventory::AddItems(const std::list<IItem*> _content){
        for(IItem * i : _content){
            Content.push_back(i);
        }
    }
    void Inventory::Show(int x, int y) {
        int x1 = x;
        int y1 = y;
        if(this->Content.size() == 0){
            GotoXY(y1, x1);
            cout <<" Empty"<< endl;
        }else{
            for(const IItem * i : this->Content) {
                GotoXY(y1, x1); x1++;
                cout << " - " << i->GetName() << endl;
            }   
        }
    }
    void Inventory::AddItem(IItem * i){
        Content.push_back(i);
    }
    std::list<IItem*> Inventory::GetContent() { 
        return this->Content; 
    }
    // Permet de définir la position du curseur
    void Inventory::GotoXY(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
    }
    void Inventory::DeleteInventory() {
        while(!this->Content.empty()) this->Content.pop_front();
    }
    IItem * Inventory::GetInventoryItemAtIndex(int i){
         return *std::next(this->Content.begin(), i);
    }
}
#include "Inventory.h"
#include <algorithm>
#include <windows.h>
using namespace std;
namespace He_Arc::RPG
{
    Inventory::Inventory(){
        this->Size = 10;
    }
    Inventory::Inventory(int _size){
        this->Size = _size;
    }
    Inventory::~Inventory(){
        while(!this->Content.empty()) delete this->Content.front(), this->Content.pop_front();
    }
    void Inventory::AddItems(const std::list<IItem*> _content){
        for(IItem *i : _content){
            Content.push_back(i);
        }
    }
    void Inventory::AddItem(IItem * i){
        Content.push_back(i);
    }
    void Inventory::Show(int y, int x){
        int x1 = x;
        int y1 = y;
        for(const IItem * i : this->Content){
            GotoXY(y1, x1); x1++;
            cout << " - " << i->GetName() << endl;
        }
    }
    // Permet de définir la position du curseur
    void Inventory::GotoXY(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
    }
}
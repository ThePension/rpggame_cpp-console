#include "Inventory.h"
#include <algorithm>
#include <windows.h>
using namespace std;
namespace He_Arc::RPG
{
    Inventory::Inventory(){

    }
    Inventory::Inventory(int _size){
        this->Size = _size;
    }
    Inventory::~Inventory(){

    }
    void Inventory::SetChestContent(const std::list<IItem*> _content){
        for(IItem *i : _content){
            Content.push_back(i);
        }
    }
    void Inventory::AddItem(IItem * i){
        Content.push_back(i);
    }
    void Inventory::Show(int x, int y){
        int x1 = x;
        int y1 = y;
        for(const IItem * i : this->Content){
            GotoXY(y1, x1); y1++;
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
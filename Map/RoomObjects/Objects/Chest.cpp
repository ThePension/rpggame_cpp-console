#include "Chest.h"
#include <algorithm>
#include <windows.h>
using namespace std;
namespace He_Arc::RPG
{
    void Chest::SetChestContent(const std::list<IItem*> _content){
        for(IItem *i : _content){
            Content.push_back(i);
        }
    }
    void Chest::AddItem(IItem * i){
        Content.push_back(i);
    }
    void Chest::Show(int x, int y){
        int x1 = x;
        int y1 = y;
        for(const IItem * i : this->Content){
            GotoXY(y1, x1); y1++;
            cout << " - " << i->GetName() << endl;
        }
    }
}
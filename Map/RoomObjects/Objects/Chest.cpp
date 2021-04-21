#include "Chest.h"
#include <algorithm>
#include <windows.h>
using namespace std;
namespace He_Arc::RPG
{
    void Chest::SetChestContent(const std::list<IItem*> _content){
        this->Content.AddItems(_content);
    }
    void Chest::AddItem(IItem * i){
        this->Content.AddItem(i);
    }
    void Chest::Show(int x, int y) {
        this->Content.Show(x, y);
    }
}
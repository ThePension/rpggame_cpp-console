#include "Wall.h"
using namespace std;
namespace He_Arc::RPG
{
    Wall::Wall(const Wall & W){
        this->Character = W.GetChar();
        this->PosX = W.GetX();
        this->PosY = W.GetY();
    }
}
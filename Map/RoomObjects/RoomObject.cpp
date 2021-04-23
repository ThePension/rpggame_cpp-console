#include "RoomObject.h"
#include <windows.h>
using namespace std;
namespace He_Arc::RPG
{
    RoomObject::RoomObject(){
        this->PosX = 0;
        this->PosY = 0;
        this->Character = 'O';
    }
    void RoomObject::GotoXY(int x, int y){
        COORD coord;
        coord.X = y;
        coord.Y = x;
        SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord );
    }
    char RoomObject::GetChar() const { 
        return this->Character; 
    }
}
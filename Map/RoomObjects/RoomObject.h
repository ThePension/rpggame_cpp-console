#ifndef ROOMOBJECT_H
#define ROOMOBJECT_H
#include <iostream>
namespace He_Arc::RPG
{
    class RoomObject
    {
        protected:
            // Attributs
            int PosX;
            int PosY;
            char Character;
            // std::string Name;
        public:
            // Constructors
            RoomObject();
            RoomObject(int X, int Y, char charac) : PosX(X), PosY(Y), Character(charac) {}
            // Methods
            // std::string GetName() const { return this->Name; }
            char GetChar() const { return this->Character; }
            int GetX() const { return this->PosX; }
            int GetY() const { return this->PosY; }
            void GotoXY(int x, int y);
            // virtual void Interact() = 0;
    };
}
#endif
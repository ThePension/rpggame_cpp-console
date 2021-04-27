#ifndef ROOMOBJECT_H
#define ROOMOBJECT_H
#include <iostream>
#include "../../Inventory/Inventory.h"
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
            char GetChar() const;
            int GetX() const { return this->PosX; }
            int GetY() const { return this->PosY; }
            void SetX(int x) { this->PosX = x; }
            void SetY(int y) { this->PosY = y; }
            void GotoXY(int x, int y);
            virtual void Show(int x, int y) = 0;
            virtual void Interact(RoomObject * RO) = 0;
            virtual  std::list<IItem*> GetInventoryContent() = 0;
            virtual Inventory * GetInventory() = 0;
            // virtual void Interact() = 0;
    };
}
#endif
#ifndef WALL_H
#define WALL_H
#include <iostream>
#include "../RoomObject.h"
#include "../../../Inventory/Inventory.h"
namespace He_Arc::RPG
{
    class Wall : public RoomObject
    {
        protected:
            // Attributs
        public:
            // Constructors
            Wall();
            Wall(const Wall & W);
            Wall(int X, int Y, char charac) : RoomObject(X, Y, charac) {}
            // Methods
            void Show(int x, int y) override {}
            void Interact(RoomObject * RO) override {}
            Inventory & GetInventory() override {
                Inventory  i = Inventory(); 
                return i; 
            }
            std::list<IItem*> GetInventoryContent() override {
                std::list<IItem*> lst;
                return lst;
            }
    };
}
#endif
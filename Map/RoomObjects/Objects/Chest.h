#ifndef CHEST_H
#define CHEST_H
#include <iostream>
#include <list>
#include "../RoomObject.h"
#include "../../../Items/IItem.h"
#include "../../../Inventory/Inventory.h"
namespace He_Arc::RPG
{
    class Chest : public RoomObject
    {
        private:
            // Attributs
            Inventory Content;
        public:
            // Constructors
            Chest();
            Chest(int X, int Y, char charac) : RoomObject(X, Y, charac) {}
            // Methods
            void SetChestContent(const std::list<IItem*> _content);
            void AddItem(IItem * i);
            void Show(int x, int y) override;
    };
}
#endif
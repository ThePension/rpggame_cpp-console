#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <list>
#include "../Items/IItem.h"
namespace He_Arc::RPG
{
    class Inventory
    {
        private:
            // Attributs
            int Size = 10;
            std::list<IItem*> Content;
        public:
            // Constructors
            Inventory();
            // Destructors
            ~Inventory();
            // Methods
            void AddItems(const std::list<IItem*> _content);
            void AddItem(IItem * i);
            // void Show(int x, int y);
            void GotoXY(int x, int y);
            // void DropItem(IItem * i);
            int GetSize() const { return this->Size; }
            std::list<IItem*> GetContent();
            IItem * GetInventoryItemAtIndex(int i);
            void Show(int x, int y);
            void DeleteInventory();
    };
}
#endif
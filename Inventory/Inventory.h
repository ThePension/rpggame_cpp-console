#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <list>
#include "../../Items/IItem.h"
#include "../Hero/Hero.h"
namespace He_Arc::RPG
{
    class Inventory
    {
        private:
            // Attributs
            int Size;
            std::list<IItem*> Content;
        public:
            // Constructors
            Inventory();
            Inventory(int _size = 10);
            // Destructors
            ~Inventory();
            // Methods
            void SetChestContent(const std::list<IItem*> _content);
            void AddItem(IItem * i);
            void Show(int x, int y);
            void GotoXY(int x, int y);
            // void DropItem(IItem * i);

    };
}
#endif
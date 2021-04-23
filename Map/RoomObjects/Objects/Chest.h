#ifndef CHEST_H
#define CHEST_H
#include <iostream>
#include <list>
#include "../RoomObject.h"
#include "../../../Items/IItem.h"
//#include "../../../Inventory/Inventory.h"
namespace He_Arc::RPG
{
    class Chest : public RoomObject
    {
        private:
            // Attributs
            // Inventory * Content;
            std::list<IItem*> Inventory;
        public:
            // Constructors
            Chest();
            Chest(int X, int Y, char charac) : RoomObject(X, Y, charac) {}
            ~Chest();
            // Methods
            void SetChestContent(const std::list<IItem*> _content);
            void AddItem(IItem * i);
            void Show(int x, int y) override;
            void Interact(RoomObject * i) override {}
            std::list<IItem*> GetInventory() override;
            void DeleteInventory() override;
            /*int GetSize(){
                return this->Inventory.size();
            }*/
    };
}
#endif
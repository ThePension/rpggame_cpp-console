#ifndef CHEST_H
#define CHEST_H
#include <iostream>
#include <list>
#include "../RoomObject.h"
#include "../../../Inventory/Inventory.h"
#include "../../../Items/IItem.h"
//#include "../../../Inventory/Inventory.h"
namespace He_Arc::RPG
{
    class Chest : public RoomObject
    {
        private:
            // Attributs
            Inventory Inventory;
            // std::list<IItem*> Inventory;
        public:
            // Constructors
            /**
             * @brief Construct a new default Chest object
             * 
             */
            Chest();
            /**
             * @brief Construct a new Chest object
             * 
             * @param X X Coordinate on the map
             * @param Y Y Coordinate on the map
             * @param charac Char the represents the Chest on the map 
             */
            Chest(int X, int Y, char charac) : RoomObject(X, Y, charac) {}
            /**
             * @brief Destroy the Chest object
             * 
             */
            ~Chest();
            // Methods
            /**
             * @brief Display the chest content at the X and Y coordinates
             * 
             * @param x 
             * @param y 
             */
            void Show(int x, int y) override;
            /**
             * @brief Interact with another RoomObject
             * 
             * @param i 
             */
            void Interact(RoomObject * i) override {}
            /**
             * @brief Get the Inventory Content object as a List<>
             * 
             * @return std::list<IItem*> 
             */
            std::list<IItem*> GetInventoryContent() override;
            /**
             * @brief Get the Inventory object as an Inventory Object
             * 
             * @return RPG::Inventory* 
             */
            RPG::Inventory * GetInventory() override;
    };
}
#endif
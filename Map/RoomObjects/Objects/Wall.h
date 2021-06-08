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
            /**
             * @brief Construct a new default Wall object
             * 
             */
            Wall();
            /**
             * @brief Copy Construct a new Wall object
             * 
             * @param W 
             */
            Wall(const Wall & W);
            /**
             * @brief Construct a new Wall object
             * 
             * @param X X Coordinate
             * @param Y Y Coordinate
             * @param charac Char the represents the Wall on the map 
             */
            Wall(int X, int Y, char charac) : RoomObject(X, Y, charac) {}
            // Methods
            // Useless
            void Show(int x, int y) override {}
            void Interact(RoomObject * RO) override {}
            /**
             * @brief Get the Inventory object as an Inventory Object
             * 
             * @return Inventory* 
             */
            Inventory * GetInventory() override {
                return nullptr; 
            }
            /**
             * @brief Get the Inventory Content object as a List<>
             * 
             * @return std::list<IItem*> 
             */
            std::list<IItem*> GetInventoryContent() override {
                std::list<IItem*> lst;
                return lst;
            }
    };
}
#endif
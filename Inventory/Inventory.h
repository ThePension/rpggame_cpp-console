#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <list>
#include "../Items/IItem.h"
using namespace std;
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
            /**
             * @brief Construct a new Inventory object
             * 
             */
            Inventory();
            // Destructors
            /**
             * @brief Destroy the Inventory object
             * 
             */
            ~Inventory();
            // Methods
            /**
             * @brief Add multiple Items in the Inventory
             * 
             * @param _content 
             */
            void AddItems(const std::list<IItem*> _content);
            /**
             * @brief Add one Item in the Inventory
             * 
             * @param i 
             */
            void AddItem(IItem * i);
            // void Show(int x, int y);
            /**
             * @brief Set the cursor position to the (X;Y) coordinates
             * 
             * @param x 
             * @param y 
             */
            void GotoXY(int x, int y);
            // void DropItem(IItem * i);
            /**
             * @brief Get the Size of the Inventory
             * 
             * @return int 
             */
            int GetSize() const { return this->Size; }
            /**
             * @brief Get the Content of the Inventory as a List<>
             * 
             * @return std::list<IItem*>& 
             */
            std::list<IItem*> & GetContent();
            /**
             * @brief Get the Inventory Item At Index object
             * 
             * @param i Index
             * @return IItem* 
             */
            IItem * GetInventoryItemAtIndex(int i);
            /**
             * @brief Display the content of the Inventory
             * 
             * @param str Name of the Inventory Object
             * @param index Index of the selected Item
             * @param x X Coordinate
             * @param y Y Coordinate
             */
            void Show(std::string str, int index, int x, int y);
            /**
             * @brief Delete Inventory Content
             * 
             */
            void DeleteInventory();
    };
}
#endif
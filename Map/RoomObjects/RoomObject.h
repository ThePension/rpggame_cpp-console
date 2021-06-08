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
            /**
             * @brief Construct a new default Room Object object
             * 
             */
            RoomObject();
            /**
             * @brief Construct a new Room Object object
             * 
             * @param X X Coordinate of the Object
             * @param Y Coordinate of the Object
             * @param charac Char that represents the object 
             */
            RoomObject(int X, int Y, char charac) : PosX(X), PosY(Y), Character(charac) {}
            // Methods
            // std::string GetName() const { return this->Name; }
            /**
             * @brief Get the Char object
             * 
             * @return char 
             */
            char GetChar() const;
            /**
             * @brief Get the x position
             * 
             * @return int 
             */
            int GetX() const { return this->PosX; }
            /**
             * @brief Get the y position
             * 
             * @return int 
             */
            int GetY() const { return this->PosY; }
            /**
             * @brief Set the x position
             * 
             * @param x 
             */
            void SetX(int x) { this->PosX = x; }
            /**
             * @brief Set the y position
             * 
             * @param y 
             */
            void SetY(int y) { this->PosY = y; }
            /**
             * @brief Set the cursor position
             * 
             * @param x 
             * @param y 
             */
            void GotoXY(int x, int y);
            /**
             * @brief Show the RoomObject content if there is
             * 
             * @param x 
             * @param y 
             */
            virtual void Show(int x, int y) = 0;
            /**
             * @brief Interact with another RoomObject
             * 
             * @param RO 
             */
            virtual void Interact(RoomObject * RO) = 0;
            /**
             * @brief Get the Inventory Content object as a List<>
             * 
             * @return std::list<IItem*> 
             */
            virtual  std::list<IItem*> GetInventoryContent() = 0;
            /**
             * @brief Get the Inventory object as an Inventory Object
             * 
             * @return Inventory* 
             */
            virtual Inventory * GetInventory() = 0;
    };
}
#endif
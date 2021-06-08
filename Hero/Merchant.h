#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>
#include "../Inventory/Inventory.h"
#include "../Weapons/Weapon.h"
#include "../Map/RoomObjects/RoomObject.h"

namespace He_Arc::RPG
{
    class Merchant : public RoomObject
    {
    protected:
        // Attributs
        std::string Name;
        Inventory Inventory;
        int GoldAmount = 0;
    public:
        // Constructors
        /**
         * @brief Construct a new default Merchant object
         * 
         */
        Merchant();
        /**
         * @brief Construct a new Merchant object
         * 
         * @param x X Coordinate on the map
         * @param y Y Coordinate on the map
         * @param charac Character that represents the hero on the map
         * @param _name Name of the Merchant
         * @param _goldAmount Gold amount of the Merchant
         */
        Merchant(int x, int y, char charac, std::string _name, int _goldAmount);
        // Destructors
        /**
         * @brief Destroy the Merchant object
         * 
         */
        ~Merchant();
        // Methods
        // Useless
        void Show(int x, int y) {}
        void Interact(RoomObject * RO) {}
        void Interact(IItem * i) {}
        /**
         * @brief Return the content of the Hero inventory as a List<>
         * 
         * @return std::list<IItem*> 
         */
        std::list<IItem*> GetInventoryContent() override;
        /**
         * @brief Return the content of the Hero inventory as an Inventory Object
         * 
         * @return RPG::Inventory* 
         */
        RPG::Inventory * GetInventory() override;
        // Getters
        /**
         * @brief Get the Name object
         * 
         * @return std::string 
         */
        std::string GetName() const { return Name; }
        /**
         * @brief Get the Gold object
         * 
         * @return int 
         */
        int GetGold() const { return GoldAmount; }
        /**
         * @brief Add Gold to the Merchant inventory
         * 
         * @param Gold 
         */
        void AddGold(int Gold);
    };
}
#endif
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
        Merchant();
        Merchant(int x, int y, char charac, std::string _name, int _goldAmount);
        // Destructors
        ~Merchant();
        // Methods
        void Show(int x, int y) {}
        void Interact(RoomObject * RO) {}
        void Interact(IItem * i) {}
        std::list<IItem*> GetInventoryContent() override;
        RPG::Inventory * GetInventory() override;
        // Getters
        std::string GetName() const { return Name; }
        void AddGold(int Gold);
        int GetGold() const { return GoldAmount; }
    };
}
#endif
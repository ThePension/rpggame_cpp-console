#include "Merchant.h"
#include "../Items/Items/Potion.h"
#include "../Items/Items/Gold.h"
#include <windows.h>
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Merchant::Merchant() {
        this->GoldAmount = 0;
        this->Name = "no_name";
    }
    Merchant::~Merchant() {
        while(!this->Inventory.GetContent().empty()) delete this->Inventory.GetContent().front(), this->Inventory.GetContent().pop_front();
    }
    Merchant::Merchant(int x, int y, char charac, std::string _name, int _goldAmount) : RoomObject(x, y, charac)
    {
        this->GoldAmount = _goldAmount;
        this->Name = _name;
    }
    // Methods
    std::list<IItem*> Merchant::GetInventoryContent() {
        return this->Inventory.GetContent();
    }
    Inventory * Merchant::GetInventory() {
        return &this->Inventory;
    }
    void Merchant::AddGold(int Gold){
        this->GoldAmount += Gold;
    }
}
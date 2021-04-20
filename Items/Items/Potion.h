#ifndef POTION_H
#define POTION_H
#include "../IItem.h"
#include <iostream>
namespace He_Arc::RPG
{
    class Potion : public IItem
    {
        private:
            // Attributs
            int HealAmount = 5;
        public:
            // Constructors
            Potion() : HealAmount(5) {}
            Potion(int HealAmout, std::string _name, bool _canBeStacked = false) : IItem(_name, _canBeStacked) {
                this->HealAmount = HealAmount;
            }
            // Methods
            // std::string GetName() const { return this->Name; }
            std::string GetName() override;
            std::string GetFeature() override;
    };
}
#endif
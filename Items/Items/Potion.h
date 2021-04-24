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
            int HealAmount;
        public:
            // Constructors
            // Potion() : HealAmount(5) {}
            Potion(int _healAmout, std::string _name, bool _canBeStacked = false);
            // Methods
            // std::string GetName() const { return this->Name; }
            std::string GetName() const override;
            std::string GetFeature() const override;
            int GetHealAmount() { return this->HealAmount; }
    };
}
#endif
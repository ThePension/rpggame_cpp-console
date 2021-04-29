#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include "../Weapon.h"
namespace He_Arc::RPG
{
    class Staff : public Weapon
    {
        private:
            // Attributs
            int HealAmount;
        public:
            // Constructors
            Staff();
            Staff(int HealAmount, int _price, std::string _name);
            // Methods
            void Stats() override;
            int GetHealAmount() const;
            std::string GetName() const override { return "Staff"; }
    };
}
#endif
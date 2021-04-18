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
            Staff(int HealAmount);
            // Methods
            void Stats() override;
            int GetHealAmount() const;
    };
}
#endif
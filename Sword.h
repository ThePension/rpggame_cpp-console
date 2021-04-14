#ifndef SWORD_H
#define SWORD_H
#include <iostream>
#include "Weapon.h"
namespace He_Arc::RPG
{
    class Sword : public Weapon
    {
        private:
            // Attributs
            int Damage;
        public:
            // Constructors
            Sword();
            Sword(int Damage);
            // Methods
            void Stats() override;
            int GetDamage() const;
    };
}
#endif
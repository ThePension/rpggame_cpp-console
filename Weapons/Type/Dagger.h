#ifndef DAGGER_H
#define DAGGER_H
#include <iostream>
#include "../Weapon.h"
namespace He_Arc::RPG
{
    class Dagger : public Weapon
    {
        private:
            // Attributs
            int Damage = 1;
        public:
            // Constructors
            Dagger();
            // Methods
            void Stats() override;
            std::string GetName() const override { return "Dagger"; }
    };
}
#endif
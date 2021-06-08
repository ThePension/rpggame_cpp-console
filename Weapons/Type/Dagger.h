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
            /**
             * @brief Construct a new Dagger object
             * 
             */
            Dagger();
            // Methods
            /**
             * @brief Display the Dagger's stats
             * 
             */
            void Stats() override;
            /**
             * @brief Get the Name object
             * 
             * @return std::string 
             */
            std::string GetName() const override { return "Dagger"; }
    };
}
#endif
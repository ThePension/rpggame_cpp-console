#ifndef SWORD_H
#define SWORD_H
#include <iostream>
#include "../Weapon.h"
namespace He_Arc::RPG
{
    class Sword : public Weapon
    {
        private:
            // Attributs
            int Damage;
        public:
            // Constructors
            /**
             * @brief Construct a new default Sword object
             * 
             */
            Sword();
            /**
             * @brief Construct a new Sword object
             * 
             * @param Damage 
             * @param _price 
             * @param _name 
             */
            Sword(int Damage, int _price, std::string _name);
            // Methods
            /**
             * @brief Display the Sword's stats
             * 
             */
            void Stats() override;
            /**
             * @brief Get the Damage object
             * 
             * @return int 
             */
            int GetDamage() const;
            /**
             * @brief Get the Name object
             * 
             * @return std::string 
             */
            std::string GetName() const override { return "Sword"; }
    };
}
#endif
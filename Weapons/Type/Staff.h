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
            /**
             * @brief Construct a new default Staff object
             * 
             */
            Staff();
            /**
             * @brief Construct a new Staff object
             * 
             * @param HealAmount 
             * @param _price 
             * @param _name 
             */
            Staff(int HealAmount, int _price, std::string _name);
            // Methods
            /**
             * @brief Display the Staff's stats
             * 
             */
            void Stats() override;
            /**
             * @brief Get the Heal Amount object
             * 
             * @return int 
             */
            int GetHealAmount() const;
            /**
             * @brief Get the Name object
             * 
             * @return std::string 
             */
            std::string GetName() const override { return "Staff"; }
    };
}
#endif
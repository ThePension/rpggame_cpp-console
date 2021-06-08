#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include "../Items/IItem.h"
namespace He_Arc::RPG
{
    class Weapon : public IItem
    {
        protected:
            // Attributs
            int Level = 0;
            int XP = 0;
        public:
            // Constructors
            /**
             * @brief Construct a new default Weapon object
             * 
             */
            Weapon();
            /**
             * @brief Construct a new Weapon object
             * 
             * @param _name Name of the Weapon
             * @param _price Price of the Weapon
             * @param _canBeStacked Can the Weapon be stacked in Inventory ?
             */
            Weapon(std::string _name, int _price, bool _canBeStacked = false);
            // Methods
            /**
             * @brief Display the Weapon stats
             * 
             */
            virtual void Stats() = 0;
            /**
             * @brief Get the Feature object
             * 
             * @return std::string 
             */
            std::string GetFeature() const override { return "Weapon"; }
            /**
             * @brief Get the Name object
             * 
             * @return std::string 
             */
            virtual std::string GetName() const = 0;
            /**
             * @brief Get the Level object
             * 
             * @return int 
             */
            int GetLevel() { return this->Level; }
            /**
             * @brief Add XP to the Weapon
             * 
             */
            void AddXP();
            /**
             * @brief Level up the Weapon
             * 
             */
            void LevelUp();
    };
}
#endif
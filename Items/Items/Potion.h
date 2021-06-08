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
            /**
             * @brief Construct a new Potion object
             * 
             * @param _healAmout Healamount of the Potion
             * @param _price Price of the Potion
             * @param _name Name of the Potion
             * @param _canBeStacked Can the Potion be stacked in Inventory ?
             */
            Potion(int _healAmout, int _price, std::string _name, bool _canBeStacked = false);
            // Methods
            /**
             * @brief Get the Name object
             * 
             * @return std::string 
             */
            std::string GetName() const override;
            /**
             * @brief Get the Feature object
             * 
             * @return std::string 
             */
            std::string GetFeature() const override;
            /**
             * @brief Get the Heal Amount object
             * 
             * @return int 
             */
            int GetHealAmount() { return this->HealAmount; }
    };
}
#endif
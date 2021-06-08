#ifndef IITEM_H
#define IITEM_H
#include <iostream>
namespace He_Arc::RPG
{
    class IItem
    {
        protected:
            // Attributs
            std::string Name;
            bool CanBeStacked;
            int Price;
        public:
            // Constructors
            /**
             * @brief Construct a new default IItem object
             * 
             */
            IItem();
            /**
             * @brief Construct a new IItem object
             * 
             * @param _name Name of the Item
             * @param _price Price of the Item
             * @param _canBeStacked Can the Item be stacked in Inventory ?
             */
            IItem(std::string _name, int _price, bool _canBeStacked = false) : Name(_name), Price(_price), CanBeStacked(_canBeStacked) {}
            // Getters
            /**
             * @brief Get the Name object
             * 
             * @return std::string 
             */
            virtual std::string GetName() const = 0;
            /**
             * @brief Get the Feature object
             * 
             * @return std::string 
             */
            virtual std::string GetFeature() const = 0;
            /**
             * @brief Get the Price object
             * 
             * @return int 
             */
            int GetPrice() const { return this->Price; }
    };
}
#endif
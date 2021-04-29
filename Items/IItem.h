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
            IItem();
            IItem(std::string _name, int _price, bool _canBeStacked = false) : Name(_name), Price(_price), CanBeStacked(_canBeStacked) {}
            // Methods
            virtual std::string GetName() const = 0;
            virtual std::string GetFeature() const = 0;
    };
}
#endif
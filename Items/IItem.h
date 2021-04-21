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
        public:
            // Constructors
            IItem();
            IItem(std::string _name, bool _canBeStacked = false) : Name(_name), CanBeStacked(_canBeStacked) {}
            // Methods
            virtual std::string GetName() const = 0;
            virtual std::string GetFeature() const = 0;
    };
}
#endif
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
            // std::string GetName() const { return this->Name; }
            virtual std::string GetName() = 0;
            virtual std::string GetFeature() = 0;
    };
}
#endif
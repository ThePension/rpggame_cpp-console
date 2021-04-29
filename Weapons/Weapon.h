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
            Weapon();
            Weapon(std::string _name, int _price, bool _canBeStacked = false);
            // Methods
            virtual void Stats() = 0;
            std::string GetFeature() const override { return "Weapon"; }
            virtual std::string GetName() const = 0;
            int GetLevel() { return this->Level; }
            void AddXP();
            void LevelUp();
    };
}
#endif
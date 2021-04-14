#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
namespace He_Arc::RPG
{
    class Weapon
    {
        protected:
            // Attributs
            int Level = 0;
            int XP = 0;
        public:
            // Constructors
            Weapon();
            // Methods
            virtual void Stats() = 0;
            void AddXP();
            void LevelUp();
    };
}
#endif
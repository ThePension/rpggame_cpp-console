#ifndef SWORD_H
#define SWORD_H
#include <iostream>
namespace He_Arc::RPG
{
    class Sword
    {
        private:
            // Attributs
            int Damage;
        public:
            // Constructors
            Sword();
            Sword(int Damage);
            // Methods
            int GetDamage() const;
    };
}
#endif
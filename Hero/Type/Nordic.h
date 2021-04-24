#ifndef NORDIC_H
#define NORDIC_H
#include <iostream>
#include "../Hero.h"
#include "../../Weapons/Type/Sword.h"
namespace He_Arc::RPG
{
    class Nordic : public Hero
    {
    private:
        // Attributs
        int Stamina;
    public:
        // Constructors
        Nordic(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name);
        // Methods
        void Show(int x, int y) override;
        void Interact(const Hero &other) override;
        void Attack(Hero & other);
        // friend std::ostream& operator<<(std::ostream& os, const Hero & _Hero);
    };
}
#endif
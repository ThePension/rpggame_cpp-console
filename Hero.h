#ifndef HERO_H
#define HERO_H
#include <iostream>
#include "Sword.h"
namespace He_Arc::RPG
{
    class Hero
    {
    private:
        // Attributs
        int Strength;
        int Agility;
        int Intelligence;
        double HP;
        std::string Name;
        Sword * Sword = nullptr;

    public:
        // Constructors
        Hero();
        // Hero(const Hero &);
        Hero(int _strength, int _agility, int _intelligence, double _hp, std::string _name, RPG::Sword * _sword = nullptr);
        // Methods
        void Show();
        void Interact(const Hero &other);
        int GetAgility();
        friend std::ostream& operator<<(std::ostream& os, const Hero & _Hero);
    };
}
#endif
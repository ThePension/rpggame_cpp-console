#ifndef HERO_H
#define HERO_H
#include <iostream>
#include "Dagger.h"
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
        Dagger * Dagger = nullptr;

    public:
        // Constructors
        Hero();
        Hero(const Hero &);
        Hero(int _strength, int _agility, int _intelligence, double _hp, std::string _name, RPG::Dagger * _dagger = nullptr);
        // Destructors
        ~Hero();
        // Methods
        void Show();
        void Interact(const Hero &other);
        int GetAgility();
        friend std::ostream& operator<<(std::ostream& os, const Hero & _Hero);
        Hero & operator=(const Hero &);
    };
}
#endif
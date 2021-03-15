#ifndef HERO_H
#define HERO_H
#include <iostream>
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

    public:
        // Constructors
        Hero();
        Hero(int _strength, int _agility, int _intelligence, double _hp, std::string _name);
        // Methods
        void Show();
        void Interact(const Hero &other);
        int GetAgility();
    };
}
#endif
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
        void Show();
        void Interact(const Hero &);
        int GetAgility();
    };
}
#endif
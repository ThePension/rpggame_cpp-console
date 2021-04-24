#ifndef WIZARD_H
#define WIZARD_H
#include <iostream>
#include "../Hero.h"
#include "../../Weapons/Type/Staff.h"
namespace He_Arc::RPG
{
    class Wizard : public Hero
    {
    protected:
        // Attributs
        int Mana;
    public:
        // Constructors
        Wizard(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name);
        // Methods
        void Show(int x, int y) override;
        void Interact(const Hero &other) override;
        void CastSpell();
        // friend std::ostream& operator<<(std::ostream& os, const Hero & _Hero);
    };
}
#endif
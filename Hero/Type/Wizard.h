#ifndef WIZARD_H
#define WIZARD_H
#include <iostream>
#include "../Hero.h"
#include "../../Weapons/Type/Sword.h"
namespace He_Arc::RPG
{
    class Wizard : public Hero
    {
    protected:
        // Attributs
        int Mana;
    public:
        // Constructors
        Wizard(int _strength, int _agility, int _intelligence, double _hp, std::string _name, RPG::Dagger * _dagger = nullptr);
        // Methods
        void Show() override;
        void Interact(const Hero &other) override;
        void CastSpell();
        // friend std::ostream& operator<<(std::ostream& os, const Hero & _Hero);
    };
}
#endif
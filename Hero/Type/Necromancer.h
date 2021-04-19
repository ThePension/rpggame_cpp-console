#ifndef NECROMANCER_H
#define NECROMANCER_H
#include <iostream>
#include "Wizard.h"
namespace He_Arc::RPG
{
    class Necromancer : public Wizard
    {
    public:
        // Constructors
        Necromancer(int _strength, int _agility, int _intelligence, double _hp, std::string _name, RPG::Dagger * _dagger = nullptr);
        // Methods
        void Show() override;
        void RiseUndeads();
        // friend std::ostream& operator<<(std::ostream& os, const Hero & _Hero);
    };
}
#endif
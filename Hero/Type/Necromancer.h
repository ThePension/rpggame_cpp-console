#ifndef NECROMANCER_H
#define NECROMANCER_H
#include <iostream>
#include "Wizard.h"
#include "../../Weapons/Type/Staff.h"
namespace He_Arc::RPG
{
    class Necromancer : public Wizard
    {
    public:
        // Constructors
        Necromancer(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name);
        // Methods
        void Show(int x, int y) override;
        void RiseUndeads();
        // friend std::ostream& operator<<(std::ostream& os, const Hero & _Hero);
    };
}
#endif
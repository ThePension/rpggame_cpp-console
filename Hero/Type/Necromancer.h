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
        /**
         * @brief Construct a new Necromancer object
         * 
         * @param x X Coordinate on the map
         * @param y X Coordinate on the map
         * @param charac Character that represents the Necromancer on the map
         * @param _strength Strength of the Necromancer
         * @param _agility Agility of the Necromancer
         * @param _intelligence Intelligence of the Necromancer
         * @param _hp Healpoint of the Necromancer
         * @param _name Name of the Necromancer
         */
        Necromancer(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name);
        // Methods
        /**
         * @brief Display the Hero's stats on console at the (X;Y) coordoninates
         * 
         * @param x X Coordinate
         * @param y Y Coordinate
         */
        void Show(int x, int y) override;
        // Useless
        void RiseUndeads();
    };
}
#endif
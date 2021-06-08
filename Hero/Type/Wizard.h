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
        /**
         * @brief Construct a new Wizard object
         * 
         * @param x X Coordinate on the map
         * @param y Y Coordinate on the map
         * @param charac Character that represents the hero on the map
         * @param _strength Strength of the Wizard
         * @param _agility Agility of the Wizard
         * @param _intelligence Intelligence of the Wizard
         * @param _hp Healppoint of the Wizard
         * @param _name Name of the Wizard
         */
        Wizard(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name);
        // Methods
        /**
         * @brief Display the Hero's stats on console at the (X;Y) coordoninates
         * 
         * @param x X Coordinate
         * @param y Y Coordinate
         */
        void Show(int x, int y) override;
        /**
         * @brief Interact with another Hero
         * 
         * @param other 
         */
        void Interact(const Hero &other) override;
        // Useless
        void CastSpell();
    };
}
#endif
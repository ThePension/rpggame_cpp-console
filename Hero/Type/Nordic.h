#ifndef NORDIC_H
#define NORDIC_H
#include <iostream>
#include "../Hero.h"
#include "../../Weapons/Type/Sword.h"
namespace He_Arc::RPG
{
    class Nordic : public Hero
    {
    private:
        // Attributs
        int Stamina;
    public:
        // Constructors
        /**
         * @brief Construct a new Nordic object
         * 
         * @param x X Coordinate on the map
         * @param y Y Coordinate on the map
         * @param charac Character that represents the hero on the map
         * @param _strength Strength of the Nordic
         * @param _agility Agility of the Nordic
         * @param _intelligence Intelligence of the Nordic
         * @param _hp Healpoint of the Nordic
         * @param _name Name of the Nordic
         */
        Nordic(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name);
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
        void Attack(Hero & other);
    };
}
#endif
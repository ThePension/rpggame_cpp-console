#ifndef HERO_H
#define HERO_H
#include <iostream>
#include "../Weapons/Type/Dagger.h"
#include "../Map/RoomObjects/RoomObject.h"
namespace He_Arc::RPG
{
    class Hero : public RoomObject
    {
    protected:
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
        Hero(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name, RPG::Dagger * _dagger = nullptr);
        // Destructors
        ~Hero();
        // Methods
        virtual void Show(int x, int y) = 0;
        virtual void Interact(const Hero &other) = 0;
        // Getters
        int GetAgility() const {return Agility; }
        int GetStrength() const { return Strength; }
        int GetIntelligence() const { return Intelligence; }
        double GetHP() const { return HP; }
        std::string GetName() const { return Name; }
        RPG::Dagger* GetDagger() const { return Dagger; }
        friend std::ostream& operator<<(std::ostream& os, const Hero & _Hero);
        Hero & operator=(const Hero &);
    };
}
#endif
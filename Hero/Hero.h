#ifndef HERO_H
#define HERO_H
#include <iostream>
#include "../Inventory/Inventory.h"
#include "../Weapons/Weapon.h"
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
        Inventory Inventory;
        Weapon * CurrentWeapon = nullptr;
        int GoldAmount = 0;
    public:
        // Constructors
        /**
         * @brief Construct a new Default Hero:: Hero object
         * 
         */
        Hero();
        /**
         * @brief Construct a new Hero:: Hero object
         * 
         * @param x X Coordinates on the map
         * @param y Y Coordinates on the map
         * @param charac Character that represents the hero on the map
         * @param _strength Strength of the hero
         * @param _agility Agility of the hero
         * @param _intelligence Intelligence of the hero
         * @param _hp Healpoint of the hero
         * @param _name Name of the hero
         */
        Hero(int x, int y, char charac, int _strength, int _agility, int _intelligence, double _hp, std::string _name);
        /**
         * @brief Construct a new Hero:: Hero object
         * 
         * @param hero 
         */
        Hero(const Hero &);
        
        // Destructors
        /**
         * @brief Destroy the Hero:: Hero object
         * 
         */
        ~Hero();
        // Methods
        /**
         * @brief Display the Hero's stats on console at the (X;Y) coordoninates
         * 
         * @param x X Coordinate
         * @param y Y Coordinate
         */
        virtual void Show(int x, int y) = 0;
        /**
         * @brief Interact with another Hero
         * 
         * @param other 
         */
        virtual void Interact(const Hero &other) = 0;
        /**
         * @brief Interact with a RoomObject
         * 
         * @param RO RoomObject to interact with
         */
        virtual void Interact(RoomObject * RO);
        /**
         * @brief Interact with an Item
         * 
         * @param i Item to interact with
         */
        void Interact(IItem * i);
        /**
         * @brief Return the content of the Hero inventory
         * 
         * @return std::list<IItem*> 
         */
        std::list<IItem*> GetInventoryContent() override;
        /**
         * @brief Return the content of the Hero inventory
         * 
         * @return Inventory* 
         */
        RPG::Inventory * GetInventory() override;
        // Getters
        /**
         * @brief Get the Agility object
         * 
         * @return int 
         */
        int GetAgility() const { return Agility; }
        /**
         * @brief Get the Strength object
         * 
         * @return int 
         */
        int GetStrength() const { return Strength; }
        /**
         * @brief Get the Intelligence object
         * 
         * @return int 
         */
        int GetIntelligence() const { return Intelligence; }
        /**
         * @brief 
         * 
         * @return double 
         */
        double GetHP() const { return HP; }
        /**
         * @brief Get the Name object
         * 
         * @return std::string 
         */
        std::string GetName() const { return Name; }
        /**
         * @brief Get the Gold object
         * 
         * @return int 
         */
        int GetGold() const { return GoldAmount; }
        /**
         * @brief Return ostream that display the hero's stats
         * 
         * @param os 
         * @param _Hero 
         * @return ostream& 
         */
        friend std::ostream& operator<<(std::ostream& os, const Hero & _Hero);
        /**
         * @brief 
         * 
         * @return Hero& 
         */
        Hero & operator=(const Hero &);
        /**
         * @brief Add gold to the Hero inventory
         * 
         * @param Gold 
         */
        void AddGold(int Gold);
    };
}
#endif
#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "RoomObjects/RoomObject.h"
#include "../Hero/Hero.h"
namespace He_Arc::RPG
{
    class Room
    {
        private:
            // Attributs
            int Heigth = 10;
            int Width = 20;
            // char Pattern[10][20];
            Hero * Player;
            RoomObject * ROPattern[10][20];
        public:
            // Constructors
            /**
             * @brief Construct a new default Room object
             * 
             */
            Room();
            // Destructors
            /**
             * @brief Destroy the Room object
             * 
             */
            ~Room();
            // Room(int Heigth, int Width, std::string Pattern[20][20]);
            // Methods
            /**
             * @brief Update the Player Position in the Room
             * 
             * @param key 
             */
            void Update(char key);
            /**
             * @brief Display the Room in the console
             * 
             */
            void Display();
            /**
             * @brief Check around the player position, and return the first RoomObject find
             * 
             * @param x Player X Coordinate
             * @param y Player Y Coordinate
             * @return RoomObject* 
             */
            RoomObject * CheckAround(int x, int y);
            /**
             * @brief Set the cursor position
             * 
             * @param x 
             * @param y 
             */
            void GotoXY(int x, int y);
            /**
             * @brief Display Player's stats
             * 
             */
            void ShowPlayerStats();
            /**
             * @brief Display Help for Key binding
             * 
             */
            void KeyHelp();
            /**
             * @brief Get the Player object
             * 
             * @return Hero* 
             */
            Hero * GetPlayer() { return this->Player; }
    };
}
#endif
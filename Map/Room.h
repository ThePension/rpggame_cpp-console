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
            RoomObject ROPattern[10][20];
        public:
            // Constructors
            Room();
            // Room(int Heigth, int Width, std::string Pattern[20][20]);
            // Methods
            void Update(char key);
            void Display();
            void CheckAround(int x, int y);
            void GotoXY(int x, int y);
            void ShowPlayerStats();
            void KeyHelp();
    };
}
#endif
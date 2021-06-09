#ifndef TRADINGSYTEM_H
#define TRADINGSYTEM_H
#include <iostream>
#include <iomanip>
#include "../Hero/Hero.h"
#include "../Hero/Merchant.h"
#include "../Items/IItem.h"
#include "../Map/Room.h"
using namespace std;

namespace He_Arc::RPG
{
    class TradingSystem {
        public:
            /**
             * @brief Construct a new Trading System object
             * 
             */
            TradingSystem();
            /**
             * @brief Initialize the trading system with a merchant
             * 
             * @param m Marchant
             * @param room Room
             */
            void Init(Merchant * m, Room & room);
            /**
             * @brief Initialize the trading system with another hero
             * 
             * @param h Hero
             * @param room Room
             */
            void Init(Hero * h, Room & room);
            /**
             * @brief Draw a vertical line
             * 
             * @param x X Coordinate
             * @param length Length of the line
             */
            void DrawVertLine(int x, int length);
            /**
             * @brief Set the cursor position
             * 
             * @param x X Coordinate
             * @param y Y Coordinate
             */
            void GotoXY(int x, int y);
    };
}
#endif
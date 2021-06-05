#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <iomanip>
#include "../Hero/Hero.h"
#include "../Hero/Merchant.h"
#include "../Items/IItem.h"
using namespace std;

namespace He_Arc::RPG
{
    class Log{
        public:
            Log() {}
            void MessageLog(std::string message);
            void TradeLog(Hero* h, IItem * i, Merchant m);
            void TradeLog(Merchant m, IItem * i, Hero* h);
            void ErrorLog(exception e);
            void ErrorLog(string message);
            string getCurrentDateTime();
    };
}
#endif

// Based on :
// https://stackoverflow.com/questions/7400418/writing-a-log-file-in-c-c
// https://en.cppreference.com/w/cpp/io/c/freopen
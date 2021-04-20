#ifndef CHEST_H
#define CHEST_H
#include <iostream>
#include "../RoomObject.h"
namespace He_Arc::RPG
{
    class Chest : public RoomObject
    {
        protected:
            // Attributs
            // Item Content
            // std::string Name;
        public:
            // Constructors
            Chest();
            Chest(int X, int Y, char charac) : RoomObject(X, Y, charac) {}
            // Methods
    };
}
#endif
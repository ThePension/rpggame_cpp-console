#ifndef WALL_H
#define WALL_H
#include <iostream>
#include "../RoomObject.h"
namespace He_Arc::RPG
{
    class Wall : public RoomObject
    {
        protected:
            // Attributs
        public:
            // Constructors
            Wall();
            Wall(const Wall & W);
            Wall(int X, int Y, char charac) : RoomObject(X, Y, charac) {}
            // Methods
    };
}
#endif
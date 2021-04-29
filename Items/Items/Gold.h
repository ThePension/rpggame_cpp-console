#ifndef GOLD_H
#define GOLD_H
#include "../IItem.h"
#include <iostream>
namespace He_Arc::RPG
{
    class Gold : public IItem
    {
        private:
            // Attributs
            int GoldAmount;
        public:
            Gold(int _GoldAmount);
            // Methods
            std::string GetName() const override;
            std::string GetFeature() const override;
            int GetGoldAmount() const { return this->GoldAmount; }
    };
}
#endif
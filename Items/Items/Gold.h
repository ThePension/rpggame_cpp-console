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
            /**
             * @brief Construct a new Gold object
             * 
             * @param _GoldAmount 
             */
            Gold(int _GoldAmount);
            // Getter
            /**
             * @brief Get the Name object
             * 
             * @return std::string 
             */
            std::string GetName() const override;
            /**
             * @brief Get the Feature object
             * 
             * @return std::string 
             */
            std::string GetFeature() const override;
            /**
             * @brief Get the Gold Amount object
             * 
             * @return int 
             */
            int GetGoldAmount() const { return this->GoldAmount; }
    };
}
#endif
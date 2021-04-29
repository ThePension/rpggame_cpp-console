#include "Gold.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Gold::Gold(int _GoldAmount) : IItem("Gold", 1, false) {
        this->GoldAmount = _GoldAmount;
    }
        
    std::string Gold::GetName() const {
        if(this->GoldAmount>1) return std::to_string(this->GoldAmount) + " Golds";
        else return std::to_string(this->GoldAmount) + " Gold";
    }
    std::string Gold::GetFeature() const{
        return "Can buy stuff";
    }
}
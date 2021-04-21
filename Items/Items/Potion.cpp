#include "Potion.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Potion::Potion(int _healAmout, std::string _name, bool _canBeStacked) : IItem(_name, _canBeStacked) {
        this->HealAmount = _healAmout;
    }
        
    std::string Potion::GetName() const{
        return this->Name + " : " + std::to_string(this->HealAmount) + "HP";
    }
    std::string Potion::GetFeature() const{
        return "Heals the player HP";
    }
}
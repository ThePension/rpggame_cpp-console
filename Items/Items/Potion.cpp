#include "Potion.h"
using namespace std;
namespace He_Arc::RPG
{
    std::string Potion::GetName(){
        return "Potion : " + std::to_string(HealAmount) + "HP";
    }
    std::string Potion::GetFeature(){
        return "Heals the player HP";
    }
}
#include "Dagger.h"
#include "../../Hero/Hero.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Dagger::Dagger() : Weapon("Dagger", 5, false) {
        this->Damage = 1;
    }
    // Methods
    void Dagger::Stats(){
        cout << "--- Dagger ---" << endl;
        cout << "Damage : 1" << endl;
    }
}
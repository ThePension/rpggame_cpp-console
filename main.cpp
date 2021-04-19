/*
* Auteur      : Aubert Nicolas
* Date        : 15.03.2021
* Contexte    : Langage c++ : Projet fil rouge
* Description : Jeu RPG
*/
#include <iostream>
#include "Hero/Type/Nordic.h"
#include "Hero/Type/Wizard.h"
#include "Hero/Type/Necromancer.h"
#include "Weapons/Type/Dagger.h"
using namespace std;
using namespace He_Arc::RPG;

int main(int argc, char const *argv[])
{
    // Test Nordic class
    Dagger * PyroBarbareSword_dagger = new Dagger();
    Sword PyroBarbareSword = Sword(5);
    Nordic PyroBarbare = Nordic(PyroBarbareSword, 20, 5, 15, 25, "PyroBarbare", PyroBarbareSword_dagger);
    PyroBarbare.Show();

    // Test Wizard class
    Dagger * GandoulfLeRose_dagger = new Dagger();
    Wizard GandoulfLeRose = Wizard(5, 15, 25, 10, "Gandoulf le Rose", GandoulfLeRose_dagger);
    GandoulfLeRose.CastSpell();
    GandoulfLeRose.Show();

    // Test Necromancer class
    Dagger * MolagBal_dagger = new Dagger();
    Necromancer MolagBal = Necromancer(5, 15, 25, 10, "Molag Bal", MolagBal_dagger);
    MolagBal.RiseUndeads();
    MolagBal.CastSpell();
    //MolagBal.RiseUndeads();
    //MolagBal.RiseUndeads();
    MolagBal.Show();

    return 0;
}
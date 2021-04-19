/*
* Auteur      : Aubert Nicolas
* Date        : 15.03.2021
* Contexte    : Langage c++ : Projet fil rouge
* Description : Jeu RPG
*/
#include <iostream>
#include <list>
#include <algorithm>
#include "Hero/Type/Nordic.h"
#include "Hero/Type/Wizard.h"
#include "Hero/Type/Necromancer.h"
#include "Weapons/Type/Dagger.h"
#include "Weapons/Type/Staff.h"
using namespace std;
using namespace He_Arc::RPG;

int main(int argc, char const *argv[])
{
    // Test Nordic class
    Dagger * PyroBarbareSword_dagger = new Dagger();
    Sword PyroBarbareSword = Sword(5);
    Nordic * PyroBarbare = new Nordic(PyroBarbareSword, 20, 5, 15, 25, "PyroBarbare", PyroBarbareSword_dagger);
    //PyroBarbare.Show();

    Dagger * Arolde_dagger = new Dagger();
    Sword Arolde_Sword = Sword(5);
    Nordic * Arolde = new Nordic(Arolde_Sword, 20, 5, 15, 25, "PyroBarbare", Arolde_dagger);

    // Test Wizard class
    Staff GandoulfLeRose_staff = Staff(5);
    Dagger * GandoulfLeRose_dagger = new Dagger();
    Wizard * GandoulfLeRose = new Wizard(GandoulfLeRose_staff, 5, 15, 25, 10, "Gandoulf le Rose", GandoulfLeRose_dagger);
    //GandoulfLeRose.CastSpell();
    //GandoulfLeRose.Show();

    // Test Necromancer class
    Staff MolagBal_staff = Staff(5);
    Dagger * MolagBal_dagger = new Dagger();
    Necromancer * MolagBal = new Necromancer(MolagBal_staff, 5, 15, 25, 10, "Molag Bal", MolagBal_dagger);
    //MolagBal.RiseUndeads();
    //MolagBal.CastSpell();
    //MolagBal.Show();

    // Étape 10 (Polymorphisme) - Équipe de Heroes
    std::list<Hero*> ThePensionTeam;
    ThePensionTeam.push_back(PyroBarbare);
    ThePensionTeam.push_back(Arolde);
    ThePensionTeam.push_back(GandoulfLeRose);
    ThePensionTeam.push_back(MolagBal);

    std::for_each(ThePensionTeam.begin(), ThePensionTeam.end(),[](Hero *h)
    {
        h->Show();
        std::cout << std::endl;
    });

    return 0;
}
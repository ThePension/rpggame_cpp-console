/*
* Auteur      : Aubert Nicolas
* Date        : 15.03.2021
* Contexte    : Langage c++ : Projet fil rouge
* Description : Jeu RPG
*/
#include <iostream>
#include "Hero/Type/Nordic.h"
#include "Weapons/Type/Dagger.h"
using namespace std;
using namespace He_Arc::RPG;

int main(int argc, char const *argv[])
{
    Dagger * _dagger = new Dagger();
    Sword PyroBarbareSword = Sword(5);
    Nordic PyroBarbare = Nordic(PyroBarbareSword, 20, 5, 15, 25, "PyroBarbare", _dagger);
    PyroBarbare.Show();
    return 0;
}
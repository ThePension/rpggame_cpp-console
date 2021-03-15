/*
* Auteur      : Aubert Nicolas
* Date        : 15.03.2021
* Contexte    : Langage c++ : Projet fil rouge
* Description : Jeu RPG
*/
#include <iostream>
#include "Hero.h"
using namespace std;
using namespace He_Arc::RPG;

int main(int argc, char const *argv[])
{
    Hero Bobby = Hero(4, 5, 11, 20, "Bobby");
    Hero Mamie = Hero(6, 3, 7, 50, "Mamie");
    Bobby.Show();
    Mamie.Show();
    Bobby.Interact(Mamie);
    return 0;
}
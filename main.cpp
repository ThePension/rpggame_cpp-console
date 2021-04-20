/*
* Auteur      : Aubert Nicolas
* Date        : 15.03.2021
* Contexte    : Langage c++ : Projet fil rouge
* Description : Jeu RPG
*/
#include <iostream>
#include <list>
#include <conio.h>
#include <algorithm>
#include <windows.h>
#include "Hero/Type/Nordic.h"
#include "Hero/Type/Wizard.h"
#include "Hero/Type/Necromancer.h"
#include "Weapons/Type/Dagger.h"
#include "Weapons/Type/Staff.h"
#include "Map/Room.h"
using namespace std;
using namespace He_Arc::RPG;
void GotoXY( int x, int y)
{
   COORD coord;
   coord.X = x;
   coord.Y = y;
   SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
  
int main(int argc, char const *argv[])
{
    // Test Nordic class
    /*Dagger * PyroBarbareSword_dagger = new Dagger();
    Sword PyroBarbareSword = Sword(5);
    Nordic * PyroBarbare = new Nordic(PyroBarbareSword, 20, 5, 15, 25, "PyroBarbare", PyroBarbareSword_dagger);

    Dagger * Arolde_dagger = new Dagger();
    Sword Arolde_Sword = Sword(5);
    Nordic * Arolde = new Nordic(Arolde_Sword, 20, 5, 15, 25, "PyroBarbare", Arolde_dagger);

    // Test Wizard class
    Staff GandoulfLeRose_staff = Staff(5);
    Dagger * GandoulfLeRose_dagger = new Dagger();
    Wizard * GandoulfLeRose = new Wizard(GandoulfLeRose_staff, 5, 15, 25, 10, "Gandoulf le Rose", GandoulfLeRose_dagger);

    // Test Necromancer class
    Staff MolagBal_staff = Staff(5);
    Dagger * MolagBal_dagger = new Dagger();
    Necromancer * MolagBal = new Necromancer(MolagBal_staff, 5, 15, 25, 10, "Molag Bal", MolagBal_dagger);

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
    });*/

    // Resize console windows
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 500, 220, TRUE);

    

    Room Room1 = Room();
    
    Room1.Display();
    while(true){
        char key;
        GotoXY(25, 1);
        cout << "Key help : h" << endl;
        key = _getwch();
        switch(key){
            case 'w': // Déplacement du joueur
            case 'a':
            case 's':
            case 'd':
                Room1.Update(key);
                Room1.Display();
                break;
            case '$': // Afficher les stats du joueur
                Room1.ShowPlayerStats();
                _getwch();
                Room1.Display();
                break;
            case 'h':
                Room1.KeyHelp();
                _getwch();
                Room1.Display();
                break;
        }
    }
    // _getwch();
    return 0;
}


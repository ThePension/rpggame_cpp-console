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
            case 'q': // Exit the game
                /*system("cls");
                cout << "You're about to exit the game. Are you sure ? (y/n)" << endl;
                std::string confirmation;
                cin >> confirmation;
                if(confirmation != "n")*/ exit(0);
                break;
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
            case 'h': // Afficher de l'aide sur les commandes
                Room1.KeyHelp();
                _getwch();
                Room1.Display();
                break;
            case 'i': // Afficher l'inventaire du joueur
                Room1.ShowPlayerInventory();
                _getwch();
                Room1.Display();
                break;
            case 'f': // Intéragir avec l'objet aux alentours
                int pPosX = Room1.GetPlayer()->GetX(); // Retourne les Y !
                int pPosY = Room1.GetPlayer()->GetY(); // Retourne les X !
                RoomObject * ro = Room1.CheckAround(pPosY, pPosX);
                if(ro != nullptr){ // Si l'objet n'est pas nul
                    Hero * h = Room1.GetPlayer();
                    h->Interact(ro);
                    Room1.Display(); // Rafraichir l'affichage
                    Room1.CheckAround(pPosY, pPosX);
                }
                break;
        }
    }
    // _getwch();
    return 0;
}


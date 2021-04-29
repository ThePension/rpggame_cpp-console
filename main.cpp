/*
* Auteur      : Aubert Nicolas
* Date        : 15.03.2021
* Contexte    : Langage c++ : Projet fil rouge
* Description : Jeu RPG
*/
#include <iostream>
#include <list>
#include <iterator>
#include <conio.h>
#include <algorithm>
#include <windows.h>
#include "Hero/Type/Nordic.h"
#include "Hero/Type/Wizard.h"
#include "Hero/Type/Necromancer.h"
#include "Weapons/Type/Dagger.h"
#include "Weapons/Type/Staff.h"
#include "Inventory/Inventory.h"
#include "Map/Room.h"
#include "Map/RoomObjects/Objects/Chest.h"
#include "Items/Items/Gold.h"
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
    MoveWindow(console, r.left, r.top, 500, 250, true);
    Room Room1 = Room();
    
    Room1.Display();
    
    bool IsInventoryDisplayed = false;
    GotoXY(25, 1);
    cout << "Key help : h" << endl;
    int InventoryIndex = 0;
    while(true){
        if(GetAsyncKeyState(0x48)){ // H - Afficher l'aide pour les touches
            Room1.KeyHelp();
        }else if(GetAsyncKeyState(0x57)){ // W - Déplacement vers le haut
            Room1.Update('w');
            Room1.Display();
        } else if (GetAsyncKeyState(0x41)){ // A - Déplacement vers la gauche
            Room1.Update('a');
            Room1.Display();
        } else if (GetAsyncKeyState(0x53)){ // S - Déplacement vers le bas
            Room1.Update('s');
            Room1.Display();
        } else if (GetAsyncKeyState(0x44)){ // D - Déplacement vers la droite
            Room1.Update('d');
            Room1.Display();
        }else if (GetAsyncKeyState(VK_OEM_COMMA)){ // , - Afficher les stats du joueur
            system("cls");
            Room1.Display();
            Room1.GetPlayer()->Show(0, 25);
        } else if(GetAsyncKeyState(VK_TAB)){ // TAB - Afficher l'inventaire du joueur
            InventoryIndex = 0;
            bool NoQuitInventory = true;
            system("cls");
            Room1.Display();
            Room1.GetPlayer()->GetInventory()->Show("Your inventory", InventoryIndex, 2, 25);
            do { // Navigation dans l'inventaire
                system("pause>nul");
                if(Room1.GetPlayer()->GetInventory()->GetContent().size() != 0){ // Si l'inventaire est vide
                    if(GetAsyncKeyState(0x57)){ // W - Déplacement vers le haut
                        if (InventoryIndex == 0) InventoryIndex = Room1.GetPlayer()->GetInventory()->GetContent().size() - 1;
                        else InventoryIndex--;
                        system("cls");
                        Room1.Display();
                        Room1.GetPlayer()->GetInventory()->Show("Your inventory", InventoryIndex, 2, 25);
                    }else if(GetAsyncKeyState(0x53)){ // S - Déplacement vers le bas
                        if (InventoryIndex == Room1.GetPlayer()->GetInventory()->GetContent().size() - 1) InventoryIndex=0;
                        else InventoryIndex++;
                        system("cls");
                        Room1.Display();
                        Room1.GetPlayer()->GetInventory()->Show("Your inventory", InventoryIndex, 2, 25);
                    }else if(GetAsyncKeyState(0x46)){ // F - Interact
                        IItem * i = Room1.GetPlayer()->GetInventory()->GetInventoryItemAtIndex(InventoryIndex);
                        Room1.GetPlayer()->Interact(i);
                        system("cls");
                        Room1.Display();
                        Room1.GetPlayer()->GetInventory()->Show("Your inventory", InventoryIndex, 2, 25);
                    }else if(GetAsyncKeyState(0x51)){ // Q - Drop Item
                        RoomObject * ro = Room1.CheckAround(Room1.GetPlayer()->GetY(), Room1.GetPlayer()->GetX());
                        if(ro != nullptr && typeid(*ro).name() == typeid(Chest).name()){ // If there is a chest next to the player
                            IItem * i = Room1.GetPlayer()->GetInventory()->GetInventoryItemAtIndex(InventoryIndex); // Objet sélectionné
                            Room1.GetPlayer()->GetInventory()->GetContent().remove(i); // Supprimer l'objet de l'inventaire
                            ro->GetInventory()->AddItem(i); // Ajouter l'objet dans l'inventaire du coffre
                            system("cls");
                            Room1.Display();
                            Room1.GetPlayer()->GetInventory()->Show("Your inventory", InventoryIndex, 2, 25);
                        }
                    }
                }
                if(GetAsyncKeyState(VK_TAB)){ // TAB - Quitter l'inventaire
                    NoQuitInventory = false;
                    system("cls");
                    Room1.Display();
                }
            } while(NoQuitInventory);
        } // Fin de l'inventaire
        else if(GetAsyncKeyState(0x46)){ // F - Intéraction avec les objets dans la carte
            int y = Room1.GetPlayer()->GetX();
            int x = Room1.GetPlayer()->GetY();
            RoomObject * ro = Room1.CheckAround(x, y);
            if(ro != nullptr && typeid(*ro).name() == typeid(Chest).name()){ // Si l'objet est un coffre
                InventoryIndex = 0;
                bool NoQuitInventory = true;
                system("cls");
                Room1.Display();
                ro->GetInventory()->Show("Chest", InventoryIndex, 2, 25);
                do { // Navigation dans l'inventaire
                    system("pause>nul");
                    if(GetAsyncKeyState(0x57)){ // W
                        if (InventoryIndex == 0) InventoryIndex = ro->GetInventory()->GetContent().size() - 1;
                        else InventoryIndex--;
                        system("cls");
                        Room1.Display();
                        ro->GetInventory()->Show("Chest", InventoryIndex, 2, 25);
                    }else if(GetAsyncKeyState(0x53)){ // S
                        if (InventoryIndex == ro->GetInventory()->GetContent().size() - 1) InventoryIndex = 0;
                        else InventoryIndex++;
                        system("cls");
                        Room1.Display();
                        ro->GetInventory()->Show("Chest", InventoryIndex, 2, 25);
                    }else if (GetAsyncKeyState(VK_LCONTROL) && GetAsyncKeyState(0x46)){ // CTRL + F - Take all
                        Room1.GetPlayer()->Interact(ro);
                        system("cls");
                        Room1.Display();
                        ro->GetInventory()->Show("Chest", InventoryIndex, 2, 25);
                    }else if(GetAsyncKeyState(0x46)){ // F - Intéragir avec l'Item
                        IItem * i = ro->GetInventory()->GetInventoryItemAtIndex(InventoryIndex);
                        if(i != nullptr){
                            ro->GetInventory()->GetContent().remove(i);
                            if(typeid(*i).name() == typeid(Gold).name()){
                                Gold * g = (Gold *)i;
                                Room1.GetPlayer()->AddGold(g->GetGoldAmount());
                                delete g;
                                g = nullptr;
                            }else{
                                Room1.GetPlayer()->GetInventory()->AddItem(i);
                            }
                            InventoryIndex = 0;
                            system("cls");
                            Room1.Display();
                            ro->GetInventory()->Show("Chest", InventoryIndex, 2, 25);
                        }
                    }else if(GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState(VK_TAB)){ // ESCAPE ou TAB - Quitter l'inventaire du coffre
                        NoQuitInventory = false;
                        system("cls");
                        Room1.Display();
                    }
                } while(NoQuitInventory);
            }
        }
        system("pause>nul");
    }
    return 0;
}
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
#include <excpt.h>
#include <windows.h>
#include "Hero/Type/Nordic.h"
#include "Hero/Type/Wizard.h"
#include "Hero/Merchant.h"
#include "Hero/Type/Necromancer.h"
#include "Weapons/Type/Dagger.h"
#include "Weapons/Type/Staff.h"
#include "Inventory/Inventory.h"
#include "Map/Room.h"
#include "Log/Log.h"
#include "Map/RoomObjects/Objects/Chest.h"
#include "Items/Items/Gold.h"
#include "TradingSystem/TradingSystem.h"
using namespace std;
using namespace He_Arc::RPG;
void GotoXY( int x, int y)
{
   COORD coord;
   coord.X = x;
   coord.Y = y;
   SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void DrawVertLine(int x, int length){
    for(int i = 0; i < length; i++){
        GotoXY(x, i);
        cout << "|" << endl;
    }
}
int main(int argc, char const *argv[]) 
{
    // Resize console windows
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 500, 250, true);

    // Initialize components
    Room Room1 = Room();
    Log log = Log();
    TradingSystem _TradingSystem = TradingSystem();

    Room1.Display();
    bool IsInventoryDisplayed = false;
    GotoXY(25, 1);
    cout << "Key help : h" << endl;
    int InventoryIndex = 0;
    
    while(true){
        #pragma region Déplacements
        if(GetAsyncKeyState(0x57)){ // W - Move to the top
            Room1.Update('w');
            Room1.Display();
        } else if (GetAsyncKeyState(0x41)){ // A - Move to the left
            Room1.Update('a');
            Room1.Display();
        } else if (GetAsyncKeyState(0x53)){ // S - Move to the bottom
            Room1.Update('s');
            Room1.Display();
        } else if (GetAsyncKeyState(0x44)){ // D - Move to the right
            Room1.Update('d');
            Room1.Display();
        }else if (GetAsyncKeyState(VK_OEM_COMMA)){ // , - Show players stats
            system("cls");
            Room1.Display();
            Room1.GetPlayer()->Show(0, 25);
        }else if (GetAsyncKeyState(0x51)){ // Q - Quit the game
            exit(0);
            break;
        }else if (GetAsyncKeyState(0x48)){ // H - Show keys help
            Room1.KeyHelp();
        }
        #pragma endregion comment
        #pragma region Inventaire joueur
        else if(GetAsyncKeyState(VK_TAB)){ // TAB - Display player's inventory
            InventoryIndex = 0;
            bool NoQuitInventory = true;
            system("cls");
            Room1.Display();
            Room1.GetPlayer()->GetInventory()->Show("Your inventory", InventoryIndex, 2, 25);
            do { // Player's inventory's navigation
                system("pause>nul");
                if(Room1.GetPlayer()->GetInventory()->GetContent().size() != 0){ // If inventory is empty
                    if(GetAsyncKeyState(0x57)){ // W - Move to the top
                        if (InventoryIndex == 0) InventoryIndex = Room1.GetPlayer()->GetInventory()->GetContent().size() - 1;
                        else InventoryIndex--;
                        system("cls");
                        Room1.Display();
                        Room1.GetPlayer()->GetInventory()->Show("Your inventory", InventoryIndex, 2, 25);
                    }else if(GetAsyncKeyState(0x53)){ // S - Move to the bottom
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
                            IItem * i = Room1.GetPlayer()->GetInventory()->GetInventoryItemAtIndex(InventoryIndex); // Selected Item
                            Room1.GetPlayer()->GetInventory()->GetContent().remove(i); // Delete Item in inventory
                            ro->GetInventory()->AddItem(i); // Add Item in chest inventory
                            system("cls");
                            Room1.Display();
                            Room1.GetPlayer()->GetInventory()->Show("Your inventory", InventoryIndex, 2, 25);
                        }
                    }
                }
                if(GetAsyncKeyState(VK_TAB)){ // TAB - Quit inventory
                    NoQuitInventory = false;
                    system("cls");
                    Room1.Display();
                }
            } while(NoQuitInventory);
        } // End of inventory
        #pragma endregion
        #pragma region Intéractions avec la carte
        else if(GetAsyncKeyState(0x46)){ // F - Interactions with map objects
            int y = Room1.GetPlayer()->GetX();
            int x = Room1.GetPlayer()->GetY();
            RoomObject * ro = Room1.CheckAround(x, y);
            if(ro != nullptr && typeid(*ro).name() == typeid(Chest).name()){ // If Object is a chest
                
                InventoryIndex = 0;
                bool NoQuitInventory = true;
                system("cls");
                Room1.Display();
                ro->GetInventory()->Show("Chest", InventoryIndex, 2, 25);
                do { // Inventory navigation
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
                        //try {
                            Room1.GetPlayer()->Interact(ro);
                            system("cls");
                            Room1.Display();
                            ro->GetInventory()->Show("Chest", InventoryIndex, 2, 25);
                       /* } catch(exception e){
                            log.ErrorLog(e);
                        } catch (...) {
                            log.ErrorLog("Unknown error");
                        }*/
                    }else if(GetAsyncKeyState(0x46)){ // F - Interact with item
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
                    }else if(GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState(VK_TAB)){ // ESCAPE or TAB - Quit chest inventory
                        NoQuitInventory = false;
                        system("cls");
                        Room1.Display();
                    }
                } while(NoQuitInventory);
            }
            else if(ro != nullptr && typeid(*ro).name() == typeid(Merchant).name()) { // If object is merchant
                Merchant * m = dynamic_cast<Merchant*>(ro);
                
                GetWindowRect(console, &r);
                MoveWindow(console, r.left, r.top, 750, 250, true);
                // Trading System
                _TradingSystem.Init(m, Room1);
                system("cls");
                GetWindowRect(console, &r);
                MoveWindow(console, r.left, r.top, 500, 250, true);
                Room1.Display();
            } else if(ro != nullptr && typeid(*ro).name() == typeid(Hero).name()) { // If object is a Hero
                // Combat system (to do)

                // Trading system
                Hero * h = dynamic_cast<Hero*>(ro);
                 GetWindowRect(console, &r);
                MoveWindow(console, r.left, r.top, 750, 250, true);
                // Trading System
                _TradingSystem.Init(h, Room1);
                system("cls");
                GetWindowRect(console, &r);
                MoveWindow(console, r.left, r.top, 500, 250, true);
                Room1.Display();
            }
        }
        #pragma endregion
        system("pause>nul");
    }
    return 0;
}
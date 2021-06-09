#include <fstream>
#include <windows.h>
#include "../Log/Log.h"
#include "TradingSystem.h"
using namespace std;
namespace He_Arc::RPG
{
    TradingSystem::TradingSystem(){}
    void TradingSystem::Init(Merchant * m, Room & room){
        Log log;
        int InventoryPlayerIndex = -1, InventoryMerchantIndex = -1;
        if(room.GetPlayer()->GetInventory()->GetContent().size() > 0){
            InventoryPlayerIndex = 0;
            InventoryMerchantIndex = -1;
        }else if(m->GetInventory()->GetContent().size() > 0){
            InventoryPlayerIndex = -1;
            InventoryMerchantIndex = 0;
        }
        bool NoQuitInventory = true;
        system("cls");
        room.Display();
        DrawVertLine(50, 10);
        DrawVertLine(62, 10);
        GotoXY(30, 2);
        cout << room.GetPlayer()->GetGold() << " Golds" << endl;
        GotoXY(70, 2);
        cout << m->GetGold() << " Golds" << endl;
        room.GetPlayer()->GetInventory()->Show("Your inventory", InventoryPlayerIndex, 3, 25);
        m->GetInventory()->Show("Merchant", InventoryMerchantIndex, 3, 65);
        GotoXY(53, 2);
        if(InventoryPlayerIndex == -1 && m->GetInventory()->GetContent().size() != 0) cout << m->GetInventory()->GetInventoryItemAtIndex(InventoryMerchantIndex)->GetPrice() << " Golds";
        else if(room.GetPlayer()->GetInventory()->GetContent().size() != 0) cout << room.GetPlayer()->GetInventory()->GetInventoryItemAtIndex(InventoryPlayerIndex)->GetPrice() << " Golds";
        do { // Inventories navigation
            system("pause>nul");
            if(GetAsyncKeyState(0x57)){ // W
                if(InventoryPlayerIndex == -1){
                    if (InventoryMerchantIndex == 0) InventoryMerchantIndex = m->GetInventory()->GetContent().size() - 1;
                    else InventoryMerchantIndex--;
                }else{
                    if (InventoryPlayerIndex == 0) InventoryPlayerIndex = room.GetPlayer()->GetInventory()->GetContent().size() - 1;
                    else InventoryPlayerIndex--;
                }
            }else if(GetAsyncKeyState(0x53)){ // S
                if(InventoryPlayerIndex == -1){
                    if (InventoryMerchantIndex == m->GetInventory()->GetContent().size() - 1) InventoryMerchantIndex = 0;
                    else InventoryMerchantIndex++;
                }else{
                    if (InventoryPlayerIndex == room.GetPlayer()->GetInventory()->GetContent().size() - 1) InventoryPlayerIndex = 0;
                    else InventoryPlayerIndex++;
                }
            }else if (GetAsyncKeyState(0x41)){ // A - Move to the left
                if(room.GetPlayer()->GetInventory()->GetContent().size() > 0) {
                    InventoryMerchantIndex = -1;
                    InventoryPlayerIndex = 0;
                }
            } if (GetAsyncKeyState(0x44)){ // D - Move to the right
                if(m->GetInventory()->GetContent().size() > 0) {
                    InventoryMerchantIndex = 0;
                    InventoryPlayerIndex = -1;
                }
            } else if(GetAsyncKeyState(0x46)){ // F - Interact with selected item
                IItem * i;
                if(InventoryPlayerIndex == -1 && m->GetInventory()->GetContent().size() != 0) {
                    i = m->GetInventory()->GetInventoryItemAtIndex(InventoryMerchantIndex);
                    if(room.GetPlayer()->GetGold() >= i->GetPrice() && room.GetPlayer()->GetInventory()->GetContent().size() < 10){ // Si le joueur a assez de gold et assez de place libre dans son inventaire
                        // Log
                        log.TradeLog(m, i, room.GetPlayer());
                        // Trade
                        room.GetPlayer()->AddGold(-i->GetPrice());
                        room.GetPlayer()->GetInventory()->AddItem(i);
                        m->AddGold(i->GetPrice());
                        m->GetInventory()->GetContent().remove(i);
                        InventoryPlayerIndex = 0;
                        InventoryMerchantIndex = -1;
                        
                    }
                }
                else if(room.GetPlayer()->GetInventory()->GetContent().size() != 0) {
                    i = room.GetPlayer()->GetInventory()->GetInventoryItemAtIndex(InventoryPlayerIndex);
                    if(m->GetGold() >= i->GetPrice() && m->GetInventory()->GetContent().size() < 10){ // If merchant a enough gold/places
                        // Log
                        log.TradeLog(room.GetPlayer(), i, m);
                        // Trade
                        room.GetPlayer()->AddGold(i->GetPrice());
                        room.GetPlayer()->GetInventory()->GetContent().remove(i);
                        m->AddGold(-i->GetPrice());
                        m->GetInventory()->AddItem(i);
                        InventoryPlayerIndex = -1;
                        InventoryMerchantIndex = 0;
                    }
                }
            }else if(GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState(VK_TAB)){ // ESCAPE or TAB - Quit trading system
                NoQuitInventory = false;
            }
            // Display
            system("cls");
            room.Display();
            DrawVertLine(50, 10);
            DrawVertLine(62, 10);
            GotoXY(30, 2);
            cout << room.GetPlayer()->GetGold() << " Golds" << endl;
            GotoXY(70, 2);
            cout << m->GetGold() << " Golds" << endl;
            room.GetPlayer()->GetInventory()->Show("Your inventory", InventoryPlayerIndex, 3, 25);
            m->GetInventory()->Show("Merchant", InventoryMerchantIndex, 3, 65);
            GotoXY(53, 2);
            if(InventoryPlayerIndex == -1 && m->GetInventory()->GetContent().size() != 0) cout << m->GetInventory()->GetInventoryItemAtIndex(InventoryMerchantIndex)->GetPrice() << " Golds";
            else if(room.GetPlayer()->GetInventory()->GetContent().size() != 0) cout << room.GetPlayer()->GetInventory()->GetInventoryItemAtIndex(InventoryPlayerIndex)->GetPrice() << " Golds";
        } while(NoQuitInventory);
    }
    void TradingSystem::Init(Hero * h, Room & room){
        Log log;
        int InventoryPlayerIndex = -1, InventoryMerchantIndex = -1;
        if(room.GetPlayer()->GetInventory()->GetContent().size() > 0){
            InventoryPlayerIndex = 0;
            InventoryMerchantIndex = -1;
        }else if(h->GetInventory()->GetContent().size() > 0){
            InventoryPlayerIndex = -1;
            InventoryMerchantIndex = 0;
        }
        bool NoQuitInventory = true;
        system("cls");
        room.Display();
        DrawVertLine(50, 10);
        DrawVertLine(62, 10);
        GotoXY(30, 2);
        cout << room.GetPlayer()->GetGold() << " Golds" << endl;
        GotoXY(70, 2);
        cout << h->GetGold() << " Golds" << endl;
        room.GetPlayer()->GetInventory()->Show("Your inventory", InventoryPlayerIndex, 3, 25);
        h->GetInventory()->Show("Merchant", InventoryMerchantIndex, 3, 65);
        GotoXY(53, 2);
        if(InventoryPlayerIndex == -1 && h->GetInventory()->GetContent().size() != 0) cout << h->GetInventory()->GetInventoryItemAtIndex(InventoryMerchantIndex)->GetPrice() << " Golds";
        else if(room.GetPlayer()->GetInventory()->GetContent().size() != 0) cout << room.GetPlayer()->GetInventory()->GetInventoryItemAtIndex(InventoryPlayerIndex)->GetPrice() << " Golds";
        do { // Inventories navigation
            system("pause>nul");
            if(GetAsyncKeyState(0x57)){ // W
                if(InventoryPlayerIndex == -1){
                    if (InventoryMerchantIndex == 0) InventoryMerchantIndex = h->GetInventory()->GetContent().size() - 1;
                    else InventoryMerchantIndex--;
                }else{
                    if (InventoryPlayerIndex == 0) InventoryPlayerIndex = room.GetPlayer()->GetInventory()->GetContent().size() - 1;
                    else InventoryPlayerIndex--;
                }
            }else if(GetAsyncKeyState(0x53)){ // S
                if(InventoryPlayerIndex == -1){
                    if (InventoryMerchantIndex == h->GetInventory()->GetContent().size() - 1) InventoryMerchantIndex = 0;
                    else InventoryMerchantIndex++;
                }else{
                    if (InventoryPlayerIndex == room.GetPlayer()->GetInventory()->GetContent().size() - 1) InventoryPlayerIndex = 0;
                    else InventoryPlayerIndex++;
                }
            }else if (GetAsyncKeyState(0x41)){ // A - Move to the left
                if(room.GetPlayer()->GetInventory()->GetContent().size() > 0) {
                    InventoryMerchantIndex = -1;
                    InventoryPlayerIndex = 0;
                }
            } if (GetAsyncKeyState(0x44)){ // D - Move to the right
                if(h->GetInventory()->GetContent().size() > 0) {
                    InventoryMerchantIndex = 0;
                    InventoryPlayerIndex = -1;
                }
            } else if(GetAsyncKeyState(0x46)){ // F - Interact with selected item
                IItem * i;
                if(InventoryPlayerIndex == -1 && h->GetInventory()->GetContent().size() != 0) {
                    i = h->GetInventory()->GetInventoryItemAtIndex(InventoryMerchantIndex);
                    if(room.GetPlayer()->GetGold() >= i->GetPrice() && room.GetPlayer()->GetInventory()->GetContent().size() < 10){ // Si le joueur a assez de gold et assez de place libre dans son inventaire
                        // Log
                        log.TradeLog(h, i, room.GetPlayer());
                        // Trade
                        room.GetPlayer()->AddGold(-i->GetPrice());
                        room.GetPlayer()->GetInventory()->AddItem(i);
                        h->AddGold(i->GetPrice());
                        h->GetInventory()->GetContent().remove(i);
                        InventoryPlayerIndex = 0;
                        InventoryMerchantIndex = -1;
                    }
                }
                else if(room.GetPlayer()->GetInventory()->GetContent().size() != 0) {
                    i = room.GetPlayer()->GetInventory()->GetInventoryItemAtIndex(InventoryPlayerIndex);
                    if(h->GetGold() >= i->GetPrice() && h->GetInventory()->GetContent().size() < 10){ // If merchant a enough gold/places
                        // Log
                        log.TradeLog(room.GetPlayer(), i, h);
                        // Trade
                        room.GetPlayer()->AddGold(i->GetPrice());
                        room.GetPlayer()->GetInventory()->GetContent().remove(i);
                        h->AddGold(-i->GetPrice());
                        h->GetInventory()->AddItem(i);
                        InventoryPlayerIndex = -1;
                        InventoryMerchantIndex = 0;
                    }
                }
            }else if(GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState(VK_TAB)){ // ESCAPE or TAB - Quit trading system
                NoQuitInventory = false;
            }
            // Display
            system("cls");
            room.Display();
            DrawVertLine(50, 10);
            DrawVertLine(62, 10);
            GotoXY(30, 2);
            cout << room.GetPlayer()->GetGold() << " Golds" << endl;
            GotoXY(70, 2);
            cout << h->GetGold() << " Golds" << endl;
            room.GetPlayer()->GetInventory()->Show("Your inventory", InventoryPlayerIndex, 3, 25);
            h->GetInventory()->Show("Merchant", InventoryMerchantIndex, 3, 65);
            GotoXY(53, 2);
            if(InventoryPlayerIndex == -1 && h->GetInventory()->GetContent().size() != 0) cout << h->GetInventory()->GetInventoryItemAtIndex(InventoryMerchantIndex)->GetPrice() << " Golds";
            else if(room.GetPlayer()->GetInventory()->GetContent().size() != 0) cout << room.GetPlayer()->GetInventory()->GetInventoryItemAtIndex(InventoryPlayerIndex)->GetPrice() << " Golds";
        } while(NoQuitInventory);
    }
    void TradingSystem::GotoXY( int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord );
    }
    void TradingSystem::DrawVertLine(int x, int length){
        for(int i = 0; i < length; i++){
            GotoXY(x, i);
            cout << "|" << endl;
        }
    }
}
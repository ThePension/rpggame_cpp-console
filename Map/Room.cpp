#include <windows.h>
#include <stdlib.h>
#include "Room.h"
#include "RoomObjects/RoomObject.h"
#include "RoomObjects/Objects/Chest.h"
#include "RoomObjects/Objects/Wall.h"
#include "../Hero/Hero.h"
#include "../Hero/Type/Nordic.h"
#include "../Weapons/Type/Sword.h"
#include "../Weapons/Type/Staff.h"
#include "../Items/Items/Potion.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Room::Room() {
        // Hero
        Nordic * PyroBarbare = new Nordic(2,3,'X', 20, 5, 15, 25, "PyroBarbare");
        this->Player = PyroBarbare;
        // Chest 1
        Potion * _potion = new Potion(5, "Small potion", false);
        Potion * _potion2 = new Potion(10, "Medium potion", false);
        Sword * PyroBarbareSword = new Sword(5, "PyroBarbareSword");
        Chest * _chest = new Chest(9,3,'C');
        _chest->GetInventory()->AddItem(_potion2);
        _chest->GetInventory()->AddItem(_potion);
        _chest->GetInventory()->AddItem(PyroBarbareSword);

        // Chest 2
        Staff * _GreekStaff = new Staff(10, "Greek Staff");
        Potion * _potion3 = new Potion(15, "Large potion", false);
        Potion * _potion4 = new Potion(10, "Medium potion", false);
        Chest * _chest2 = new Chest(1,8,'C');
        _chest2->GetInventory()->AddItem(_potion3);
        _chest2->GetInventory()->AddItem(_potion4);
        _chest2->GetInventory()->AddItem(_GreekStaff);
        
        // Création d'un tableau temporaire, contenant le pattern de la pièce
        RoomObject * _pattern[Heigth][Width] = {
            { new Wall(0,0,' '), new Wall(1,0,'_'), new Wall(2,0,'_'), new Wall(3,0,'_'), new Wall(4,0,'_'), new Wall(5,0,'_'), new Wall(6,0,'_'), new Wall(7,0,'_'), new Wall(8,0,'_'), new Wall(9,0,'_'), new Wall(10,0,'_'), new Wall(11,0,'_'), new Wall(12,0,'_'), new Wall(13,0,'_'), new Wall(14,0,'_'), new Wall(15,0,'_'), new Wall(16,0,'_'), new Wall(17,0,'_'), new Wall(18,0,'_'), new Wall(19,0,' ')},
            { new Wall(0,1,'|'), new Wall(1,1,' '), new Wall(2,1,' '), new Wall(3,1,' '), new Wall(4,1,' '), new Wall(5,1,' '), new Wall(6,1,' '), new Wall(7,1,' '), new Wall(8,1,' '), new Wall(9,1,' '), new Wall(10,1,' '), new Wall(11,1,' '), new Wall(12,1,' '), new Wall(13,1,' '), new Wall(14,1,' '), new Wall(15,1,' '), new Wall(16,1,' '), new Wall(17,1,' '), new Wall(18,1,' '), new Wall(19,1,'|')},
            { new Wall(0,2,'|'), new Wall(1,2,' '), new Wall(2,2,' '), new Wall(3,2,' '), new Wall(4,2,' '), new Wall(5,2,' '), new Wall(6,2,' '), new Wall(7,2,' '), new Wall(8,2,' '), new Wall(9,2,' '), new Wall(10,2,' '), new Wall(11,2,' '), new Wall(12,2,' '), new Wall(13,2,' '), new Wall(14,2,' '), new Wall(15,2,' '), new Wall(16,2,' '), new Wall(17,2,' '), new Wall(18,2,' '), new Wall(19,2,'|')},
            { new Wall(0,3,'|'), new Wall(1,3,' '), PyroBarbare  ,     new Wall(3,3,' '), new Wall(4,3,' '), new Wall(5,3,' '), new Wall(6,3,' '), new Wall(7,3,' '), new Wall(8,3,' '), _chest, new Wall(10,3,' '), new Wall(11,3,' '), new Wall(12,3,' '), new Wall(13,3,' '), new Wall(14,3,' '), new Wall(15,3,' '), new Wall(16,3,' '), new Wall(17,3,' '), new Wall(18,3,' '), new Wall(19,3,'|')},
            { new Wall(0,4,'|'), new Wall(1,4,'-'), new Wall(2,4,'-'), new Wall(3,4,'-'), new Wall(4,4,'-'), new Wall(5,4,'-'), new Wall(6,4,' '), new Wall(7,4,' '), new Wall(8,4,' '), new Wall(9,4,' '), new Wall(10,4,' '), new Wall(11,4,' '), new Wall(12,4,' '), new Wall(13,4,' '), new Wall(14,4,' '), new Wall(15,4,' '), new Wall(16,4,' '), new Wall(17,4,' '), new Wall(18,4,' '), new Wall(19,4,'|')},
            { new Wall(0,5,'|'), new Wall(1,5,' '), new Wall(2,5,' '), new Wall(3,5,' '), new Wall(4,5,' '), new Wall(5,5,' '), new Wall(6,5,' '), new Wall(7,5,' '), new Wall(8,5,' '), new Wall(9,5,' '), new Wall(10,5,' '), new Wall(11,5,' '), new Wall(12,5,' '), new Wall(13,5,' '), new Wall(14,5,' '), new Wall(15,5,' '), new Wall(16,5,' '), new Wall(17,5,' '), new Wall(18,5,' '), new Wall(19,5,'|')},
            { new Wall(0,6,'|'), new Wall(1,6,' '), new Wall(2,6,' '), new Wall(3,6,' '), new Wall(4,6,' '), new Wall(5,6,'|'), new Wall(6,6,' '), new Wall(7,6,' '), new Wall(8,6,' '), new Wall(9,6,' '), new Wall(10,6,' '), new Wall(11,6,' '), new Wall(12,6,' '), new Wall(13,6,' '), new Wall(14,6,' '), new Wall(15,6,' '), new Wall(16,6,' '), new Wall(17,6,' '), new Wall(18,6,' '), new Wall(19,6,'|')},
            { new Wall(0,7,'|'), new Wall(1,7,' '), new Wall(2,7,' '), new Wall(3,7,' '), new Wall(4,7,' '), new Wall(5,7,'|'), new Wall(6,7,' '), new Wall(7,7,' '), new Wall(8,7,' '), new Wall(9,7,' '), new Wall(10,7,' '), new Wall(11,7,' '), new Wall(12,7,' '), new Wall(13,7,' '), new Wall(14,7,' '), new Wall(15,7,' '), new Wall(16,7,' '), new Wall(17,7,' '), new Wall(18,7,' '), new Wall(19,7,'|')},
            { new Wall(0,8,'|'), _chest2,           new Wall(2,8,' '), new Wall(3,8,' '), new Wall(4,8,' '), new Wall(5,8,'|'), new Wall(6,8,' '), new Wall(7,8,' '), new Wall(8,8,' '), new Wall(9,8,' '), new Wall(10,8,' '), new Wall(11,8,' '), new Wall(12,8,' '), new Wall(13,8,' '), new Wall(14,8,' '), new Wall(15,8,' '), new Wall(16,8,' '), new Wall(17,8,' '), new Wall(18,8,' '), new Wall(19,8,'|')},
            {new Wall(0,9,'\\'), new Wall(1,9,'_'), new Wall(2,9,'_'), new Wall(3,9,'_'), new Wall(4,9,'_'), new Wall(5,9,'_'), new Wall(6,9,'_'), new Wall(7,9,'_'), new Wall(8,9,'_'), new Wall(9,9,'_'), new Wall(10,9,'_'), new Wall(11,9,'_'), new Wall(12,9,'_'), new Wall(13,9,'_'), new Wall(14,9,'_'), new Wall(15,9,'_'), new Wall(16,9,'_'), new Wall(17,9,'_'), new Wall(18,9,'_'), new Wall(19,9,'/')},
        };

        // Copie du tableau dans l'attribut
        for(int i = 0; i < Heigth; i++){
            for(int y = 0; y < Width; y++){
                switch(_pattern[i][y]->GetChar()){
                    case '|':
                    case '_':
                    case '-':
                    case '\\':
                    case ' ':
                    case '/':
                    case 'X':
                        this->ROPattern[i][y] = new Wall(_pattern[i][y]->GetX(),_pattern[i][y]->GetY(), _pattern[i][y]->GetChar());
                        break;
                    case 'C':
                        this->ROPattern[i][y] = _pattern[i][y];
                        // Chest(_pattern[i][y]->GetX(),_pattern[i][y]->GetY(), _pattern[i][y]->GetChar());
                        break;
                }
            }
        }
    }
    Room::~Room(){
        for(int i = 0; i < Heigth; i++){
            for(int y = 0; y < Width; y++){
                delete this->ROPattern[i][y];
                this->ROPattern[i][y] = nullptr;
            }
        }
        delete this->Player;
        this->Player = nullptr;
    }
    /*Room::Room(int Heigth, int Width, std::string Pattern[20][20]) {
        string _pattern[20][20] = Pattern;
        this->Pattern = &_pattern;
        this->Heigth = Heigth;
        this->Width = Width;
    }*/
    // Methods
    void Room::KeyHelp(){
        system("cls");
        cout << "Move player : w,a,s,d" << endl;
        cout << "Open inventory : i" << endl;
        cout << "Show player stats : $" << endl;
        cout << "Interact with object : f" << endl;
        cout << "Quit : q" << endl;
    }
    void Room::ShowPlayerInventory(){
        system("cls");
        this->Display();
        this->Player->ShowInventory(2, 25);
    }
    void Room::ShowPlayerStats(){
        system("cls");
        this->Display();
        this->Player->Show(0, 25);
    }
    // Permet d'afficher la pièce dans la console
    void Room::Display(){
        int playerX, playerY;
        system("cls"); // Clear the console
        for(int i = 0; i < Heigth; i++){
            for(int y = 0; y <  Width; y++){
                if(ROPattern[i][y]->GetChar() == 'X'){
                    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
                    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hstdout, 0x0C);
                    std::cout << ROPattern[i][y]->GetChar();
                    SetConsoleTextAttribute(hstdout, 0x0F);
                    FlushConsoleInputBuffer(hstdin);
                    // CheckAround(i,y);
                    playerX = i;
                    playerY = y;
                }else{
                    std::cout << ROPattern[i][y]->GetChar();
                }
                
            }
            std::cout << endl;
        }
        CheckAround(playerX,playerY);
    }
    // Permet de définir la position du curseur
    void Room::GotoXY(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    // Permet de mettre à jour la position du joueur en fonction de la touche pressée
    void Room::Update(char key) {
        for(int i = 0; i < this->Heigth; i++){
            for(int y = 0; y < this->Width; y++){
                if(this->ROPattern[i][y]->GetChar() == 'X'){
                    switch (key)
                    {
                        case 'w':
                            if(ROPattern[i-1][y]->GetChar() == ' ') {
                                this->ROPattern[i-1][y] = ROPattern[i][y];
                                this->Player->SetY(i-1);
                                this->ROPattern[i][y] = new Wall(i, y, ' ');
                            }
                            break;
                        case 's':
                            if(ROPattern[i+1][y]->GetChar() == ' ') {
                                this->ROPattern[i+1][y] = ROPattern[i][y];
                                this->Player->SetY(i+1);
                                this->ROPattern[i][y] = new Wall(i, y, ' ');
                            }
                            break;
                        case 'a':
                            if(ROPattern[i][y-1]->GetChar() == ' ') {
                                this->ROPattern[i][y-1] = ROPattern[i][y];
                                this->Player->SetX(y-1);
                                this->ROPattern[i][y] = new Wall(i, y, ' ');
                            }
                            break;
                        case 'd':
                             if(ROPattern[i][y+1]->GetChar() == ' ') {
                                this->ROPattern[i][y+1] = ROPattern[i][y];
                                this->Player->SetX(y+1);
                                int posx = this->Player->GetX(); // Debug
                                int poys = this->Player->GetY();
                                this->ROPattern[i][y] = new Wall(i, y, ' ');
                             }
                            break;
                    }
                    return;
                }
            }
        }
    }
    // Fonction permettant de contrôler ce qu'il y autour du joueur
    RoomObject * Room::CheckAround(int x, int y){
        int lineNb = 1;
        for(int i = x-1; i <= x+1; i++){
            for(int j = y-1; j <= y+1; j++){
                switch(ROPattern[i][j]->GetChar()){
                case 'C':
                    GotoXY(25,lineNb);
                    cout << "Chest : ";
                    lineNb++;
                    ROPattern[i][j]->GetInventory()->Show(lineNb, 25);
                    return ROPattern[i][j];
                    break;
                }
            }
        }
        return nullptr;
    }
}
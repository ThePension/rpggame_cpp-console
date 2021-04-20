#include <windows.h>
#include <stdlib.h>
#include "Room.h"
#include "RoomObjects/RoomObject.h"
#include "RoomObjects/Objects/Chest.h"
#include "RoomObjects/Objects/Wall.h"
#include "../Hero/Hero.h"
#include "../Hero/Type/Nordic.h"
#include "../Weapons/Type/Sword.h"
using namespace std;
namespace He_Arc::RPG
{
    // Constructors
    Room::Room() {

        Dagger * PyroBarbareSword_dagger = new Dagger();
        Sword PyroBarbareSword = Sword(5);
        Nordic * PyroBarbare = new Nordic(1,1,'X',PyroBarbareSword, 20, 5, 15, 25, "PyroBarbare", PyroBarbareSword_dagger);
        this->Player = PyroBarbare;
        // Création d'un tableau temporaire, contenant le pattern de la pièce
        RoomObject _pattern[Heigth][Width] = {
            { Wall(0,0,' '), Wall(1,0,'_'), Wall(2,0,'_'), Wall(3,0,'_'), Wall(4,0,'_'), Wall(5,0,'_'), Wall(6,0,'_'), Wall(7,0,'_'), Wall(8,0,'_'), Wall(9,0,'_'), Wall(10,0,'_'), Wall(11,0,'_'), Wall(12,0,'_'), Wall(13,0,'_'), Wall(14,0,'_'), Wall(15,0,'_'), Wall(16,0,'_'), Wall(17,0,'_'), Wall(18,0,'_'), Wall(19,0,' ')},
            { Wall(0,1,'|'), Wall(1,1,' '), Wall(2,1,' '), Wall(3,1,' '), Wall(4,1,' '), Wall(5,1,' '), Wall(6,1,' '), Wall(7,1,' '), Wall(8,1,' '), Wall(9,1,' '), Wall(10,1,' '), Wall(11,1,' '), Wall(12,1,' '), Wall(13,1,' '), Wall(14,1,' '), Wall(15,1,' '), Wall(16,1,' '), Wall(17,1,' '), Wall(18,1,' '), Wall(19,1,'|')},
            { Wall(0,2,'|'), Wall(1,2,' '), Wall(2,2,' '), Wall(3,2,' '), Wall(4,2,' '), Wall(5,2,' '), Wall(6,2,' '), Wall(7,2,' '), Wall(8,2,' '), Wall(9,2,' '), Wall(10,2,' '), Wall(11,2,' '), Wall(12,2,' '), Wall(13,2,' '), Wall(14,2,' '), Wall(15,2,' '), Wall(16,2,' '), Wall(17,2,' '), Wall(18,2,' '), Wall(19,2,'|')},
            { Wall(0,3,'|'), Wall(1,3,' '), *PyroBarbare  , Wall(3,3,' '), Wall(4,3,' '), Wall(5,3,' '), Wall(6,3,' '), Wall(7,3,' '), Wall(8,3,' '), Chest(9,3,'C'), Wall(10,3,' '), Wall(11,3,' '), Wall(12,3,' '), Wall(13,3,' '), Wall(14,3,' '), Wall(15,3,' '), Wall(16,3,' '), Wall(17,3,' '), Wall(18,3,' '), Wall(19,3,'|')},
            { Wall(0,4,'|'), Wall(1,4,' '), Wall(2,4,' '), Wall(3,4,' '), Wall(4,4,' '), Wall(5,4,' '), Wall(6,4,' '), Wall(7,4,' '), Wall(8,4,' '), Chest(9,4,'C'), Wall(10,4,' '), Wall(11,4,' '), Wall(12,4,' '), Wall(13,4,' '), Wall(14,4,' '), Wall(15,4,' '), Wall(16,4,' '), Wall(17,4,' '), Wall(18,4,' '), Wall(19,4,'|')},
            { Wall(0,5,'|'), Wall(1,5,' '), Wall(2,5,' '), Wall(3,5,' '), Wall(4,5,' '), Wall(5,5,' '), Wall(6,5,' '), Wall(7,5,' '), Wall(8,5,' '), Wall(9,5,' '), Wall(10,5,' '), Wall(11,5,' '), Wall(12,5,' '), Wall(13,5,' '), Wall(14,5,' '), Wall(15,5,' '), Wall(16,5,' '), Wall(17,5,' '), Wall(18,5,' '), Wall(19,5,'|')},
            { Wall(0,6,'|'), Wall(1,6,' '), Wall(2,6,' '), Wall(3,6,' '), Wall(4,6,' '), Wall(5,6,' '), Wall(6,6,' '), Wall(7,6,' '), Wall(8,6,' '), Wall(9,6,' '), Wall(10,6,' '), Wall(11,6,' '), Wall(12,6,' '), Wall(13,6,' '), Wall(14,6,' '), Wall(15,6,' '), Wall(16,6,' '), Wall(17,6,' '), Wall(18,6,' '), Wall(19,6,'|')},
            { Wall(0,7,'|'), Wall(1,7,' '), Wall(2,7,' '), Wall(3,7,' '), Wall(4,7,' '), Wall(5,7,' '), Wall(6,7,' '), Wall(7,7,' '), Wall(8,7,' '), Wall(9,7,' '), Wall(10,7,' '), Wall(11,7,' '), Wall(12,7,' '), Wall(13,7,' '), Wall(14,7,' '), Wall(15,7,' '), Wall(16,7,' '), Wall(17,7,' '), Wall(18,7,' '), Wall(19,7,'|')},
            { Wall(0,8,'|'), Wall(1,8,' '), Wall(2,8,' '), Wall(3,8,' '), Wall(4,8,' '), Wall(5,8,' '), Wall(6,8,' '), Wall(7,8,' '), Wall(8,8,' '), Wall(9,8,' '), Wall(10,8,' '), Wall(11,8,' '), Wall(12,8,' '), Wall(13,8,' '), Wall(14,8,' '), Wall(15,8,' '), Wall(16,8,' '), Wall(17,8,' '), Wall(18,8,' '), Wall(19,8,'|')},
            {Wall(0,9,'\\'), Wall(1,9,'_'), Wall(2,9,'_'), Wall(3,9,'_'), Wall(4,9,'_'), Wall(5,9,'_'), Wall(6,9,'_'), Wall(7,9,'_'), Wall(8,9,'_'), Wall(9,9,'_'), Wall(10,9,'_'), Wall(11,9,'_'), Wall(12,9,'_'), Wall(13,9,'_'), Wall(14,9,'_'), Wall(15,9,'_'), Wall(16,9,'_'), Wall(17,9,'_'), Wall(18,9,'_'), Wall(19,9,'/')},
        };

        // Copie du tableau dans l'attribut
        for(int i = 0; i < Heigth; i++){
            for(int y = 0; y < Width; y++){
                switch(_pattern[i][y].GetChar()){
                    case '|':
                    case '_':
                    case '-':
                    case '\\':
                    case ' ':
                    case '/':
                    case 'X':
                        this->ROPattern[i][y] = Wall(_pattern[i][y].GetX(),_pattern[i][y].GetY(), _pattern[i][y].GetChar());
                        break;
                    case 'C':
                        this->ROPattern[i][y] = Chest(_pattern[i][y].GetX(),_pattern[i][y].GetY(), _pattern[i][y].GetChar());
                        break;
                }
            }
        }
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
                if(ROPattern[i][y].GetChar() == 'X'){
                    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
                    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hstdout, 0x0C);
                    std::cout << ROPattern[i][y].GetChar();
                    SetConsoleTextAttribute(hstdout, 0x0F);
                    FlushConsoleInputBuffer(hstdin);
                    // CheckAround(i,y);
                    playerX = i;
                    playerY = y;
                }else{
                    std::cout << ROPattern[i][y].GetChar();
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
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
    }
    // Permet de mettre à jour la position du joueur en fonction de la touche pressée
    void Room::Update(char key) {
        for(int i = 0; i < this->Heigth; i++){
            for(int y = 0; y < this->Width; y++){
                if(this->ROPattern[i][y].GetChar() == 'X'){
                    switch (key)
                    {
                        case 'w':
                            if(ROPattern[i-1][y].GetChar() == ' ') {
                                this->ROPattern[i-1][y] = Wall(i-1, y, 'X');
                                this->ROPattern[i][y] = Wall(i, y, ' ');
                            }
                            break;
                        case 's':
                            if(ROPattern[i+1][y].GetChar() == ' ') {
                                this->ROPattern[i+1][y] = Wall(i+1, y, 'X');
                                this->ROPattern[i][y] = Wall(i, y, ' ');
                            }
                            break;
                        case 'a':
                            if(ROPattern[i][y-1].GetChar() == ' ') {
                                this->ROPattern[i][y-1] = Wall(i, y-1, 'X');
                                this->ROPattern[i][y] = Wall(i, y, ' ');
                            }
                            break;
                        case 'd':
                             if(ROPattern[i][y+1].GetChar() == ' ') {
                                this->ROPattern[i][y+1] = Wall(i, y+1, 'X');
                                this->ROPattern[i][y] = Wall(i, y, ' ');
                             }
                            break;
                    }
                    return;
                }
            }
        }
    }
    // Fonction permettant de contrôler ce qu'il y autour du joueur
    void Room::CheckAround(int x, int y){
        int lineNb = 2;
        for(int i = x-1; i <= x+1; i++){
            for(int j = y-1; j <= y+1; j++){
                switch(ROPattern[i][j].GetChar()){
                    case 'C':
                        GotoXY(25,lineNb);
                        cout << "Coffre";
                        lineNb++;
                        break;
                }   
            }
        }
    }
}
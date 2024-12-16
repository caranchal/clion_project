#include <iostream> 
#include "windows.h" 

using namespace std;


int SIZE_MAP_X = 10;
int SIZE_MAP_Y = 10;
int zomb_x = 1;
int zomb_y = 1;
int human_x = 2;
int human_y = 2;

/*void Param() {
    int s, z, h;
    cout << "настройка" << endl;
    cout << "веберите соличество зомби" << endl;
    cin >> z;
    cout << "размер поля" << endl;
    cin >> s;
    SIZE_MAP_X = s;
    SIZE_MAP_Y = s;
    cout << "колво людей" << endl;
    cin >> h;
}*/
char** map = new char* [SIZE_MAP_X];
void InitMap(int character_x, int character_y) {
    for (int i = 0; i < SIZE_MAP_X; i++) {
        map[i] = new char[SIZE_MAP_Y];
        for (int j = 0; j < SIZE_MAP_Y; j++) {
            if (i == 0 || i == SIZE_MAP_Y - 1 || j == 0 || j == SIZE_MAP_Y - 1) {
                map[i][j] = '*';
            }
            else {
                if (i == character_x && j == character_y)
                    map[i][j] = ' ';                
                else
                    map[i][j] = ' ';
            }
        }
    }
}
void PrintPlace() {
    for (int i = 0; i < SIZE_MAP_X; i++) {
        for (int j = 0; j < SIZE_MAP_Y; j++) {
            cout << map[i][j] << " ";
        }        cout << endl;
    }
}
void RedrawPlace() {
    system("cls");    PrintPlace();
}
bool MoveZomb(int destination_x, int destination_y) {
    if (map[destination_x][destination_y] != '*') {
        zomb_x = destination_x;
        zomb_y = destination_y;
        for (int i = 0; i < SIZE_MAP_X; i++) {
            for (int j = 0; j < SIZE_MAP_Y; j++) {
                if (map[i][j] == 'Z')                    
                    map[i][j] = ' ';
            }
        }
        map[destination_x][destination_y] = 'Z';
        return true;
    }
    else        return false;
}

bool MoveHuman(int destination_x, int destination_y) {
    if (map[destination_x][destination_y] != '*') {
        human_x = destination_x;
        human_y = destination_y;
        for (int i = 0; i < SIZE_MAP_X; i++) {
            for (int j = 0; j < SIZE_MAP_Y; j++) {
                if (map[i][j] == 'H')   
                    map[i][j] = ' ';
            }
        }
        map[destination_x][destination_y] = 'H';
        return true;
    }
    else        
    return false;
}
/*int zom() {
    for (int i = 0; i < SIZE_MAP_X;i++) {
        for (int j = 0; j < SIZE_MAP_Y;i++) {
            if (zomb_x == human_x && zomb_y == human_y) {
                map[i][j] = 'Z';
            }
        }
    }
    
}
*/

void Init_Zombie_Human(int zombie, int human) {
    int temp;
    
    for (int i = 0; i < zombie; i++) {
        for (int j = 0; j < zombie;j++) {
            int x = rand() % 2;
            int y = x;
            if (map[x][y] != '*' && map[x][y] != 'Z' && map[x][y] != 'H') {
                
                map[x][y] = 'Z';
                map[x][y] = ' ';
            }
            
        }
    }
    for (int i = 0; i < human;i++) {
        for (int k = 0; k < human;k++) {

            int x = rand() % 2;
            int y = x;
            if (map[x][y] != '*' && map[x][y] != 'Z' && map[x][y] != 'H') {
                map[x][y] = 'H';
                map[x][y] = ' ';
            }
            
        }
    }
}

int main()
{
   //Param();

    InitMap(1, 1);
    Init_Zombie_Human(3, 3);
    while (true) {
        /*
        switch (rand() % 4) {
        case 0:                 
            MoveZomb(zomb_x + 1, zomb_y);
            MoveHuman(human_x - 1, human_y);
        break;            
        case 1:
            MoveZomb(zomb_x - 1, zomb_y);
            MoveHuman(human_x + 1, human_y);
            break;
        case 2:               
            MoveZomb(zomb_x, zomb_y + 1);
            MoveHuman(human_x, human_y - 1);
        break;            
        case 3:
            MoveZomb(zomb_x, zomb_y - 1);
            MoveHuman(human_x, human_y + 1);
            break;
        }     
        */
        
        int nextMoveX;
        int nextMoveY;

        if (rand() % 2 == 0) nextMoveX = -1;
        else nextMoveX = 1;
        
        if (rand() % 2 == 0) nextMoveY = -1;
        else nextMoveY = 1;

       
            MoveZomb(zomb_x + nextMoveX, zomb_y + nextMoveY);

        
       

        if (rand() % 2 == 0) nextMoveX = -1;
        else nextMoveX = 1;

        if (rand() % 2 == 0) nextMoveY = -1;
        else nextMoveY = 1;

        MoveHuman(human_x + nextMoveX, human_y + nextMoveY);

        Sleep(100);
        RedrawPlace();
    }
   
}

// SNAKE GAME
// CONSOLE GAME

#include <iostream>
#include <windows.h>
using namespace std;

// Initialise Variable
bool snake , menu, normalgame;
const int w = 55;
const int h = 25;
// User Variable
int x, y, spd = 1;
//Tail variables
int tX[100], tY[100],tlen;
//Tail coordinates
int fposX, fposY,sposX,sposY;
// Target Variable
int targetX, targetY;
// Game Variable
int score;
enum directions
{
    STOP = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};
directions dir;

void mainMenu()
{
    system("cls");
    cout << "This is the Main Menu:" << endl;
    cout << "Play the Game"<< endl;
    cout << "Options" << endl;
    cout << "End Game" << endl;

    if (GetAsyncKeyState(VK_RETURN))
    {
        menu = false;
    }
    else if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
    {
        dir = STOP;
    }
    else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
    {
        dir = STOP;
    }
    else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
    {
        dir = STOP;
    }
    else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
    {
        dir = STOP;
    }
}

void gamesetup()
{
    snake = true;
    menu = true;

}

void gameover()
{
    normalgame = false;
    menu = true;
    tlen = 0;
    score = 0;
}

void normalsetup()
{
    normalgame = true;
    //At Zero
    dir = STOP;
    x = rand() % w;
    y = rand() % h;
    targetX = rand() % w;
    targetY = rand() % h;
    // ERROR WHEN TARGET AND PLAYER ARE ON TOP
    while (x == targetX && y == targetY)
    {
        //Setting player and target start point
        x = rand() % w;
        y = rand() % h;
        targetX = rand() % w;
        targetY = rand() % h;
    }
    score = 0;
}

void window()
{
    system("cls");
    // Top border
    for (int i = 0; i < w; i++)
    {
        cout << "#";
    }
    cout << endl;
    // Body
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (j == 0 || j == w - 1)
            {
                cout << "#";
            }
            else if (i == y && j == x)
            {
                cout << "A";
            }
            else if (i == targetY && j == targetX)
            {
                cout << "S";
            }
            else
            {
                bool tail = false;
                for (int k = 0; k < tlen; k++)
                {
                    if (j == tX[k] && i == tY[k])
                    {
                        cout << "a";
                        tail = true;
                    }
                }
                if (!tail)
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    // Bottom border
    for (int i = 0; i < w; i++)
    {
        cout << "#";
    }
    cout << endl;
    //Score board
    cout << "Score: "<<score;
}
// controls setting A,S,D,W & arow keys
void input()
{
    if (menu == false && normalgame == true)
    {
        if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A') && dir != RIGHT)
        {
            dir = LEFT;
        }

        else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D') && dir != LEFT)
        {
            dir = RIGHT;
        }
        else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S') && dir != UP)
        {
            dir = DOWN;
        }
        else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W') && dir != DOWN)
        {
            dir = UP;
        }
        else if (GetAsyncKeyState(VK_RETURN))
        {
            return;
        }

    }
}

void program()
{
    //Tail
    fposX = tX[0];
    fposY = tY[0];
    tX[0] = x;
    tY[0] = y;
    for (int i = 1; i < tlen; i++)
    {
        sposX = tX[i];
        sposY = tY[i];
        tX[i] = fposX;
        tY[i] = fposY;
        fposX = sposX;
        fposY = sposY;
    }
    //Move Snake
    switch (dir)
    {
    case LEFT:
        x -= spd;
        break;
    case UP:
        y -= spd;
        break;
    case DOWN:
        y += spd;
        break;
    case RIGHT:
        x += spd;
        break;
    }

    //Snake Border Hit
    if (x <= 0 || x >= w - 1 || y < 0 || y > h - 1)
    {
        gameover();
    }
    //Snake tail hit
    for (int i = 0; i < tlen; i++)
    {
        if (x == tX[i] && y == tY[i])
        {
            gameover();
        }
    }
    //Snake hits Target
    if (x == targetX && y == targetY)
    {
        targetX = rand() % w;
        targetY = rand() % h;
        score += 10;
        tlen++;
    }
}
int main()
{
    gamesetup();
    while (snake == true)
    {
        if(menu == true)
        {
            mainMenu();
        }
        else if (menu == false)
        {
            normalsetup();
            while (normalgame == true)
            {
                window();
                input();
                program();
                Sleep(30);
            }
        }
    }
}
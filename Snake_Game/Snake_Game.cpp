// SNAKE GAME
// CONSOLE GAME

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Initialixe Variable
bool snake;
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

void setup()
{
    snake = true;
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
        cout << "*";
    }
    cout << endl;
    // Body
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (j == 0 || j == w - 1)
            {
                cout << "*";
            }
            else if (i == y && j == x)
            {
                cout << "S";
            }
            else if (i == targetY && j == targetX)
            {
                cout << "O";
            }
            else
            {
                bool tail = false;
                for (int k = 0; k < tlen; k++)
                {
                    if (j == tX[k] && i == tY[k])
                    {
                        cout << "s";
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
        cout << "*";
    }
    cout << endl;
    cout << score;
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if (dir != RIGHT)
            {
                dir = LEFT;
            }
            break;
        case 's':
            if (dir != UP)
            {
                dir = DOWN;
            }
            break;
        case 'd':
            if (dir != LEFT)
            {
                dir = RIGHT;
            }
            break;
        case 'w':
            if (dir != DOWN)
            {
                dir = UP;
            }
            break;
        case '0':
            snake = false;
            break;
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
        snake = false;
    }
    //Snake tail hit
    for (int i = 0; i < tlen; i++)
    {
        if (x == tX[i] && y = tY[i])
        {
            snake = false;
        }
    }
    //Snake hits Target
    if (x == targetX && y == targetY)
    {
        targetX = rand() % w;
        targetY = rand() % h;
        score++;
        tlen++;
    }
}
int main()
{
    setup();
    while (snake == true)
    {
        window();
        input();
        program();
        Sleep(30);
    }

}
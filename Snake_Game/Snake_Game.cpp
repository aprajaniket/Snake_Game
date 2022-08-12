// SNAKE GAME
// CONSOLE GAME

#include <iostream>
#include <conio.h>
using namespace std;

// Initialixe Variable
bool snake;
const int w = 25;
const int h = 25;
// User Variable
int x, y, spd = 1;
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
    dir = STOP;
    x = rand() % w;
    y = rand() % h;
    targetX = rand() % w;
    targetY = rand() % h;
    // ERROR WHEN TARGET AND PLAYER ARE ON TOP
    while (x == targetX && targetY)
    {
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
            else
            {
                cout << " ";
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
    if (x <= 0 || x >= w - 1 || y <= 0 || y >= h - 1)
    {
        snake = false;
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
    }

    return 0;
}
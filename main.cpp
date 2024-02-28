#include <iostream>
#include <iomanip>

#include "Die.h"

using namespace std;


bool search(direction lastRoll, bool setNumber);

static Die die;
static int moveCnt = 0;
static int score = 0;
static int x = 0;
static int y = 0;
//               y  x
static int table[6][6] = {
    {0,   77,  32, 403, 337, 452},
    {5,   23,  -4, 592, 445, 620},
    {-7,   2, 357, 452, 317, 395},
    {186, 42, 195, 704, 452, 228},
    {81, 123, 240, 443, 353, 508},
    {57,  33, 132, 268, 492, 732},
};

static int moveset[6][6] = {
    {0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1},
};

void printGrid(int grid[6][6])
{
    for (int i = 5; i > -1; i--)
    {
        for (int j = 0; j < 6; j++)
            cout << setw(3) << grid[i][j] << ",";
        cout << endl;
    }
}

int sumOfSquares()
{
    int sum = 0;
    for (int i = 5; i > -1; i--)
        for (int j = 0; j < 6; j++)
            if (moveset[j][i] == -1)
                sum += table[j][i];
    return sum;
}

void printResult()
{
    cout << "MoveCnt: " << moveCnt << endl;
    cout << "Score: " << score << endl;
    cout << "Moveset Grid:" << endl;
    printGrid(moveset);
    cout << "Sum of unvisited squares: " << sumOfSquares() << endl << endl;
}

int main()
{
    if ( search(DIR_UP, false) ) // Came from owhere tho but no matter.
    {
        cout << "Solution found" << endl << endl;
        printResult();
    }
    else
    {
        cout << "Returned False" << endl << "Algorithm Failed" << endl;
    }

}

bool search(direction lastRoll, bool setNumber)
{
    //      Try going up
    if (y +1 <= 6)
    {
        if (die.peakValue(DIR_UP) == 0 &&
            (table[y+1][x] - score) % (moveCnt+1) == 0)
        {
            // Update position
            // Update move count
            // Update moveset
            // Roll dice
            // set new current value for face
            // Update score
            y++;
            moveCnt++;
            moveset[y][x] = moveCnt;
            die.rollUp();
            // faceval = (tableVal - score) /  moveCnt;
            die.setCurrentValue( (table[y][x] - score) / moveCnt);
            score += moveCnt * die.getCurrentValue();

            setNumber = true;

            // Check if we are there
            if (table[y][x] == 732)
                return true;
            if ( search(DIR_UP, true) )
                return true;
        }
        else if ( (table[y+1][x] - score) % (moveCnt+1) == 0 &&
                  table[y+1][x] == score + (moveCnt+1) * die.peakValue(DIR_UP))
        {
            // Update position
            // Update move count
            // Update moveset
            // Roll dice
            // Update score
            y++;
            moveCnt++;
            moveset[y][x] = moveCnt;
            die.rollUp();
            score += moveCnt * die.getCurrentValue();

            // Check if we are there
            if (table[y][x] == 732)
                return true;
            if ( search(DIR_UP, false) )
                return true;
        }
    }

    //      Try going right
    if (x +1 <= 6)
    {
        if (die.peakValue(DIR_RIGHT) == 0 &&
            (table[y][x+1] - score) % (moveCnt+1) == 0)
        {
            // Update position
            // Update move count
            // Update moveset
            // Roll dice
            // set new current value for face
            // Update score
            x++;
            moveCnt++;
            moveset[y][x] = moveCnt;
            die.rollRight();
            // faceval = (tableVal - score) /  moveCnt;
            die.setCurrentValue( (table[y][x] - score) / moveCnt);
            score += moveCnt * die.getCurrentValue();

            setNumber = true;

            // Check if we are there
            if (table[y][x] == 732)
                return true;
            if ( search(DIR_RIGHT, true) )
                return true;
        }
        else if ( (table[y][x+1] - score) % (moveCnt+1) == 0 &&
                  table[y][x+1] == score + (moveCnt+1) * die.peakValue(DIR_RIGHT) )
        {
            // Update position
            // Update move count
            // Update moveset
            // Roll dice
            // Update score
            x++;
            moveCnt++;
            moveset[y][x] = moveCnt;
            die.rollRight();
            score += moveCnt * die.getCurrentValue();

            // Check if we are there
            if (table[y][x] == 732)
                return true;
            if ( search(DIR_RIGHT, false) )
                return true;
        }
    }

    //      Try going down
    if (y -1 >= 0)
    {
        if (die.peakValue(DIR_DOWN) == 0 &&
            (table[y-1][x] - score) % (moveCnt+1) == 0)
        {
            // Update position
            // Update move count
            // Update moveset
            // Roll dice
            // set new current value for face
            // Update score
            y--;
            moveCnt++;
            moveset[y][x] = moveCnt;
            die.rollDown();
            // faceval = (tableVal - score) /  moveCnt;
            die.setCurrentValue( (table[y][x] - score) / moveCnt);
            score += moveCnt * die.getCurrentValue();

            setNumber = true;

            // Check if we are there
            if (table[y][x] == 732)
                return true;
            if ( search(DIR_DOWN, true) )
                return true;
        }
        else if ( (table[y-1][x] - score) % (moveCnt+1) == 0 &&
                  table[y-1][x] == score + (moveCnt+1) * die.peakValue(DIR_DOWN) )
        {
            // Update position
            // Update move count
            // Update moveset
            // Roll dice
            // Update score
            y--;
            moveCnt++;
            moveset[y][x] = moveCnt;
            die.rollDown();
            score += moveCnt * die.getCurrentValue();

            // Check if we are there
            if (table[y][x] == 732)
                return true;
            if ( search(DIR_DOWN, false) )
                return true;
        }
    }

    //      Try going left
    if (x -1 >= 0)
    {
        if (die.peakValue(DIR_LEFT) == 0 &&
            (table[y][x-1] - score) % (moveCnt+1) == 0)
        {
            // Update position
            // Update move count
            // Update moveset
            // Roll dice
            // set new current value for face
            // Update score
            x--;
            moveCnt++;
            moveset[y][x] = moveCnt;
            die.rollLeft();
            // faceval = (tableVal - score) /  moveCnt;
            die.setCurrentValue( (table[y][x] - score) / moveCnt);
            score += moveCnt * die.getCurrentValue();

            setNumber = true;

            // Check if we are there
            if (table[y][x] == 732)
                return true;
            if ( search(DIR_LEFT, true) )
                return true;
        }
        else if ( (table[y][x-1] - score) % (moveCnt+1) == 0 &&
                  table[y][x-1] == score + (moveCnt+1) * die.peakValue(DIR_LEFT) )
        {
            // Update position
            // Update move count
            // Update moveset
            // Roll dice
            // Update score
            x--;
            moveCnt++;
            moveset[y][x] = moveCnt;
            die.rollLeft();
            score += moveCnt * die.getCurrentValue();

            // Check if we are there
            if (table[y][x] == 732)
                return true;
            if ( search(DIR_LEFT, false) )
                return true;
        }
    }

    //      Need to roll back changes
    // Update score
    // Update current value to 0 if set in this move
    // Update moveset
    // Update move count
    // Update table position koordinates
    // Update dice by rolling back
    score -= moveCnt * die.getCurrentValue();
    if (setNumber)
        die.setCurrentValue(0);
    moveset[y][x] = -1;
    moveCnt--;
    switch (lastRoll)
    {
    case DIR_UP:
        y--;
        die.rollDown();
        break;
    case DIR_LEFT:
        x++;
        die.rollRight();
        break;
    case DIR_DOWN:
        y++;
        die.rollUp();
        break;
    case DIR_RIGHT:
        x--;
        die.rollLeft();
        break;
    }

    return false;
}



//#include <stdlib.h>
//int main()
//{
//    Die die;

//    cout << "side " << die.getCurrentFace() << endl;

//    cout << "Random rolling starts.." << endl;
//    int r;
//    for (int x = 0; x < 20; ++x)
//    {
//        r = rand() % 4;
//        switch (r)
//        {
//        case 0:
//            cout << "up    " << die.rollUp() << endl;
//            break;
//        case 1:
//            cout << "left  " << die.rollLeft() << endl;
//            break;
//        case 2:
//            cout << "down  " << die.rollDown() << endl;
//            break;
//        case 3:
//            cout << "right " << die.rollRight() << endl;
//            break;

//        default:
//            break;
//        }
//    }

//    cout << "Random rolling ended.." << endl << endl;

//    cout << "right " << die.rollRight() << endl;
//    cout << "down  " << die.rollDown() << endl;
//    cout << "down  " << die.rollDown() << endl;
//    cout << "down  " << die.rollDown() << endl;
//    cout << "down  " << die.rollDown() << endl;
//    cout << "down  " << die.rollDown() << endl;
//    cout << "down  " << die.rollDown() << endl;
//    cout << "down  " << die.rollDown() << endl;
//    cout << "up    " << die.rollUp() << endl;
//    cout << "up    " << die.rollUp() << endl;
//    cout << "up    " << die.rollUp() << endl;
//    cout << "up    " << die.rollUp() << endl;
//    cout << "up    " << die.rollUp() << endl;
//    cout << "up    " << die.rollUp() << endl;
//    cout << "down  " << die.rollDown() << endl;

//    cout << "All its good" << endl;
//    return 0;
//}

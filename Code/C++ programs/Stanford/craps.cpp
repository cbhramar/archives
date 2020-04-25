#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include "random.h"

using namespace std;

bool tryToMakePoint(int point);
int rollTwoDice();

int main()
{
    cout << "RAND_MAX on this computer is " << RAND_MAX << endl << endl;
    cout << "This program plays a game of craps\n";
    int point = rollTwoDice();
    switch(point)
    {
        case 7: case 11:
            cout << "That's a natural. You win :) \n";
            break;
        case 2: case 3: case 12:
            cout << "That's crap. You lose :( \n";
            break;
        default:
            cout << "Your point is : " << point << endl;
            if (tryToMakePoint(point))
            {
                cout << "You made your point. You win :) \n";
            }
            else
                cout << "You rolled a seven. You lose :( \n";
    }
    return 0;
}

int rollTwoDice()
{
    cout << "Rolling the dice ... \n";
    int d1 = randomInteger(1,6);
    int d2 = randomInteger(1,6);
    int total = d1 + d2;
    cout << "You rolled " << d1 << " and " << d2 << " - that's " << total << endl;
    return total;
}

bool tryToMakePoint(int point)
{
    while(true)
    {
        int total = rollTwoDice();
        if (total == point) return true;
        if (total == 7) return false;
    }
}

void initRandomSeed();

int randomInteger(int low, int high)
{
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return int(floor(low + s));
}

double randomReal(int low, int high)
{
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low);
    return low + s;
}

bool randomChance(double p)
{
    initRandomSeed();
    return randomReal(0, 1) < p;
}

void setRandomSeed(int seed)
{
    initRandomSeed();
    srand(seed);
}

void initRandomSeed()
{
    static bool initialized = false;
    if (!initialized)
    {
        srand(int(time(NULL)));
        initialized = true;
    }
}

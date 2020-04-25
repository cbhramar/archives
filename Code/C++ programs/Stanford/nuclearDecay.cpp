#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include"random.h"

using namespace std;

const int INITIAL = 10000;

void printDecayPattern();
int decayAmount(int n, int year);

int main(){
    printDecayPattern();
    return 0;
}

void printDecayPattern(){
    cout << "There are " << right << setw(5) << INITIAL << " atoms initially \n";
    int n = INITIAL;
    decayAmount(n, 1);
}

int decayAmount(int n, int year)
{
    int x = 0;
    for (int i = 0; i < n; i++){
        if (randomChance(0.5)){
            x++;
        }
    }
    cout << "There are " << right << setw(5) << x << " atoms at the end of year " << setw(2) << year << endl;
    if (x != 0)
        decayAmount(x, year + 1);
    return x;
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

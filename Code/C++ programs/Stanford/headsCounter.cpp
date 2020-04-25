#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void initRandomSeed() {
    static bool initialized = false;
    if (!initialized) {
        srand(int(time(NULL)));
        initialized = true;
    }
}

int randomInteger(int low, int high) {
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return int(floor(low + s));
}

double randomReal(int low, int high) {
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low);
    return low + s;
}

bool randomChance(double p) {
    initRandomSeed();
    return randomReal(0, 1) < p;
}

void setRandomSeed(int seed) {
    initRandomSeed();
    srand(seed);
}

void headsCounter() {
    int hcount = 0;
    int i = 0;
    while (true) {
        if (randomInteger(0, 1) == 1) {
            hcount ++;
            cout << "Heads" << endl;
        }
        else {
            hcount = 0;
            cout << "Tails" << endl;
        }
        i ++;
        if (hcount == 10) {
            cout << "It took " << i << " attempts to get ten heads. \n";
            break;
        }
    }
}

int main() {
    cout << "Flipping a coin and listing the results :\n";
    headsCounter();
    return 0;
}

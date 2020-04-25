#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include "random.h"

using namespace std;

double randomAverage(int n);
double randomRMS(int n);

int main() {
    cout << "Please enter required number of trials \n";
    int n;
    cin >> n;
    cout << "The average of " << n << " trials is " << randomAverage(n) << endl;
    cout << "The RMS of " << n << " trials is " << randomRMS(n) << endl;
    return 0;
}

double randomAverage(int n) {
    double sum = 0;
    double term;
    for (int i=0; i<n; i++)
    {
        term = randomReal(0, 1);
        sum = sum + term;
    }
    double avg = sum/double(n);
    return avg;
}

double randomRMS(int n) {
    double sum = 0;
    double term;
    for (int i = 0; i<n; i++)
    {
        term = randomReal(0, 1);
        sum = sum + term*term;
    }
    double avg = sum/double(n);
    double sqrtavg = sqrt(avg);
    return sqrtavg;
}

void initRandomSeed();

int randomInteger(int low, int high) {
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return int(floor(low + s));
}

double randomReal(double low, double high) {
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

void initRandomSeed() {
    static bool initialized = false;
    if (!initialized)
    {
        srand(int(time(NULL)));
        initialized = true;
    }
}

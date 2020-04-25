#include<simplecpp>
#include<iostream>
#include<cmath>
#include"random.h"
#include<cstdlib>
#include<ctime>

using namespace std;

void drawFractalTree(int order, int l, double x, double y, double t);

int main(){
    int length = 200;
    initCanvas("Fractal Tree", 1360, 700);
    drawFractalTree(17, length, 680, 650, -PI/2);
    getClick();
}

void drawFractalTree(int order, int l, double x, double y, double t){
    if(order == 0 || order == 1) {
        Line l0(x, y, x + l*cos(t), y + l*sin(t));
        l0.imprint();
        if (randomChance(0.75)){
            Circle c1(x + l*cos(t), y + l*sin(t), 2.5);
            c1.setFill(true);
            c1.setColor(COLOR(100, 180, 100));
            c1.imprint();
        }
        else{
            Circle c1(x + l*cos(t), y + l*sin(t), 2.5);
            c1.setFill(true);
            c1.setColor(COLOR(253, 100, 100));
            c1.imprint();
        }
    }
    else{
        Rectangle r(x + cos(t)*l/2, y + sin(t)*l/2, order, l);
        r.rotate(t + PI/2);
        r.setFill(true);
        r.setColor(COLOR("black"));
        r.imprint();
        drawFractalTree(order - 2, l*0.7, x + l*cos(t), y + l*sin(t), t - PI/4 + (17 - order)*PI/150);
//        drawFractalTree(order - 1, l*0.75, x + l*cos(t), y + l*sin(t), t + PI/6 );
        drawFractalTree(order - 1, l*0.75, x + l*cos(t), y + l*sin(t), t + PI/4 + (17 - order)*PI/100);
//        drawFractalTree(order - 1, l*0.75, x + l*cos(t), y + l*sin(t), t - PI/6 );
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

double randomReal(double low, double high)
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
    simplecpp::srand(seed);
}

void initRandomSeed()
{
    static bool initialized = false;
    if (!initialized)
    {
        simplecpp::srand(int(time(NULL)));
        initialized = true;
    }
}

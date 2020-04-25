#include<simplecpp>
#include<iostream>
#include<cmath>

using namespace std;

void drawStuff(double r, int x, int y);

int main(){
    initCanvas("Draw Stuff", 1360, 700);
    drawStuff(300, 680, 350);
    getClick();
}

void drawStuff(double r, int x, int y){
    if (r >= 5){
        Circle c0(x, y, r);
        c0.imprint();
        drawStuff(r*0.5, x - r/2, y - r/2);
        drawStuff(r*0.5, x + r/2, y - r/2);
        drawStuff(r*0.5, x + r/2, y + r/2);
        drawStuff(r*0.5, x - r/2, y + r/2);
    }
}

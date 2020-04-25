#include<iostream>
#include<simplecpp>

using namespace std;

void drawHem(int n, double x, double y, double l);

int main(){
    initCanvas("Fibbonacci Tree", 1360, 700);
    drawHem(7, 680, 250, 150);
    getClick();
}

void drawHem(int n, double x, double y, double l){
    if (n == 0 || n == 1){
        Text t(x, y + 10, n);
        t.imprint();
    }
    else {
        Text t1(x, y - 10, n);
        t1.imprint();
        double t = PI/7 + (7- n)*PI/20;
        Line l0(x, y, x + l*cos(t), y + l*sin(t));
        l0.imprint();
        drawHem(n - 1, x + l*cos(t), y + l*sin(t), l*0.75);
        Line l1(x, y, x - l*cos(t), y + l*sin(t));
        l1.imprint();
        drawHem(n - 2, x - l*cos(t), y + l*sin(t), l*0.75*0.75);
    }
}

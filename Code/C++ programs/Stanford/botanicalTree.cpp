#include<iostream>
#include<simplecpp>

using namespace std;

void botanicalTree(int order, double length, double theta, double x, double y);

int main(){
    initCanvas("Botanical Tree", 1360, 700);
    botanicalTree(7, 300, -PI/2, 680, 700);
    getClick();
}

void botanicalTree(int order, double length, double theta, double x, double y){
    if (order == 0 || order == 1){
        Line l0(x, y, x + length*cos(theta), y + length*sin(theta));
        l0.imprint();
    }
    else{
        Line l0(x, y, x + length*cos(theta), y + length*sin(theta));
        l0.imprint();
        botanicalTree(order - 1, length*0.6, theta - PI/4, x + 0.7*length*cos(theta), y + 0.7*length*sin(theta));
        botanicalTree(order - 2, length*0.4, theta + PI/6, x + 0.7*length*cos(theta), y + 0.7*length*sin(theta));
        botanicalTree(order - 1, length*0.5, theta + PI/5, x + length*cos(theta), y + length*sin(theta));
        botanicalTree(order - 1, length*0.55, theta , x + length*cos(theta), y + length*sin(theta));
    }
}

#include <simplecpp>
#include <iostream>
#include <cmath>

using namespace std;

void fractalLine(double x, double y, double length, double theta, int order);

int main(){
    cout << "Enter length of 0 order fractal :" << endl;
    double length;
    cin >> length;
    initCanvas("Koch Snowflake", 800, 700);
    fractalLine(400 - (length/2.0), 350 - sqrt(3)*(length/6.0), length, 0, 5);
    fractalLine(400 + (length/2.0), 350 - sqrt(3)*(length/6.0), length, 2*PI/3.0, 5);
    fractalLine(400, 350 + sqrt(3)*(length/3.0), length, -2*PI/3.0, 5);
    getClick();
}

void fractalLine(double x, double y, double length, double theta, int order){
    if (order == 0){
        Line l(x, y, x + length*cos(theta), y + length*sin(theta));
        l.imprint();
    }
    else{
        double newX = x + (length/3.0)*cos(theta);
        double newY = y + (length/3.0)*sin(theta);
//        Line l1(x, y, newX, newY);
//        l1.imprint();
        fractalLine(newX, newY, length/3.0, theta - PI/3.0, order - 1);
        fractalLine(x, y, length/3.0, theta, order - 1);
        fractalLine(newX + (length/3.0)*cos(theta - PI/3.0), newY + (length/3.0)*sin(theta - PI/3.0), length/3.0, theta + PI/3.0, order - 1);
//        Line l2(x + 2*(length/3.0)*cos(theta), y + 2*(length/3.0)*sin(theta), x + (length)*cos(theta), y + (length)*sin(theta));
//        l2.imprint();
        fractalLine(x + 2*(length/3.0)*cos(theta), y + 2*(length/3.0)*sin(theta), length/3.0, theta, order - 1);
    }
}

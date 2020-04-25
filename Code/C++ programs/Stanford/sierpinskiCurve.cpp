#include <simplecpp>
#include <iostream>

using namespace std;

const double cenx = 680;
const double cenY = 350;

void createSCurve(double x, double y, double length, int order);

int main(){
    initCanvas("The Sierpinski Curve", 1360, 700);
    createSCurve(680, 350, 200, 3);
    getClick();

    return 0;
}

void createSCurve(double x, double y, double length, int order){
    if (order == 0){
        Line l0(x - length/4, y - length/2, x + length/4, y - length/2);
        l0.imprint();
        Line l1(x + length/2, y - length/4, x + length/2, y + length/4);
        l1.imprint();
        Line l2(x + length/4, y + length/2, x - length/4, y + length/2);
        l2.imprint();
        Line l3(x - length/2, y + length/4, x - length/2, y - length/4);
        l3.imprint();

        Line l4(x + length/4, y - length/2, x + length/2, y - 3*length/4);
        l4.imprint();
//        Line l5(x + length/2, y - 3*length/4, x + 3*length/4, y - length/2);
//        l5.imprint();
        Line l6(x + 3*length/4, y - length/2, x + length/2, y - length/4);
        l6.imprint();

        Line l7(x + length/2, y + length/4, x + 3*length/4, y + length/2);
        l7.imprint();
//        Line l8(x + 3*length/4, y + length/2, x + length/2, y + 3*length/4);
//        l8.imprint();
        Line l9(x + length/2, y + 3*length/4, x + length/4, y + length/2);
        l9.imprint();

        Line l10(x - length/4, y + length/2, x - length/2, y + 3*length/4);
        l10.imprint();
//        Line l11(x - length/2, y + 3*length/4, x - 3*length/4, y + length/2);
//        l11.imprint();
        Line l12(x - 3*length/4, y + length/2, x - length/2, y + length/4);
        l12.imprint();

        Line l13(x - length/2, y - length/4, x - 3*length/4, y - length/2);
        l13.imprint();
//        Line l14(x - 3*length/4, y - length/2, x - length/2, y - 3*length/4);
//        l14.imprint();
        Line l15(x - length/2, y - 3*length/4, x - length/4, y - length/2);
        l15.imprint();
    }
    else{
        createSCurve(x, y, length/2, order - 1);
        createSCurve(x + length/2, y + length/2, length/2, order - 1);
        createSCurve(x + length/2, y - length/2, length/2, order - 1);
        createSCurve(x - length/2, y + length/2, length/2, order - 1);
        createSCurve(x - length/2, y - length/2, length/2, order - 1);
    }
}

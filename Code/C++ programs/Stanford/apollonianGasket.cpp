#include<simplecpp>

using namespace std;

const double cenX = 680;
const double cenY = 350;

void apollonianGasket(double c1x, double c1y, double c1r, double c2x, double c2y, double c2r, double c3x, double c3y, double c3r, int n);

int main(){
    initCanvas("Apollonian Gasket", 1360, 700);
    Circle circle1(580, 350 - sqrt(3)*200/6, 100);
    circle1.imprint();
    Circle circle2(780, 350 - sqrt(3)*200/6, 100);
    circle2.imprint();
    Circle circle3(680, 350 + sqrt(3)*200/3, 100);
    circle3.imprint();
    apollonianGasket(580, 350 - sqrt(3)*200/6, 100, 780, 350 - sqrt(3)*200/6, 100, 680, 350 + sqrt(3)*200/3, 100, 2);
    getClick();
}

void apollonianGasket(double c1x, double c1y, double c1r, double c2x, double c2y, double c2r, double c3x, double c3y, double c3r, int n){
    if (n == 0){
        //create the smaller tangential circle
        double rsmall = (c1r*c2r*c3r)/(c1r*c2r + c2r*c3r + c3r*c1r + 2*sqrt(c1r*c2r*c3r*(c1r + c2r + c3r)));
        double rlarge = (c1r*c2r*c3r)/(c1r*c2r + c2r*c3r + c3r*c1r - 2*sqrt(c1r*c2r*c3r*(c1r + c2r + c3r)));
        double a = 2*(c1x - c2x);
        double a_= 2*(c1x - c3x);
        double b = 2*(c1y - c2y);
        double b_= 2*(c1y - c3y);
        double c = 2*(c1r - c2r);
        double c_= 2*(c1r - c3r);
        double d = (c1x*c1x + c1y*c1y - c1r*c1r) - (c2x*c2x + c2y*c2y - c2r*c2r);
        double d_= (c1x*c1x + c1y*c1y - c1r*c1r) - (c3x*c3x + c3y*c3y - c3r*c3r);
        double xsmall;
        double ysmall;
        xsmall = (b_*d - b*d_ - b_*c*rsmall + b*c_*rsmall)/(a*b_ - b*a_);
        ysmall = (a*d_ - a_*d + a_*c*rsmall - a*c_*rsmall)/(a*b_ - b*a_);
        Circle cs(xsmall, ysmall, rsmall);
        cs.imprint();
//        Circle cl(cenX, cenY, rlarge);
//        cl.imprint();
    }
    else{
        //create one circle, call apollonianGasket again 6 times taking pairs of two old and one new circle;
        double rsmall = (c1r*c2r*c3r)/(c1r*c2r + c2r*c3r + c3r*c1r + 2*sqrt(c1r*c2r*c3r*(c1r + c2r + c3r)));
        double rlarge = (c1r*c2r*c3r)/(c1r*c2r + c2r*c3r + c3r*c1r - 2*sqrt(c1r*c2r*c3r*(c1r + c2r + c3r)));
        double a = 2*(c1x - c2x);
        double a_= 2*(c1x - c3x);
        double b = 2*(c1y - c2y);
        double b_= 2*(c1y - c3y);
        double c = 2*(c1r - c2r);
        double c_= 2*(c1r - c3r);
        double d = (c1x*c1x + c1y*c1y - c1r*c1r) - (c2x*c2x + c2y*c2y - c2r*c2r);
        double d_= (c1x*c1x + c1y*c1y - c1r*c1r) - (c3x*c3x + c3y*c3y - c3r*c3r);
        double xsmall;
        double ysmall;
        xsmall = (b_*d - b*d_ - b_*c*rsmall + b*c_*rsmall)/(a*b_ - b*a_);
        ysmall = (a*d_ - a_*d + a_*c*rsmall - a*c_*rsmall)/(a*b_ - b*a_);
        Circle cs(xsmall, ysmall, rsmall);
        cs.imprint();
        apollonianGasket(c1x, c1y, c1r, c2x, c2y, c2r, xsmall, ysmall, rsmall, n - 1);
        apollonianGasket(c1x, c1y, c1r, c3x, c3y, c3r, xsmall, ysmall, rsmall, n - 1);
        apollonianGasket(c3x, c3y, c3r, c2x, c2y, c2r, xsmall, ysmall, rsmall, n - 1);
        apollonianGasket(c1x, c1y, c1r, c2x, c2y, c2r, cenX, cenY, rlarge, n - 1);
        apollonianGasket(c1x, c1y, c1r, c3x, c3y, c3r, cenX, cenY, rlarge, n - 1);
        apollonianGasket(c3x, c3y, c3r, c2x, c2y, c2r, cenX, cenY, rlarge, n - 1);
    }
}

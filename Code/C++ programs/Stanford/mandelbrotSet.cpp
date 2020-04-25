#include<simplecpp>
#include<iostream>
#include<cmath>

using namespace std;

class comp{
public:
    double real;
    double imaginary;

    comp(double x = 0, double y = 0){
        real = x;
        imaginary = y;
    }
    void operator=(comp rhs){
        real = rhs.real;
        imaginary = rhs.imaginary;
    }
    comp operator+(comp rhs){
        return comp(real + rhs.real, imaginary + rhs.imaginary);
    }
    friend comp operator*(comp c1, comp c2);
    friend bool acceptable(comp c, int order);
};

comp operator*(comp c1, comp c2){
    return comp(c1.real*c2.real - c1.imaginary*c2.imaginary, c1.real*c2.imaginary + c2.real * c1.imaginary);
}

bool acceptable(comp c, int order){
    comp z = c;
    if (order == 0){
        if (sqrt(z.real*z.real + z.imaginary*z.imaginary) <= 2.15) return true;
        else return false;
    }
    else {
        z = z*z + c;
        return acceptable(z, order - 1);
    }
}

void createMandelbrot(){
//    comp c;
    for (double i = -2.0; i <= 2.0; i += 0.01){
        for (double j = -sqrt(4 - i*i); j <= sqrt(4 - i*i); j += 0.01){
//            c(i, j);
            if (acceptable(comp(i, j), 10)){
                Circle p0(680 + 100*i, 350 + 100*j, 2);
                p0.setFill(true);
                p0.setColor(COLOR("red"));
                p0.imprint();
            }
        }
    }
}

int main(){
    initCanvas("Mandelbrot Fractal", 1360, 700);
    createMandelbrot();
    getClick();
}

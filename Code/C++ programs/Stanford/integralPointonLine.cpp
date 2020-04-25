#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b);
void findIntegralSolution(int a, int b, int c, int & x, int & y);

int main() {
    int x, y;
    int a, b, c;
    cout << "Enter the coefficeients:" << endl;
    cin >> a >> b >> c;
    if (c%gcd(a, b) == 0) {
        findIntegralSolution(a, b, c, x, y);
        cout << "An integral solution to " << a <<"x + " << b <<"y = " << c << " is : ( " << x <<" , " << y << " )" << endl;
    }
    else
        cout << "Integral solutions not possible" << endl;
}

void findIntegralSolution(int a, int b, int c, int & x, int & y) {
    if (a == 1) {
        y = 0;
        x = c;
    }
    else if (b == 1) {
        x = 0;
        y = c;
    }
    else {
        if (a > b) {
            y += x;
            findIntegralSolution(a - b, b, c, x, y);
            y -= x;
        }
        else {
            x += y;
            findIntegralSolution(a, b - a, c, x, y);
            x -= y;
        }
    }
}

int gcd(int a, int b) {
    if (a%b == 0) {
        return b;
    }
    else{
        return gcd(b, a%b);
    }
}

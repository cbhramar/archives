#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include "rational.h"

using namespace std;

void error(string msg);
int gcd(int x, int y);
string integerToString(int n);

Rational::Rational(int x, int y){
    if (y == 0) error("Division by zero is impossible");
    if (x == 0){
        num = 0;
        den = 1;
    }
    else{
        int g = gcd(abs(x), abs(y));
        num = x/g;
        den = abs(y)/g;
        if (y < 0){
            num = -num;
        }
    }
}

string Rational::toString(){
    if (den == 1){
        return integerToString(num);
    }
    else{
        return integerToString(num) + "/" + integerToString(den);
    }
}

ostream & operator<<(ostream & os, Rational rat){
    return os << rat.toString();
}

Rational operator+(Rational r1, Rational r2){
    return Rational(r1.num*r2.den + r2.num*r1.den, r1.den*r2.den);
}

Rational operator-(Rational r1, Rational r2){
    return Rational(r1.num*r2.num - r2.num*r1.den, r1.den*r2.den);
}

Rational operator*(Rational r1, Rational r2){
    return Rational(r1.num*r2.num, r1.den*r2.den);
}

Rational operator/(Rational r1, Rational r2){
    return Rational(r1.num*r2.den, r2.num*r1.den);
}
/*
Rational operator+=(Rational r2){
    num = num*r2.den + den*r2.num;
    den = den*r2.den;
}
/*
Rational & operator-=(Rational r2){
    num = num*r2.den - r2.num*den;
    den = den*r2.den;
}

Rational & operator*=(Rational r2){
    num = num*r2.num;
    den = den*r2.den;
}

Rational & operator/=(Rational r2){
    num = num*r2.den;
    den = den*r2.num;
}
*/
bool operator==(Rational r1, Rational r2){
    if (r1.num == r2.num && r1.den == r2.den){
        return true;
    }
    return false;
}

bool operator<(Rational r1, Rational r2){
    if (r2.num*r1.den - r1.num*r2.den > 0){
        return true;
    }
    return false;
}

bool operator>(Rational r1, Rational r2){
    if (r1.num*r2.den - r2.num*r1.den > 0){
        return true;
    }
    return false;
}

bool operator!=(Rational r1, Rational r2){
    return !(r1 == r2);
}

bool operator>=(Rational r1, Rational r2){
    return !(r1 < r2);
}

bool operator<=(Rational r1, Rational r2){
    return !(r1 > r2);
}

void error(string msg){
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

int gcd(int x, int y){
    int r = x%y;
    while (r != 0){
        x = y;
        y = r;
        r = x%y;
    }
    return y;
}

string integerToString(int n){
    ostringstream stream;
    stream << n;
    return stream.str();
}

int main(){
    Rational r1;
    Rational r2(5);
    Rational r3(6,8);

    cout << r1 << endl << r2 << endl << r3 << endl;
    Rational r4 = r2 + r3;
    cout << r4 << endl;
    Rational r5(1, 6), r6(1, 3), r7(1, 2);
    Rational r8 = r5 + r6 + r7;
    cout << r8 << endl;

    double d1 = 1.0/6.0, d2 = 1.0/3.0, d3 = 1.0/2.0;
    double d4 = d1 + d2 + d3;
    cout << setprecision(16) << d4 << endl;

    if (r2 == r3) cout << r2 << " = " << r3 << endl;
    else if (r2 != r3) cout << r2 << " != " << r3 << endl;

    if (r3 < r8) cout << r3 << " < " << r8 << endl;
    if (r3 > r5) cout << r3 << " > " << r5 << endl;

    return 0;
}

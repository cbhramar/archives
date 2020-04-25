#ifndef _rational_h
#define _rational_h

#include<iostream>
#include<string>

class Rational{

public:

    Rational(int x = 0, int y = 1);

    std::string toString();

    friend Rational operator+(Rational r1, Rational r2);
    friend Rational operator-(Rational r1, Rational r2);
    friend Rational operator*(Rational r1, Rational r2);
    friend Rational operator/(Rational r1, Rational r2);

//    Rational operator+=(Rational r2);
//    void & operator-=(Rational r2);
//    void & operator*=(Rational r2);
//    void & operator/=(Rational r2);

    friend bool operator==(Rational r1, Rational r2);
    friend bool operator<(Rational r1, Rational r2);
    friend bool operator>(Rational r1, Rational r2);

//    Rational operator++();

private:

    int num;
    int den;
};

std::ostream & operator<<(std::ostream & os, Rational rat);

Rational operator+(Rational r1, Rational r2);
Rational operator-(Rational r1, Rational r2);
Rational operator*(Rational r1, Rational r2);
Rational operator/(Rational r1, Rational r2);

bool operator==(Rational r1, Rational r2);
bool operator<(Rational r1, Rational r2);
bool operator>(Rational r1, Rational r2);

bool operator!=(Rational r1, Rational r2);
bool operator>=(Rational r1, Rational r2);
bool operator<=(Rational r1, Rational r2);

#endif

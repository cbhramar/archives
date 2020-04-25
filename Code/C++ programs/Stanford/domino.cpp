/* File: domino.cpp
 * Defining the member and other functions
 */

#include<string>
#include"domino.h"
#include<sstream>
#include<vector>

using namespace std;

string integerToString(int n);

Domino::Domino(){
    left = 0;
    right = 0;
}

Domino::Domino(int n, int m){
    left = n;
    right = m;
}

string Domino::toString(){
    return integerToString(left) + "-" + integerToString(right);
}

int Domino::getLeftDot(){
    return left;
}

int Domino::getRightDot(){
    return right;
}

ostream & operator<<(ostream & os, Domino dm){
    return os << dm.toString();
}

string integerToString(int n){
    ostringstream stream;
    stream << n;
    return stream.str();
}

int main(){
    for (int i = 1; i <= 6; i++){
        for (int j = i; j <= 6; j++){
            cout << Domino(i, j) << endl;
        }
    }
    return 0;
}


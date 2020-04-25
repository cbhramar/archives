#include <iostream>
#include <cmath>

using namespace std;

double squareRoot(double num);

int main(){
    cout << "Welcome to square rooters! Please provide us with your number so we can root the hell out of it :\n";
    double num;
    cin >> num;
    cout << "The square root of " << num << " is : \n" << squareRoot(num) << endl;
    return 0;
}

double squareRoot(double num){
    double g = num/2.0;
    while ( abs( g - sqrt(num)) >= 0.0001 ){
        g = 0.5*(g + (num/g));
    }
    return g;
}

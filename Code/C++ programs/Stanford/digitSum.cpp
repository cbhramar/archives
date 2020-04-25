#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

int digitsum(long n);
int digitalroot(long n);

int main(){
    cout << "Enter a digit :" << endl;
    long n;
    cin >> n;
    cout << "The sum of digits of " << n << " is " << digitsum(n) << endl;
    cout << "The digital root of " << n << " is " << digitalroot(n) << endl;

    return 0;
}

int digitsum(long n){
    if (n/10 == 0){
        return n;
    }
    else {
        return n%10 + digitsum(n/10);
    }
}

int digitalroot(long n){
    if (n < 10){
        return n;
    }
    else{
        return digitalroot(digitsum(n));
    }
}

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;

int recursiveGCD(int x, int y);

int main(){
    cout << recursiveGCD(342, 45) << endl;
}

int recursiveGCD(int x, int y){
    if (x%y == 0){
        return y;
    }
    else return recursiveGCD(y, x%y);
}

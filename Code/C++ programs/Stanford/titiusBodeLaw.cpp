#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;

double getTitiusBodeDistance(int k);
int b(int k);

int main(){
    cout << "Titius - Bode distance of first 9 planets" << endl;
//    for (int i = 1; i < 9; i--){
//        cout << setw(3) << right << getTitiusBodeDistance(i) << " AU" << endl;
//    }
    cout << getTitiusBodeDistance(10) << endl;
    return 0;
}

double getTitiusBodeDistance(int k){
    return (4 + b(k))/10.0;
}

int b(int k){
    if(k == 1) return 1;
    if(k == 2) return 3;
    else return 2*b(k - 1);
}

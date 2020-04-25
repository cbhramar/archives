#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
#include<iomanip>

using namespace std;

string addCommas(string digits);

int main(){
    while (true){
        string digits;
        cout << "Enter a number : \n";
        getline(cin, digits);
        if (digits == "") break;
        cout << addCommas(digits) << endl;
    }
    return 0;
}

string addCommas(string digits){
    string str = digits;
    int counter = 0;
    for (int i = str.length() - 1; i >= 0; i--){
        counter ++;
        if (counter == 3 && i != 0){
            str.insert(i,",");
            counter = 0;
        }
    }
    return str;
}

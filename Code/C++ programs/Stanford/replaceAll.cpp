#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
#include<iomanip>

using namespace std;

string replaceAll(string str, char c1, char c2);

int main(){
    cout << "Enter string :\n";
    string str;
    getline(cin, str);
    char c1, c2;
    cout << "Enter char to be replaced : \n";
    cin >> c1;
    cout << "Enter new char to be added : \n";
    cin >> c2;
    cout << "Your new string is : \n" << replaceAll(str, c1, c2);
    return 0;
}

string replaceAll(string str, char c1, char c2){
    string str2 = "";
    for (int i = 0; i < str.length(); i++){
        if(str[i] != c1){
            str2 += str[i];
        }
        else{
            str2 += c2;
        }
    }
    return str2;
}

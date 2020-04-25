#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

string Reverse(string str);
string reverseSubstr(string str, int p, int q);

int main(){
    string line;
    cout << "Enter a lin : " << endl;
    getline(cin, line);
    cout << Reverse(line) << endl;

    return 0;
}

string Reverse(string str){
    return reverseSubstr(str, 0, str.length() - 1);
}

string reverseSubstr(string str, int p, int q){
    if (p >= q) return str;
    else {
        char c = str[p];
        str[p] = str[q];
        str[q] = c;
        return reverseSubstr(str, p + 1, q - 1);
    }
}

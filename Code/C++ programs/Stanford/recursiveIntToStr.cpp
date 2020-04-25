#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<cstdlib>
#include<algorithm>

using namespace std;

string integerToString(int n);
string Reverse(string str);
string reverseSubstr(string str, int p, int q);

int main() {
    cout << "Enter the number you want to stringify : " << endl;
    int n;
    cin >> n;
    string str = integerToString(n);
    cout << Reverse(str) << endl;
}

string integerToString(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    if (n == 2) return "2";
    if (n == 3) return "3";
    if (n == 4) return "4";
    if (n == 5) return "5";
    if (n == 6) return "6";
    if (n == 7) return "7";
    if (n == 8) return "8";
    if (n == 9) return "9";
    else return integerToString(n%10) + integerToString(n/10);

}

string Reverse(string str) {
    return reverseSubstr(str, 0, str.length() - 1);
}

string reverseSubstr(string str, int p, int q) {
    if (p >= q) return str;
    else {
        char c = str[p];
        str[p] = str[q];
        str[q] = c;
        return reverseSubstr(str, p + 1, q - 1);
    }
}

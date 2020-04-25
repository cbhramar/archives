/*
 * File: TrimString.cpp
 * This program takes an input line and returns the line removing any spaces that might have been part of
 * the original line
 */
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

void trimString(string & str);

int main() {
    cout << "Enter the string you want to trim in the line below \n";
    string line;
    getline(cin, line);
    trimString(line);
    cout << "Your newly trimmed string is :\n";
    cout << line << endl;
    return 0;
}

void trimString(string & str) {
    for (int i = str.length() - 1; i >= 0; i--) {
        if (isspace(str[i])){
            str.erase(i, 1);
        }
    }
}

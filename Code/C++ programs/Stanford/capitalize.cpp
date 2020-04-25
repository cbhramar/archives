#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

void capitalize(string & str);

int main() {
    cout << "Enter your uncultured string: \n";
    string str;
    cin >> str;
    capitalize(str);
    cout << "Your new and improved string is : \n" << str << endl;
    return 0;
}

void capitalize(string & str) {
    if(islower(str[0])) {
        str[0] = str[0] + 'A' - 'a';
    }
    for (int i = 1; i < str.length(); i++) {
        char ch = str[i];
        if (isupper(ch)) {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

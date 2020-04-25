#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
#include<iomanip>

using namespace std;

bool palindromeSentence(string line);
bool palindrome(string str);

int main(){
    cout << "This program tests for sentence palindromes \n";
    cout << "Exit program by leaving a blank line \n";
    while (true){
        cout << "Enter a line to test\n";
        string line;
        getline(cin, line);
        if (line.length() == 0)
            break;

        if (palindromeSentence(line)){
            cout << "This is indeed a palindrome!" << endl;
        }
        else{
            cout << "This is not a palindrome, Sorry :(" << endl;
        }
    }
    return 0;
}

bool palindromeSentence(string line){
    string str = "";
    for (int i = 0; i < line.length(); i++){
        if (isalnum(line[i])){
            if(isupper(line[i])){
                str += line[i] - 'A' + 'a';
            }
            else
                str += line[i];
        }
    }
    return palindrome(str);
}

bool palindrome(string str){
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
    if (str[i] != str[n - i - 1]) return false;
    }
    return true;
}

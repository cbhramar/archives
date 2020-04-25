#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main() {
    cout << "Enter the wannabe palindrome \n";
    string str;
    cin >> str;
    if (isPalindrome(str)) {
        cout << "My, my. This really is a palindrome\n";
    }
    else
        cout << "This one's a dud \n";
    return 0;
}

bool isPalindrome(string str) {
    int n = str.length();
    for (int i=0; i<(n/2); i++) {
        if (str[i] != str[n-i-1]) 
            return false;
    }
    return true;
}

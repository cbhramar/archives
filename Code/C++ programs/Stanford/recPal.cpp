#include<iostream>
#include<cmath>

using namespace std;

bool isStringPal(string str);
bool isSubStringPal(string str, int p1, int p2);

int main()
{
    cout << "Enter word to be checked \n";
    string str;
    cin >> str;
    if (isStringPal(str))
    {
        cout << "This is indeed a palindrome\n";
    }
    else
        cout << "Not a palindrome \n";
    return 0;
}

bool isSubStringPal(string str, int p1, int p2)
{
    if (p1 >= p2)
        return true;
    else
        return (str[p1] == str[p2]) && isSubStringPal(str, p1 + 1, p2 - 1);
}

bool isStringPal(string str)
{
    return isSubStringPal(str, 0, str.length() - 1);
}

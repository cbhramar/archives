#include <iostream>
#include <string>

using namespace std;

void removeChars(string &str, string takeaway);

int main() {
    cout << "Enter the word to operated upon: \n";
    string str;
    cin >> str;
    string takeaway;
    cout << "Enter the stone to be removed: \n";
    cin >> takeaway;
    removeChars(str, takeaway);
    cout << "Your newly rejuvenated word is: " << endl << str << endl;
    return 0;
}

void removeChars(string &str, string takeaway) {
    int len = takeaway.length();
/*    char[len];
    for (int i=0; i<len; i++)
    {
        char[i] = takeaway[i];
    }   */

    int strlen = str.length();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < strlen; j++) {
            if(str[j] == takeaway[i]) {
                str.erase(j,1);
            }
        }
    }
}

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string invertKey(string key);

int main() {
    cout << "Enter your enryption key :\n";
    string key;
    getline(cin, key);
    cout << "Decription key is:\n" << invertKey(key) << endl;
    return 0;
}

string invertKey(string key) {
    string ikey = ALPHABET;
    for (int i = 0; i < key.length(); i++) {
        for (int j = 0; j < ALPHABET.length(); j++) {
            if (key[i] == ALPHABET[j]) {
                ikey[j] = ALPHABET[i];
            }
        }
    }
    return ikey;
}

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string letterSubCipher(string msg, string key);

int main(){
    cout << "Enter 26 letter key :\n";
    string key;
    getline(cin, key);
    cout << "Enter message :\n";
    string msg;
    getline(cin, msg);
    string lsc = letterSubCipher(msg, key);
    cout << "Encoded message :\n" << lsc << endl;
}

string letterSubCipher(string msg, string key){
    string lsc = msg;
    for (int i = 0; i < lsc.length(); i++){
        char ch = lsc[i];
        for (int j = 0; j < ALPHABET.length(); j++){
            if (ch == ALPHABET[j]){
                lsc[i] = key[j];
            }
        }
    }
    return lsc;
}

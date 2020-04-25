#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
#include<iomanip>

using namespace std;

string removeDoubledLetters(string word);

int main(){
    cout << "Enter the word :\n";
    string word;
    cin >> word;
    cout << "Your word in the new era would be :\n" << removeDoubledLetters(word) << endl;
    return 0;
}

string removeDoubledLetters(string word){
    string newstr = "";
    for (int i = 0; i < word.length(); i++){
        if(word[i] != word[i + 1]){
            newstr += word[i];
        }
    }
    return newstr;
}

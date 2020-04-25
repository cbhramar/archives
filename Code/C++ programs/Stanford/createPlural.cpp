#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
#include<iomanip>

using namespace std;

string plural(string word);

int main(){
    cout << "Enter the word you want to pluralify :\n";
    string word;
    cin >> word;
    cout << "The plural of " << word << " is : \n" << plural(word) << endl;
    return 0;
}

string plural(string word){
    string plr = word;
    plr.erase(plr.length() - 1, 1);
    char ch = word[word.length() - 1];
    if (ch == 's' || ch == 'x' || ch == 'z'){
        plr += ch;
        plr += "es";
    }
    else if (ch == 'h'){
        char ch2 = word[word.length() - 2];
        if (ch2 == 'c' || ch2 == 's'){
            plr += ch;
            plr += "es";
        }
    }
    else if (ch == 'y'){
        char ch2 = word[word.length() - 2];
        if (!(ch2 == 'a' || ch2 == 'e' || ch2 == 'i' || ch2 == 'o' || ch2 == 'u')){
            plr += "ies";
        }
    }
    else{
        plr += ch;
        plr += "s";
    }
    return plr;
}

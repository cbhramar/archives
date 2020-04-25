#include<iostream>
#include<string>
#include<cctype>

using namespace std;

string obenglobish(string word);

int main(){
    while(true){
        string word;
        cout << "Enter a word :\n";
        getline(cin, word);
        if (word.length() == 0) break;
        string trans = obenglobish(word);
        cout << word << " -> " << trans << endl;
    }
    return 0;
}

string obenglobish(string word){
    string trans;
    trans = word;
    for (int i = trans.length() - 1; i >= 0; i--){
        char ch = trans[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch =='U'){
            char ch2 = trans[i - 1];
            if (i == trans.length() - 1 && (ch == 'e' || ch == 'E')){
                continue;
            }
            else if (ch2 == 'a' || ch2 == 'e' || ch2 == 'i' || ch2 == 'o' || ch2 == 'u' || ch2 == 'A' || ch2 == 'E' || ch2 == 'I' || ch2 == 'O' || ch2 =='U'){
                continue;
            }
            else{
                trans.insert(i, "ob");
            }
        }
    }
    return trans;
}

#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
#include<iomanip>

using namespace std;

int score(string word);

int main(){
    cout << "Enter your scrabble word (only UPPERCASE alphabets counted) \n";
    string word;
    getline(cin, word);
    cout << "Your scrabble score is " << score(word) << endl;
    return 0;
}

int score(string word){
    int sc = 0;
    for (int i = 0; i < word.length(); i++){
        char ch = word[i];
        if (isupper(ch)){
            switch (ch){
                case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U':
                    sc += 1;
                    break;
                case 'D': case 'G':
                    sc += 2;
                    break;
                case 'B': case 'C': case 'M': case 'P':
                    sc += 3;
                    break;
                case 'F': case 'H': case 'V': case 'W': case 'Y':
                    sc += 4;
                    break;
                case 'K':
                    sc += 5;
                    break;
                case 'J': case 'X':
                    sc += 8;
                    break;
                case 'Q': case 'Z':
                    sc += 10;
                    break;
            }
        }
    }
    return sc;
}

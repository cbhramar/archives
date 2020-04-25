#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

string acronym(string line);

int main(){
    string line;
    cout << "Enter the thing you want to acronymise :\n";
    getline(cin, line);
    cout << "Your acronym is : \n";
    string anym;
    anym = acronym(line);
    cout << anym;
    cout << endl << "See ya later" << endl;
    return 0;
}

string acronym(string line){
    string acr = "";
    for (int i = 0; i < line.length(); i++){
        if (i == 0 && isalpha(line[i])){
            if (isupper(line[i])){
                acr += line[i];
            }
            else{
                char ch = line[i] - 'a' + 'A';
                acr += ch;
            }
        }
        else if (isalpha(line[i]) && !isalpha(line[i-1])){
            if (isupper(line[i])){
                acr += line[i];
            }
            else{
                char ch = line[i] - 'a' + 'A';
                acr += ch;
            }
        }
    }
    return acr;
}

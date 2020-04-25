#include<iostream>
#include<string>

using namespace std;

bool endsWith(string str, string suffix);

int main(){
    cout << "Enter the string : ";
    string word;
    cin >> word;
//    cout << endl;
    cout << "Enter the suffix to check for : ";
    string suffix;
    cin >> suffix;
//    cout << endl;
    if (endsWith(word, suffix)){
        cout << "The word indeed does end with the suffix" << endl;
    }
    else {
        cout << "The word doesn't end with the provided suffix " << endl;
    }
    return 0;
}

bool endsWith(string str, string suffix){
    for (int i = 1; i <= suffix.length(); i++){
        if (str[(str.length() - i)] != suffix[suffix.length() - i]){
            return false;
        }
    }
    return true;
}

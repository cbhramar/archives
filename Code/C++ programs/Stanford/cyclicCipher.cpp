#include<iostream>
#include<iomanip>
#include<string>
#include<cctype>

using namespace std;

string encodeCaesarCipher(string str, int shift);

int main(){
    cout << "Encode a message using Caesar cipher !\n";
        int shift;
        cout << "Enter the shift : \n";
        cin >> shift;
        cout << "Enter the message to be coded : \n";
        string str;
//        getline(cin, str);
        cin >> str;
        string ecc = encodeCaesarCipher(str, shift);
        cout << "Encoded Message : \n" << ecc << endl;
    return 0;
}

string encodeCaesarCipher(string str, int shift){
    string ecc = str;
    char sh = shift;
    char ts = 26;
    for (int i = 0; i < ecc.length(); i++){
        char ch = ecc[i];
        if (isalpha(ch)){
            if (islower(ch)){
                if (ch + sh <= 'z' && ch + sh >= 'a'){
                    ecc[i] = ecc[i] + sh;
                }
                else if ( ch + sh >= 'z'){
                    ecc[i] = (ecc[i] + sh)%'z' + 'a' - 1;
                }
                else if (ch + sh <= 'a'){
                    ecc[i] = ecc[i] + sh + ts;
                }
            }
            else if (isupper(ch)){
                if (ch + sh <= 'Z' && ch + sh >= 'A'){
                    ecc[i] = ecc[i] + sh;
                }
                else if ( ch + sh >= 'Z'){
                    ecc[i] = (ecc[i] + sh)%'Z' + 'A' - 1;
                }
                else if (ch + sh <= 'A'){
                    ecc[i] = ecc[i] + sh + ts;
                }
            }
        }
    }
    return ecc;
}

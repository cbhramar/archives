#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

vector<string> generatePermutations(string str);

int main(){
    string str;
    cout << "Enter your string : " << endl;
    getline(cin, str);
    vector<string> vec = generatePermutations(str);
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << "   ";
    }

    return 0;
}

vector<string> generatePermutations(string str){
    vector<string> result;
    if (str == "") result.push_back("");
    else{
        string ch = str.substr(0, 1);
        string rest = str.substr(1);
        for (int i = 0; i < generatePermutations(rest).size(); i++){
            for (int i = 0; i < generatePermutations(rest)[i].length(); i++){
               string newstr = rest.substr(0, i) + ch + rest.substr(i + 1);
                result.push_back(rest.insert(i, ch));
//                cout << rest.substr(0, i) + ch + rest.substr(i + 1) << endl;
            }
        }

    }
    return result;
}

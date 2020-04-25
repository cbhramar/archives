#include<iostream>
#include<fstream>
#include<string>
#include<cctype>

using namespace std;

string defaultExtension(string filename, string ext);

int main(){
    string filename;
    cout << "Input filename, with or without extension :" << endl;
    getline(cin, filename);
    cout << "Your chosen extension ? : \n";
    string ext;
    cin >> ext;
    string str = defaultExtension(filename, ext);
    cout << "Correct filename is \n" << str << endl;
    return 0;
}

string defaultExtension(string filename, string ext){
    string str;
    int period = -1;
    for (int i = 0; i < filename.length(); i++){
        if (filename[i] == '.'){
            period = i;
        }
    }
    if (period == -1){
        str = filename + "." + ext;
    }
    else if (period != -1 && ext[0] == '*'){
        str = filename.substr(0, period + 1) + ext.substr(1);
    }
    else if (period != -1 && ext[0] != '*'){
        str = filename;
    }
    return str;
}

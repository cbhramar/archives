#include<iostream>
#include<string>

using namespace std;

// If the program requires that the file EXIST, I'll have to include fstream and call for !infile.fail()

void getRootAndExtension(string filename, string & root, string & extension);

int main(){
    cout << "Enter File name : \n";
    string filename;
    getline(cin, filename);
    string root, extension;
    getRootAndExtension(filename, root, extension);
    cout << "Root - " << root << endl << "Extension - " << extension << endl;
    return 0;
}

void getRootAndExtension(string filename, string & root, string & extension){
    int period;
    for (int i = 0; i < filename.length(); i++){
        if (filename[i] == '.') period = i;
    }
    root = filename.substr(0, period);
    extension = filename.substr(period + 1);
}

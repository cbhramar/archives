#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string promptUserForFile(ifstream & infile, string prompt );

int main(){
    ifstream infile;
    promptUserForFile(infile, "Input File : ");
    char ch;
    while (infile.get(ch)){
        cout.put(ch);
    }
    infile.clear();
/*    string line;
    while (getline(infile, line)){
        cout << line << endl;
    } */
    infile.close();

    return 0;
}

string promptUserForFile(ifstream & infile, string prompt ){
    while(true){
        cout << prompt;
        string filename;
        getline(cin, filename);
        infile.open(filename.c_str());
        if (!infile.fail()) return filename;
        infile.clear();
        cout << "Unable to open that file. Try again :" << endl;
        if (prompt =="") prompt = "Input File : ";
    }
}

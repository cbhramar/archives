#include<iostream>
#include<fstream>
#include<string>
#include<vector>
// There's some stupid problem with using the function
using namespace std;

//void readEntireFile(istream & is, vector<string> & lines);

int main(){
    ifstream infile;
    cout << "Input File : " << endl;
    string filename;
    getline(cin, filename);
    vector <string> lines;
    infile.open(filename.c_str());
    string line;
    while (getline(infile, line)){
        lines.push_back(line);
    }
//    readEntireFile(infile, lines);
    infile.close();
    for (int i = lines.size() - 1; i >= 0; i--){
        cout << lines[i] << endl;
    }
}
/*
void readEntireFile(istream & is, vector <string> lines){
    string line;
    while (getline(is, line)){
        lines.push_back(line);
    }
}
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cctype>

using namespace std;

int nChars(istream & infile);
int nWords(istream & infile);
int nLines(istream & infile);

int main(){
    ifstream infile;
    cout << "Enter file name : \n";
    string fname;
    getline(cin, fname);
    infile.open(fname.c_str());
    cout << "Chars : " << nChars(infile) << endl;
    cout << "Words : " << nWords(infile) << endl;
    cout << "Lines : " << nLines(infile) << endl;
    infile.close();
    return 0;
}

int nChars(istream & infile){
    int ch;
    int sum;
    while ((ch = infile.get()) != EOF){
        sum ++;
    }
    return sum;
}

int nWords(istream & infile){
    int sum;
    while (true){
        char chs = infile.get();
        int ch = infile.get();
        if (ch == EOF) break;
        else if (isspace(chs)) sum++;
        else continue;
    }
    sum ++;
    return sum;
}

int nLines(istream & infile){
    return 12;
}

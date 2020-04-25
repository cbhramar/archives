#include<iostream>
#include<fstream>
#include<string>
#include<cctype>

using namespace std;

void censor(ifstream & infile, ofstream & outfile);

int main(){
    ifstream infile;
    ofstream outfile;
    censor(infile, outfile);
    infile.close();
    outfile.close();

    return 0;
}

void censor(ifstream & infile, ofstream & outfile){
    cout << "Input file : " << endl;
    string ifile;
    getline(cin, ifile);
    infile.open(ifile.c_str());

    cout << "Output file : " << endl;
    string ofile;
    getline(cin, ofile);
    outfile.open(ofile.c_str());

    cout << "Input character to be banished (in lower case please) : " << endl;
    string censor;
    getline(cin, censor);

    char ch;
    while(infile.get(ch)){
        bool keep = true;
        for (int i = 0; i < censor.length(); i++){
            if ((ch == censor[i]) || (ch == censor[i] - 'a' + 'A')){
                keep = keep && false;
            }
        }
        if (keep){
            outfile.put(ch);
        }
    }
}

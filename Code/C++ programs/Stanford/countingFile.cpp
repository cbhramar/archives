#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void countfile(ifstream & infile, int & csum, int & wsum, int & lsum);

int main(){
    ifstream infile;
    int csum = 0, wsum = 0, lsum = 0;
    countfile(infile, csum, wsum, lsum);
    cout << "Chars - " << csum << endl;
    cout << "Words - " << wsum << endl;
    cout << "Lines - " << lsum << endl;
    return 0;
}


void countfile(ifstream & infile, int & csum, int & wsum, int & lsum){
    cout  << "Input file : \n";
    string filename;
    getline(cin, filename);
    infile.open(filename.c_str());
    int ch;
    while ((ch = infile.get()) != EOF){
        csum ++;
        if (isspace(ch)){
            wsum ++;
        }
        if (ch == '\n'){
            lsum ++;
        }
    }
}

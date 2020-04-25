#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void removeComments(ifstream & infile, ofstream & outfile);

int main(){
    ifstream infile;
    ofstream outfile;
    removeComments(infile, outfile);
    infile.close();
    return 0;
}

void removeComments(ifstream & infile, ofstream & outfile){
    cout << "Input file : " << endl;
    string filename;
    getline(cin, filename);
    infile.open(filename.c_str());
    char ch;
    while (infile.get(ch)){
        bool keep = true;
        if (ch == '/'){
            char ch1;
            while (infile.get(ch1)){
                if (ch1 == '/'){
                // Deal with single line comments here
                    while (ch != '\n'){
                        keep = false;
                    }
                }
                else if (ch1 == '*'){
                /* Deal with multiline
                 * comments over here.
                 */
                }
            }
        }
        if (keep){
            outfile.put(ch);
        }
    }
}

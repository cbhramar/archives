#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int findDNAMatch(string gene, string strand, int start = 0);

int main(){
    cout << "Enter part of gene :\n";
    string gene;
    cin >> gene;
    cout << "Enter target strand :\n";
    string strand;
    cin >> strand;
    int match = findDNAMatch(gene, strand, 0);
    cout << "First match occurs at position : " << match << endl;
    return 0;
}

int findDNAMatch(string gene, string strand, int start){
    string pattern = strand;
    for (int i = 0; i < pattern.length(); i++){
        char ch = pattern[i];
        if (ch == 'A'){
            pattern[i] = 'T';
        }
        else if (ch == 'T'){
            pattern[i] = 'A';
        }
        else if (ch == 'G'){
            pattern[i] = 'C';
        }
        else if (ch == 'C'){
            pattern[i] = 'G';
        }
    }
    int n = gene.find(pattern, start);
    if (n!= string::npos){
        return n;
    }
    else
        return -1;
}

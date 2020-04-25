#include<iostream>
#include<string>
#include<cctype>

using namespace std;

string wordToPiglatin(string word);
string lineToPiglatin(string line);
int firstVowel(string word);

int main()
{
/*    cout << "Enter the string to be translated\n";
 *    string word;
 *    cin >> word;
 *    cout << "The translated word is : " << wordToPiglatin(word) << endl << endl;
 */
    cout << "Enter the line to be translated\n";
    string line;
    getline(cin, line);
    cout << "The translated line is : \n";
    cout << lineToPiglatin(line) << endl;
    return 0;
}

int firstVowel(string word)
{
    int i=0;
    int k=-1;
    for(int j=0; j<word.length(); j++)
    {
        if( word[j] =='a' || word[j] =='A' || word[j] =='e' || word[j] =='E' || word[j] =='i' || word[j] =='I' || word[j] =='o' || word[j] =='O' || word[j] =='u' || word[j] =='U')
        {
            i = j;
            return i;
        }
    }
    return k;
}

string wordToPiglatin(string word)
{
    string translation = "";
    if (firstVowel(word) == -1)
    {
        translation = word;
        return translation;
    }
    else if (firstVowel(word) == 0)
    {
        string vsuff = "way";
        translation = word + vsuff;
        return translation;
    }
    else if (firstVowel(word) > 0)
    {
        string p1 = word.substr(3);
        string p2 = word.substr(0, 3);
        if (isupper(p2[0])){
            p2[0] = p2[0] - 'A' + 'a';
            if (p1 != ""){
                p1[0] = p1[0] - 'a' + 'A';
            }
            else{
                p2[0] = p2[0] - 'a' + 'A';
            }
        }
        string p = p1 + p2;
        string csuff = "ay";
        translation = p + csuff;
        return translation;
    }
}

string lineToPiglatin(string line)
{
    string translation = "";
    int start = -1;
    for (int i=0; i<line.length(); i++)
    {
        char ch = line[i];
        if (isalpha(ch))
        {
            if (start == -1)
                start = i;
        }
        else
        {
            if (start >= 0)
            {
                translation += wordToPiglatin(line.substr(start, i-start));
                start = -1;
            }
            translation += ch;
        }
    }
    if (start >= 0)
        translation += wordToPiglatin(line.substr(start));
    return translation;
}

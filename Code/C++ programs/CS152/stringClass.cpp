#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

void scopy ( char destination[], const char source[], int dstart = 0)
{
    int i;
    for ( i = 0; source[i] != '\0'; i++)
        destination[ dstart + i] = source[i]; // copying all characters except \0
    destination[ dstart + i] = source[i]; // copying \0 , the trouble is here probably
}


int length ( const char source[])
{
    int l = 0;
    for ( int i = 0; source[i] != '\0'; i++)
        l++;
    return l;
}


class String
{
public :
    char *sptr; // variable memory allocation on heap

    String() // constructor
    {
        sptr = NULL;
    }

    String ( const String &rhs) // copy constructor
    {
        sptr = new char[ length(rhs.sptr) + 1];
        scopy ( sptr, rhs.sptr, 0);
        sptr[ length(rhs.sptr)] = rhs.sptr[ length(rhs.sptr)];
    }

    String& operator = ( String &rhs) // equating a String to a String
    {
        delete [] sptr;
        sptr = new char[ length( rhs.sptr ) + 1];
        scopy( sptr, rhs.sptr, 0);
        sptr[ length(rhs.sptr)] = rhs.sptr[ length(rhs.sptr)];
        return *this;
    }

    String& operator = ( const char* rhs) // equating a String to a char *
    {
        delete [] sptr;
        sptr = new char[ length(rhs) + 1];
        scopy( sptr, rhs, 0);
        sptr[ length(rhs)] = rhs[ length(rhs)];
        return *this;
    }

    String operator + ( const String &rhs) // adds two Strings . why wont you work goddamit !!??!
    {
        String res;
        res.sptr = new char[ length(sptr) + length(rhs.sptr) + 1];
        //scopy( res.sptr, sptr, 0);
        //scopy( res.sptr, rhs.sptr, length(sptr));
        for ( int i = 0; i < length(sptr); i++)
        {
            res.sptr[i] = sptr[i];
        }
        for ( int i = length(sptr); i<( length(sptr) + length(rhs.sptr) ); i++)
        {
            res.sptr[i] = rhs.sptr[ i - length(sptr) ];
        }
        res.sptr[length(sptr) + length(rhs.sptr)] = rhs.sptr[length(rhs.sptr)];
        return res;
    }

    int size() const // returns length
    {
        return length(sptr);
    }

    char& operator [] (int i) const // accesing the ith element
    {
        return sptr[i];
    }

    void print() // printing the sequence of characters
    {
        if ( sptr != NULL) cout << sptr << endl;
        else cout << "NULL" << endl;
    }

    ~String() // destructor
    {
        delete[] sptr;
    }
};


String lcase( const String &arg)
{
    String res = arg;
    for ( int i = 0; i<length(res.sptr) ; i++)
    {
        if( res[i] >= 'A' && res[i] <= 'Z') res[i] += 'a' - 'A';
    }
    return res;
}


int main()
{
    String a,b;
    a = "PqR";
    b = a;
    cout << "size of b : \n";
    cout << b.size() << endl;
    cout << "printing a : \n";
    a.print();
    cout << "third element of String a : \n";
    cout << a[2] << endl;
    cout << "printing String b = a using operator overloading : \n";
    b.print();
    cout << "String c = a + b : \n";
    String c = a + b;
    c.print();
    String d(a);
    cout << "using copy constructor to initialize String d to a : \n";
    d.print();
    cout << "using the lowercase function \n";
    lcase(d).print();
    String e;
}

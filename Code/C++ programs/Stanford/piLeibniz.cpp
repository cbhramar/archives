#include<iostream>
#include<cmath>

using namespace std;

int odd(int n);

int main()
{
    long double pi = 0;
//    long double term = 1;
    for(int i = 0; i<10000; i++)
    {
        pi = pi + pow(-1, i)*(double(1)/odd(i));
    }
    pi = pi*4;
    cout << pi;
}

int odd(int n)
{
    int m = 2*n + 1;
    return m;
}

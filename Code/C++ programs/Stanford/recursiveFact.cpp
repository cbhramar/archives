#include<iostream>
#include<cmath>

using namespace std;

int fact(int n);

int main()
{
    int n;
    cout << "Enter the num :\n";
    cin >> n;
    cout << n << "! is :\n";
    cout << fact(n);
    return 1;
}

int fact(int n)
{
    if(n == 0)
        return 1;
    else
        return n*fact(n-1);
}

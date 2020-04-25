#include<iostream>
#include<cmath>

using namespace std;

int gcd(int m, int n)
{
    if(n > m)
    {
        int t = 0;
        t = m;
        m = n;
        n = t;
    };

    if (m%n == 0)
        return n;
    else
    {
        int r = m%n;
        gcd(n, r);
    }
}

int Egcd(int x, int y)
{
    int r = x%y;
    while(r != 0)
    {
        x = y;
        y = r;
        r = x%y;
    }
    return y;
}

int main()
{
    int n, m;
    cout << "Enter two numbers\n";
    cin >> n >> m;
    cout << gcd(m,n) << endl;
    cout << Egcd(m, n);
    return 0;
}

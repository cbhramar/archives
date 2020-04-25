#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int permutation(int n, int k);

int main()
{
    cout << "Enter n, k in that order\n";
    int n, k;
    cin >> n >> k;
    cout << "P(n, k) is : " << permutation(n, k) << endl;
    return 0;
}

int permutation(int n, int k)
{
    int p = 1;
    for (int i = n - k + 1; i <= n; i++)
    {
        p *= i;
    }
    return p;
}

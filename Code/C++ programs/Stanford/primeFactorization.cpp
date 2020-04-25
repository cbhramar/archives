#include<iostream>
#include<cmath>

using namespace std;

bool is_prime(int n)
{
    if(n == 1) return true;
    for(int i = 2; i<n; i++)
    {
        if(n%i == 0) return false;
    }
    return true;
}

int prime(int i)
{
    if(is_prime(i))
        return i;
    else
        return 86457;
}

//void prime_til(int n);

void prime_factors(int n);

int main()
{
    cout << "Enter a number\n";
    int n;
    cin >> n;
    prime_factors(n);
    cout << "1\n";
    return 0;
}

void prime_factors(int n)
{
    if(is_prime (n))
    {
        cout << n <<"*";
        return;
    }
    else
    {
        for(int i = 2; i<n; i++)
        {
            if(n % prime(i) == 0)
            {
                cout << prime(i) <<"*";
                n = n/prime(i);
                prime_factors(n);
                return;
            }
        }
    }
}

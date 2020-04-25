#include<iostream>
#include<cmath>

using namespace std;

const int SENTINEL = 1;

void create_hailstone_sequence(int n);

int main()
{
    int num;
    cout << "Enter the number you want to create the hailstone sequence from\n";
    cin >> num;
    create_hailstone_sequence(num);
}

void create_hailstone_sequence(int n)
{
    while(true)
    {
        if( n%2 == 0)
        {
            n = n/2;
            cout << "Since " << 2*n << " is even, divide it by 2 to get " << n << endl;
        }
        else if( n != SENTINEL && n%2 == 1)
        {
            n = 3*n + 1;
            cout << "Since " << (n - 1)/3 << " is odd, multiply it by 3 and add 1 to get " << n << endl;
        }
        else if( n == SENTINEL)
        {
            cout << "n has reached 1; terminating the hailstone sequence.\n";
            break;
        }
    }
}

#include<iostream>
#include<cmath>

using namespace std;

const double W = 0.00001;

double H(double x);

int main()
{
    double x = 0;
    double pi = 0;
    while(x < 2.0)
    {
        pi = pi + H(x)*W;
        x = x + W;
    }
    cout << pi;
    return 0;
}

double H(double x)
{
   double r;
   r = sqrt(4 - x*x);
   return r;
}

#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

void get_coeffs(double &a, double &b, double &c);
void solve(double &a, double &b, double &c, double &r1, double &r2);
void print_roots(double &r1, double &r2);
void error(string msg);

int main()
{
    double a, b, c, r1, r2;
    get_coeffs(a, b, c);
    solve(a, b, c, r1, r2);
    print_roots(r1, r2);
    return 0;
}

void get_coeffs(double &a, double &b, double &c)
{
    cout << "Enter the coeffecients of the quadratic equation in order:\n";
    cin >> a >> b >> c;
}

void solve(double &a, double &b, double &c, double &r1, double &r2)
{
    if( a==0 ) error("The first coefficient must not be zero :|");
    double D = b*b - 4*a*c;
    if( D<0 ) error("No real roots :/");
    r1 = ( -b + sqrt(D))/( 2*a );
    r2 = ( -b - sqrt(D))/( 2*a );
}

void print_roots(double &r1, double &r2)
{
    cout << "The roots are: " << r1 << "    " << r2 << " :-)" << endl;
}

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

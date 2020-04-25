#include <iostream>
#include <cmath>

using namespace std;

int additiveSequence(int n, int t0, int t1);
int fib(int n);

int main() {
    cout << "Enter the index :\n";
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}

int additiveSequence(int n, int t0, int t1) {
    if(n == 0)
        return t0;
    else if(n == 1)
        return t1;
    else
        return additiveSequence(n - 1, t1, t0 + t1);
}

int fib(int n) {
    return additiveSequence(n, 0, 1);
}

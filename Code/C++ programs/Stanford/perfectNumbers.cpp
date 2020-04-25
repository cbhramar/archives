#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

bool isPerfect(int n);

int main() {
    int start;
    cout << "Enter strarting number: " << endl;
    cin >> start;

    int end;
    cout << "Enter enging number: " << endl;
    cin >> end;

    while (start > end) {
        cout << "Please enter the starting and ending points in the right order, or choose different numbers: " << endl;
        cin >> start >> end;
    }

    for (int i = start; i < end; ++i) {
        if(isPerfect(i)) {
            cout << i  << " is a Perfect Number" << endl;
        }
    }
    return 0;
}

bool isPerfect(int n) {
    int total = 0;
    for(int i = 1; i < n; ++i) {
        if( n%i == 0) {
            total = total + i;
        }
    }
    if (total == n)
        return true;
    else
        return false;
}

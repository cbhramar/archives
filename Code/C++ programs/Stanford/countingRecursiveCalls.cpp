#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int countfib_1(int n);
int countfib_2(int n, int t0, int t1);

int main(){
    cout << " n " << "     " << " fib1 " << "     " << " fib2 " << endl;
    cout << "---" << "     " << "------" << "     " << "------" << endl;
    for (int i = 0; i < 20; i++){
        cout << right << setw(2) << i << "    " << setw(5) << countfib_1(i) << "    " << setw(5) << countfib_2(i, 0, 1) << endl;
    }
    return 0;
}

int countfib_2(int n, int t0, int t1){
    int sum = 0;
    if (n == 0) return ++sum;
    if (n == 1) return ++sum;
    else sum += 1 + countfib_2(n-1, t1, t0 + t1);
    return sum;
}

int countfib_1(int n){
    int sum = 0;
    if (n == 0) return ++sum;
    if (n == 1) return ++sum;
    else {
        sum += 1 + countfib_1(n - 1) + countfib_1(n - 2);
    }
    return sum;
}

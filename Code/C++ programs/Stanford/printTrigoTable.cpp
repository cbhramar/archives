#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

const double PI = 3.141592653;

void printTrigoTable();

int main() {
    printTrigoTable();
    return 0;
}

void printTrigoTable() {
    cout << " theta | sin(theta) | cos(theta) |" << endl;
    cout << "-------+------------+------------+" << endl;
    for (int i = -90; i <= 90; i += 15) {
        double degree = i*(PI/180.0);
        cout << right << setw(5) << i << "  | " << right << fixed << setprecision(7) << setw(10) << sin(degree) << " | " << setprecision(8) << setw(8) << cos(degree) << " |" << endl;
    }
}

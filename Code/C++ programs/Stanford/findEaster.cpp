#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

void findEaster(int year, string &month, int &day);

int main() {
    cout << "Welcom to ye olde Easter finding services for the 18th and 19th century. Please choose a year: \n";
    int year;
    cin >> year;
    string month;
    int day;
    cout << "Please wait while your Easter is being calculated ... \n";
    findEaster(year, month, day);
    cout << "Easter for the year " << year << " lies on " << month << " " << day << endl;
    return 0;
}

void findEaster(int year, string &month, int &day) {
    int a, b, c;
    a = year%19;
    b = year%4;
    c = year%7;

    int d;
    d = ((19*a) + 23)%30;

    int e;
    if (year < 1800 && year >= 1700)
    {
        e = ((2*b) + (4*c) + (6*d) + 3)%7;
    }
    else if ( year < 1900 && year >= 1800)
    {
        e = ((2*b) + (4*c) + (6*d) + 4)%7;
    }

    if (d + e <= 9)
    {
        month = "March";
        day = 22 + d + e;
    }
    else
    {
        month = "April";
        day = d + e - 9;
    }
}

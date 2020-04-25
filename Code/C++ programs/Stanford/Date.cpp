#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<sstream>

using namespace std;

const vector<string> MONTH = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

string integerToString(int n);

class Date{

public:
    Date(){
        day = 01;
        month = 01;
        year = 1900;
    }
    Date(string gmonth, int gday, int gyear){
        day = gday;
        year = gyear;
        for (int i = 0; i < 12; i++){
            if (MONTH[i] == gmonth){
                month = i + 1;
            }
        }
        if ((year%100 != 0 && year%4==0) || year%400 == 0){
        dom[1] = 29;
        }
    }
    Date(int gday, string gmonth, int gyear){
        day = gday;
        year = gyear;
        for (int i = 0; i < 12; i++){
            if (MONTH[i] == gmonth){
                month = i + 1;
            }
        }
        if ((year%100 != 0 && year%4==0) || year%400 == 0){
        dom[1] = 29;
        }
    }
    string getMonth(){
        return MONTH[month - 1];
    }
    int getDay(){
        return day;
    }
    int getYear(){
        return year;
    }
    string toString(){
        return integerToString(day) + "-" + MONTH[month - 1].substr(0,3) + "-" + integerToString(year);
    }

    Date operator++(){                  //usage: ++Date;
        ++day;
        if (month != 12 && day > dom[month - 1]){
            ++month;
            day = day - dom[month - 2];
        }
        else if (month == 12 && day > 31){
            ++year;
            month = 0;
            day = day - 31;
        }
        return Date(MONTH[month - 1], day, year);
    }
    Date operator++(int){               //usage: Date++;
        Date d(day, MONTH[month - 1], year);
        ++day;
        if (month != 12 && day > dom[month - 1]){
            ++month;
            day = day - dom[month - 2];
        }
        else if (month == 12 && day > 31){
            ++year;
            month = 0;
            day = day - 31;
        }
        return d;
    }
    Date operator--(){                  //usage: --Date;
        --day;
        if (month != 1 && day < 1){
            --month;
            day = dom[month - 1];
        }
        else if (month == 1 && day < 1){
            --year;
            month = 12;
            day = 31;
        }
        return Date(day, MONTH[month - 1], year);
    }
    Date operator--(int){               //usage: Date--;
        Date d(day, MONTH[month - 1], year);
        --day;
        if (month != 1 && day < 1){
            --month;
            day = dom[month - 1];
        }
        else if (month == 1 && day < 1){
            --year;
            month = 12;
            day = dom[month - 1];
        }
        return d;
    }
    Date operator=(const Date & rhs){   //Assignment
        day = rhs.day;
        month = rhs.month;
        year = rhs.year;
        return Date(day, MONTH[month - 1], year);
    }

    friend bool operator==(Date d1, Date d2);   //Comparisson operators
    friend bool operator<(Date d1, Date d2);
    friend bool operator>(Date d1, Date d2);

    friend Date operator+(Date d1, int n);
    friend Date operator-(Date d1, int n);

    friend int operator-(Date d1, Date d2);

private:
    int day;
    int month;
    int year;
    vector<int> dom = {31,28,31,30,31,30,31,31,30,31,30,31};
};

ostream & operator<<(ostream & os, Date d);
bool operator!=(Date d1, Date d2);
bool operator>=(Date d1, Date d2);
bool operator<=(Date d1, Date d2);

int main(){
/*    Date d1;
 *   cout << d1 << endl;
 *   Date d2("JULY", 18, 1969);
 *   cout << d2 << endl;
 *   cout << Date(19, "JULY", 1969) << endl;
 *   if (d1 == d2) cout << d1 << " = " << d2 << endl;
 *   if (d1 != d2) cout << d1 << " != " << d2 << endl;
 *   Date d3("JULY", 19, 1969);
 *   if (d2 < d3) cout << d2 << " < " << d3 << endl;
 *   if (d2 >= d3) cout << d2 << " >= " << d3 << endl;
 *   if (d3 > d2) cout << d3 << " > " << d2 << endl;
 *   cout << ++d3 << endl << d3++ << endl;
 *   cout << d3-- << endl;
 *   cout << d3 << endl;
 *   cout << --d3 << endl;
 */
    Date electionday(6, "NOVEMBER", 2012);
    Date inaugrationday("JANUARY", 21, 2013);
    cout << ++inaugrationday << endl;

/*    Date d4(28, "FEBRUARY", 1940);
 *   cout << ++d4 << endl;
 *   cout << d4++ << endl;
 *   cout << d4 << endl;
 */
    Date d5;
    Date d6 = d5 + 3650;
    cout << d6 << endl;

    return 0;
}

string integerToString(int n){
    ostringstream stream;
    if (n < 10){
        stream << "0" << n;
    }
    else{
        stream << n;
    }
    return stream.str();
}

ostream & operator<<(ostream & os, Date d){
    return os << d.toString();
}

bool operator==(Date d1, Date d2){
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year){
        return true;
    }
    return false;
}

bool operator!=(Date d1, Date d2){
    return !(d1 == d2);
}

bool operator<(Date d1, Date d2){
    if (d1.year < d2.year)
        return true;
    else if (d1.year == d2.year){
        if (d1.month < d2.month){
            return true;
        }
        else if (d1.month == d2.month){
            if(d1.day < d2.day){
                return true;
            }
        }
    }
    return false;
}

bool operator>=(Date d1, Date d2){
    return !(d1 < d2);
}

bool operator>(Date d1, Date d2){
    if (!(d1 == d2) && (d1 >= d2)){
        return true;
    }
    return false;
}

bool operator<=(Date d1, Date d2){
    return !(d1 > d2);
}

int operator-(Date d1, Date d2){
    int difference = 0;
    if (d1 <= d2){
        for (Date d = d1; d < d2; d++){
            difference++;
        }
    }
    else{
        for (Date d = d2; d < d1; d++){
            difference++;
        }
    }
    return difference;
}

Date operator+(Date d1, int n){
    int day, month, year;
    day = d1.day;
    month = d1.month;
    year = d1.year;
    day += n;
    vector<int> dom = {31,28,31,30,31,30,31,31,30,31,30,31};
    if ((year%100 != 0 && year%4==0) || year%400 == 0){
        dom[1] = 29;
    }
    while (day > dom[month - 1]){
        if ((year%100 != 0 && year%4==0) || year%400 == 0){
            dom[1] = 29;
        }
        if (month != 12){
            ++month;
            day = day - dom[month - 2];
        }
        else if (month == 12 && day > 31){
            ++year;
            month = 1;
            day = day - 31;
        }
    }
    return Date(day, MONTH[month - 1], year);
}

Date operator-(Date d1, int n){
    int day, month, year;
    day = d1.day;
    month = d1.month;
    year = d1.year;
    day -= n;
    vector<int> dom = {31,28,31,30,31,30,31,31,30,31,30,31};
    if ((year%100 != 0 && year%4==0) || year%400 == 0){
        dom[1] = 29;
    }
    while (day < 0){
        if ((year%100 != 0 && year%4==0) || year%400 == 0){
            dom[1] = 29;
        }
        if (month != 1){
            --month;
            day = day - dom[month - 2];
        }
        else if (month == 12 && day > 31){
            ++year;
            month = 1;
            day = day - 31;
        }
    }
    return Date(day, MONTH[month - 1], year);
}

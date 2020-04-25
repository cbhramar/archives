#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int roundToNearestInt(double x);
int windChill(int temp, int speed);
void error(string msg);

int main()
{
    cout << "TMP->";
    for (int temp = 40; temp >= -45; temp -= 5){
        cout << right << setw(3) << temp << " |";
    }
    cout << endl << "SPEED";
    for (int temp = 40; temp >= -45; temp -= 5){
        cout << "----+";
    }
    cout << endl;
    for(int speed = 5; speed <= 60; speed += 5)
    {
        cout << right << setw(3) << speed << " |";
        for(int temp = 40; temp >= -45; temp = temp - 5)
        {
            cout << right << setw(3) << windChill(temp, speed) << " |";
        }
        cout << endl;
    }
    return 0;
}

int roundToNearestInt(double x)
{
    int r;
    r = int(x);
    double s;
    s = x - r;
    if (s >= -0.5 && s < 0.5)
    {
        return r;
    }
    else if (s < -0.5)
    {
        r --;
        return r;
    }
    else if (s >= 0.5)
    {
        r ++;
        return r;
    }
}

int windChill(int temp, int speed)
{
    double WC;
    int wc;
    if (temp > 40) error("Wind Chill isn't defined for temperatures greater than forty degrees fahrenheit");
    else if (speed == 0) return temp;
    else
    {
        WC = 35.74 + (0.6215 * temp) - (35.75 * pow(speed, 0.16)) + (0.4275 * temp * pow(speed, 0.16));
    }
    wc = roundToNearestInt(WC);
    return wc;
}

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

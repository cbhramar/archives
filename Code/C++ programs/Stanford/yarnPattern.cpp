#include<iostream>
#include<simplecpp>
#include<vector>

using namespace std;

const int N_ACCROSS = 1360;
const int N_DOWN = 700;
const int DELTA = 2061;
const int ITERATIONS = 1360;

class Point{
public:
    Point(int xc = 0, int yc = 0){
        x = xc;
        y = yc;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
private:
    int x;
    int y;
};

void createPattern(vector<Point> & stops);

int main(){
    initCanvas("Yarn Pattern", N_ACCROSS, N_DOWN);
    Point centre(N_ACCROSS/2, N_DOWN/2);
    vector<Point> stops;
    for (int i = 0; i < N_ACCROSS; i++){
        stops.push_back(Point(centre.getX() - N_ACCROSS/2 + i, centre.getY() - N_DOWN/2));
    }
    for (int i = 0; i < N_DOWN; i++){
        stops.push_back(Point(centre.getX() + N_ACCROSS/2, centre.getY() - N_DOWN/2 + i));
    }
    for (int i = 0; i < N_ACCROSS; i++){
        stops.push_back(Point(centre.getX() + N_ACCROSS/2 - i, centre.getY() + N_DOWN/2));
    }
    for (int i = 0; i < N_DOWN; i++){
        stops.push_back(Point(centre.getX() - N_ACCROSS/2, centre.getY() + N_DOWN/2 - i));
    }
    createPattern(stops);
    getClick();
}

void createPattern(vector<Point> & stops){
    int cp = 0;
    for (int i = 0; i < ITERATIONS; i++){
        Line l(stops[cp].getX(), stops[cp].getY(), stops[(cp + DELTA)%stops.size()].getX(), stops[(cp + DELTA)%stops.size()].getY());
        l.imprint();
        cp = (cp + DELTA)%stops.size();
    }
}

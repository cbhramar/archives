#include <simplecpp>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WIDTH = 15;
const int HEIGHT = 15;
const int MINES = 20;

void initRandomSeed()
{
    static bool initialized = false;
    if (!initialized)
    {
        srand(int(time(NULL)));
        initialized = true;
    }
}

int randomInteger(int low, int high)
{
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return int(floor(low + s));
}

double randomReal(double low, double high)
{
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low);
    return low + s;
}

bool randomChance(double p)
{
    initRandomSeed();
    return randomReal(0, 1) < p;
}

void setRandomSeed(int seed)
{
    initRandomSeed();
    srand(seed);
}


class Point{
public:
    int x;
    int y;
    Point(int cx = 0, int cy = 0){
        x = cx;
        y = cy;
    }
};

void error(string msg);
void createGrid();
void placeMines(vector<Point> & minepositions);
void play(vector<Point> & minepositions, int x, int y/*, vector<vector<int>> & clicked*/);
bool clickInMineSquare(int x, int y, vector<Point> & minepositions);
int getX(int clickPos);
int getY(int clickPos);
void setToCentre(int clickPos, int & x, int & y);
int scout(int x, int y, vector<Point> & minepositions);
bool onlyMinesLeft(vector<Point> & minepositions);
void click(vector<Point> & minepositions, int x, int y/*, vector<vector<int>> & clicked*/);
/*bool negativeOnes(vector<vector<int>> & clicked);*/

int main(){
/*    cout << "Enter width and height, and number of mines:";
    int width, height;
    int mines;
    cin >> width >> height >> mines;*/
    initCanvas("Minesweeper", WIDTH*40, HEIGHT*40);
    createGrid();
    vector<Point> minepositions;
    placeMines(minepositions);
/*    vector<vector<int>> clicked(WIDTH,vector<int>(HEIGHT));
    for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++){
            clicked[i][j] = -1;
        }
    }
    for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++){
            for (int k = 0; k < minepositions.size(); k++){
                if (i == minepositions[k].x && j == minepositions[k].y){
                    clicked[i][j] = -10;
                }
            }
        }
    }*/
    // Game starts from now;
    int clickPos;
    int x = 0, y = 0;
    clickPos = getClick();
    setToCentre(clickPos, x, y);
    play(minepositions, x, y/*, clicked*/);
    getClick();

    return 0;
}

int getX(int clickPos){
    return clickPos/65536;
}

int getY(int clickPos){
    return clickPos%65536;
}

void error(string msg){
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

void createGrid(){
    for (int i = 0; i < WIDTH; i++){
        Line l0(i*40, 0, i*40, HEIGHT*40);
        l0.imprint();
    }
    for (int j = 0; j < HEIGHT; j++){
        Line l0(0, j*40, WIDTH*40, j*40);
        l0.imprint();
    }
    for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++){
            Rectangle r0(i*40 + 20, j*40 + 20, 36, 36);
            r0.setFill(true);
            r0.setColor(COLOR(10, 150, 200));
            r0.imprint();
        }
    }
}

void placeMines(vector<Point> & minepositions){
    for (int i = 0; i < MINES; i++){
        minepositions.push_back(Point(40*randomInteger(0, WIDTH - 1) + 20, 40*randomInteger(0, HEIGHT - 1) + 20));
    }
}

void setToCentre(int clickPos, int & x, int & y){
    x = getX(clickPos) - getX(clickPos)%40 + 20;
//    x = x*40 + 20;
    y = getY(clickPos) - getY(clickPos)%40 + 20;
//    y = y*40 + 20;
}

void play(vector<Point> & minepositions, int x, int y/*, vector<vector<int>> & clicked*/){
    if (clickInMineSquare(x, y, minepositions)){
        Rectangle r1(x, y, 36, 36);
        r1.setFill(true);
        r1.setColor(COLOR("white"));
        r1.imprint();
        Circle c0(x, y, 7);
        c0.setFill(true);
        c0.setColor(COLOR("red"));
        c0.imprint();
        wait(1);
        error("You clicked on a mine. Game Over :(");
    }
    else if (x < 0 || x >= WIDTH*40 ||  y < 0 || y >= HEIGHT*40){
        return;
    }
/*    else if (!negativeOnes(clicked)){
        wait(1);
        error("You've Won! :)");
    }*/
    else{
        int minecount = scout(x, y, minepositions);
        if (minecount == 0){
            Rectangle r1(x, y, 36, 36);
            r1.setFill(true);
            r1.setColor(COLOR("white"));
            r1.imprint();
            click(minepositions, x - 40, y - 40/*, clicked*/);
            click(minepositions, x - 40, y/*, clicked*/);
            click(minepositions, x - 40, y + 40/*, clicked*/);
            click(minepositions, x, y - 40/*, clicked*/);
            click(minepositions, x, y + 40/*, clicked*/);
            click(minepositions, x + 40, y - 40/*, clicked*/);
            click(minepositions, x + 40, y/*, clicked*/);
            click(minepositions, x + 40, y + 40/*, clicked*/);
//            Text t1(x, y, minecount);
//            t1.imprint();
//            clicked[(y - 20)/40][(x - 20)/40] = minecount;
            int clickPosition;
            clickPosition = getClick();
            setToCentre(clickPosition, x, y);
            play(minepositions, x, y/*, clicked*/);
        }
        else {
            minecount = scout(x, y, minepositions);
            Rectangle r1(x, y, 36, 36);
            r1.setFill(true);
            r1.setColor(COLOR("white"));
            r1.imprint();
            Text t1(x, y, minecount);
            t1.imprint();
//            clicked[(y - 20)/40][(x - 20)/40] = minecount;
            int clickPosition;
            clickPosition = getClick();
            setToCentre(clickPosition, x, y);
            play(minepositions, x, y/*, clicked*/);
        }
    }
}

bool clickInMineSquare(int gx, int gy, vector<Point> & minepositions){
    for (int i = 0; i < minepositions.size(); i++){
        if (gx == minepositions[i].y && gy == minepositions[i].x){
            return true;
        }
    }
    return false;
}

void click(vector<Point> & minepositions, int x, int y/*, vector<vector<int>> & clicked*/){
    int minecount = scout(x, y, minepositions);
    if (minecount == 0){
//        clicked[(y - 20)/40][(x - 20)/40] = minecount;
        Rectangle r1(x, y, 36, 36);
        r1.setFill(true);
        r1.setColor(COLOR("white"));
        r1.imprint();
    }
    else{
//        clicked[(y - 20)/40][(x - 20)/40] = minecount;
        Rectangle r1(x, y, 36, 36);
        r1.setFill(true);
        r1.setColor(COLOR("white"));
        r1.imprint();
        Text t1(x, y, minecount);
        t1.imprint();
    }
}

int scout(int x, int y, vector<Point> & minepositions){
    int num = 0;
    if (clickInMineSquare(x - 40, y - 40, minepositions)) num++;
    if (clickInMineSquare(x - 40, y, minepositions)) num++;
    if (clickInMineSquare(x - 40, y + 40, minepositions)) num++;
    if (clickInMineSquare(x, y - 40, minepositions)) num++;
    if (clickInMineSquare(x, y + 40, minepositions)) num++;
    if (clickInMineSquare(x + 40, y - 40, minepositions)) num++;
    if (clickInMineSquare(x + 40, y, minepositions)) num++;
    if (clickInMineSquare(x + 40, y + 40, minepositions)) num++;
    return num;
}

/*bool negativeOnes(vector<vector<int>> & clicked){
    for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++){
            if (clicked[i][j] == -1){
                return true;
            }
        }
    }
    return false;
}*
/
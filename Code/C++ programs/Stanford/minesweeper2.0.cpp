#include<simplecpp>
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include"random.h"
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

const int WIDTH = 16;
const int HEIGHT = 16;
const int N_MINES = 30;
const int L = 40;

void createGrid();
void placeMines(vector<vector<int>> & board);
bool blockIsMine(vector<vector<int>> & board, int x, int y);
int scout(vector<vector<int>> & board, int x, int y);
void fillRestBoard(vector<vector<int>> & board);
int getX(int clickPos);
int getY(int clickPos);
void setClickToBoard(int clickPos, int & x, int & y);
void play(vector<vector<int>> & board, int x, int y, vector<vector<bool>> & displayed);
void error(string msg);
void printBoard(vector<vector<int>> & board, vector<vector<bool>> & displayed);
void click(vector<vector<int>> & board, int x, int y, vector<vector<bool>> & displayed);
bool hasWon(vector<vector<int>> & board, vector<vector<bool>> & displayed);

int main(){
    initCanvas("MINESWEEPER. YES, THE GAME", HEIGHT*L, WIDTH*L);
    createGrid();
    vector<vector<int>> board(WIDTH, vector<int>(HEIGHT));
    vector<vector<bool>> displayed(WIDTH, vector<bool>(HEIGHT));
    placeMines(board);
    fillRestBoard(board);
//    printBoard(board, displayed);
    int x = 0;
    int y = 0;
    int clickPos = getClick();
    setClickToBoard(clickPos, x, y);
    play(board, x, y, displayed);

    getClick();

    return 0;
}

int getX(int clickPos){
    return clickPos/65536;
}

int getY(int clickPos){
    return clickPos%65536;
}

void setClickToBoard(int clickPos, int & x, int & y){
    y = getX(clickPos)/L;
    x = getY(clickPos)/L;
}

void createGrid(){
    for (int i = 0; i < HEIGHT*L; i += L){
        Line l0(i, 0, i, WIDTH*L);
        l0.imprint();
        for (int j = 0; j < WIDTH*L; j += L){
            Line l1(0, j, HEIGHT*L, j);
            l1.imprint();
            Rectangle r(i + L/2, j + L/2, L - L/10, L - L/10);
            r.setFill(true);
            r.setColor(COLOR(50, 150, 250));
            r.imprint();
        }
    }
}

void placeMines(vector<vector<int>> & board){
    for (int i = 0; i < N_MINES; i++){
        board[randomInteger(0, WIDTH - 1)][randomInteger(0, HEIGHT - 1)] = -1;
    }
}

bool blockIsMine(vector<vector<int>> & board, int x, int y){
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return false;
    else
        return board[x][y] == -1;
}

int scout(vector<vector<int>> & board, int x, int y){
    int mineCount = 0;
    if (blockIsMine(board, x - 1, y - 1)) mineCount++;
    if (blockIsMine(board, x - 1, y)) mineCount++;
    if (blockIsMine(board, x - 1, y + 1)) mineCount++;
    if (blockIsMine(board, x, y - 1)) mineCount++;
    if (blockIsMine(board, x, y + 1)) mineCount++;
    if (blockIsMine(board, x + 1, y - 1)) mineCount++;
    if (blockIsMine(board, x + 1, y)) mineCount++;
    if (blockIsMine(board, x + 1, y + 1)) mineCount++;
    return mineCount;
}

void fillRestBoard(vector<vector<int>> & board){
    for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++){
            if (!blockIsMine(board, i, j)){
                board[i][j] = scout(board, i, j);
            }
        }
    }
}

void play(vector<vector<int>> & board, int x, int y, vector<vector<bool>> & displayed){

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    displayed[x][y] = true;
    if (blockIsMine(board, x, y)){
        Rectangle r(y*L + L/2, x*L + L/2, L - L/10);
        r.setFill(true);
        r.setColor(COLOR("white"));
        r.imprint();
        Circle c(y*L + L/2, x*L + L/2, L/5);
        c.setFill(true);
        c.setColor(COLOR("red"));
        c.imprint();
        wait(1);
        error("YOU STEPPED ON A MINE. GAME OVER :(");
    }
    else if(hasWon(board, displayed)){
        Rectangle r(y*L + L/2, x*L + L/2, L - L/10);
        r.setFill(true);
        r.setColor(COLOR("white"));
        r.imprint();
        Text t(y*L + L/2, x*L + L/2, board[x][y]);
        t.imprint();
        for (int i = 0; i < HEIGHT; i ++){
            for (int j = 0; j < WIDTH; j++){
                if (board[j][i] == -1){
                    Rectangle r(i*L + L/2, j*L + L/2, L - L/10, L - L/10);
                    r.setFill(true);
                    r.setColor(COLOR("white"));
                    r.imprint();
                    Text t(i*L + L/2, j*L + L/2, "B)");
                    t.imprint();
                }
            }
        }
        getClick();
        error("YOU'VE WON. FELT LIKE A BOSS? :)");
    }
    else{
//        printBoard(board, displayed);
        if (board[x][y] != 0){
            Rectangle r(y*L + L/2, x*L + L/2, L - L/10);
            r.setFill(true);
            r.setColor(COLOR("white"));
            r.imprint();
            Text t(y*L + L/2, x*L + L/2, board[x][y]);
            t.imprint();
            int clickPos = getClick();
            setClickToBoard(clickPos, x, y);
            play(board, x, y, displayed);
        }
        else{
            Rectangle r(y*L + L/2, x*L + L/2, L - L/10);
            r.setFill(true);
            r.setColor(COLOR("white"));
            r.imprint();
            click(board, x - 1, y - 1, displayed);
            click(board, x - 1, y, displayed);
            click(board, x - 1, y + 1, displayed);
            click(board, x, y - 1, displayed);
            click(board, x, y + 1, displayed);
            click(board, x + 1, y - 1, displayed);
            click(board, x + 1, y, displayed);
            click(board, x + 1, y + 1, displayed);
            int clickPos = getClick();
            setClickToBoard(clickPos, x, y);
            play(board, x, y, displayed);
        }
    }
}

void printBoard(vector<vector<int>> & board, vector<vector<bool>> & displayed){
    for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++){
            cout << setw(4) << right << board[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
    for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++){
            cout << setw(4) << right << displayed[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
}

void error(string msg){
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

void click(vector<vector<int>> & board, int x, int y, vector<vector<bool>> & displayed){
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    displayed[x][y] = true;
    if (board[x][y] != 0){
        Rectangle r(y*L + L/2, x*L + L/2, L - L/10);
        r.setFill(true);
        r.setColor(COLOR("white"));
        r.imprint();
        Text t(y*L + L/2, x*L + L/2, board[x][y]);
        t.imprint();
    }
    else{
        Rectangle r(y*L + L/2, x*L + L/2, L - L/10);
        r.setFill(true);
        r.setColor(COLOR("white"));
        r.imprint();
    }
}

bool hasWon(vector<vector<int>> & board, vector<vector<bool>> & displayed){
    for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++){
            if (board[i][j] != -1 && displayed[i][j] == false)
                return false;
        }
    }
    return true;
}

/*
 * function prototype provided in random.h
 * are defined below this comment.
 */

void initRandomSeed();

int randomInteger(int low, int high){
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return int(floor(low + s));
}

double randomReal(double low, double high){
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low);
    return low + s;
}

bool randomChance(double p){
    initRandomSeed();
    return randomReal(0, 1) < p;
}

void setRandomSeed(int seed){
    initRandomSeed();
    simplecpp::srand(seed);
}

void initRandomSeed(){
    static bool initialized = false;
    if (!initialized)
    {
        simplecpp::srand(int(time(NULL)));
        initialized = true;
    }
}

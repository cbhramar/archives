#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;

const int WIDTH = 4;
const int HEIGHT = 4;
const int xmove[4] = { 1, 0, -1, 0 };
const int ymove[4] = { 0, 1, 0, -1 };

void initializeMaze(vector<vector<bool>> & Maze);
void printMaze(vector<vector<bool>> & Maze);
bool solve(vector<vector<bool>> & Maze, int startx, int starty, int endx, int endy, vector<vector<bool>> & solvedMaze);
bool isValid(vector<vector<bool>> & Maze, int x, int y);
void changeStartPos(int & x, int & y, int xadd, int yadd, vector<vector<bool>> & solvedMaze);
void revertStartPos(int & x, int & y, int xtake, int ytake, vector<vector<bool>> & solvedMaze);

int main() {
	vector<vector<bool>> Maze(WIDTH, vector<bool>(HEIGHT, false));
	vector<vector<bool>> solvedMaze(WIDTH, vector<bool>(HEIGHT, false));
	initializeMaze(Maze);
	printMaze(Maze);
	cout << endl;
	int startx = 3;
	int starty = 3;
	int endx = 0;
	int endy = 0;
	solvedMaze[startx][starty] = true;
	solvedMaze[endx][endy] = true;
/*	if (solve(Maze, startx, starty, endx, endy, solvedMaze)) {
		printMaze(solvedMaze);
	}*/
	solve(Maze, startx, starty, endx, endy, solvedMaze);
	return 0;
}

void initializeMaze(vector<vector<bool>> & Maze) {
	Maze[0][0] = true;
	Maze[1][0] = true;
	Maze[1][1] = true;
	Maze[1][2] = true;
	Maze[1][3] = true;
	Maze[2][0] = true;
	Maze[2][1] = true;
	Maze[3][0] = true;
	Maze[3][1] = true;
	Maze[3][2] = true;
	Maze[3][3] = true;
	/*	Maze[1][1] = true;
	Maze[1][3] = true;
	Maze[1][4] = true;
	Maze[1][5] = true;
	Maze[1][6] = true;
	Maze[1][7] = true;
	Maze[1][8] = true;
	Maze[1][9] = true;
	Maze[1][11] = true;
	Maze[1][12] = true;
	Maze[1][13] = true;
	Maze[2][1] = true;
	Maze[2][3] = true;
	Maze[2][9] = true;
	Maze[2][13] = true;
	Maze[3][1] = true;
	Maze[3][2] = true;
	Maze[3][3] = true;
	Maze[3][5] = true;
	Maze[3][6] = true;
	Maze[3][7] = true;
	Maze[3][9] = true;
	Maze[3][10] = true;
	Maze[3][11] = true;
	Maze[3][13] = true;
	Maze[4][1] = true;
	Maze[4][3] = true;
	Maze[4][5] = true;
	Maze[4][7] = true;
	Maze[4][11] = true;
	Maze[4][13] = true;
	Maze[5][1] = true;
	Maze[5][3] = true;
	Maze[5][5] = true;
	Maze[5][7] = true;
	Maze[5][11] = true;
	Maze[5][12] = true;
	Maze[5][13] = true;
	Maze[6][1] = true;
	Maze[6][7] = true;
	Maze[6][9] = true;
	Maze[6][13] = true;
	Maze[7][1] = true;
	Maze[7][3] = true;
	Maze[7][4] = true;
	Maze[7][5] = true;
	Maze[7][6] = true;
	Maze[7][7] = true;
	Maze[7][9] = true;
	Maze[7][10] = true;
	Maze[7][11] = true;
	Maze[7][13] = true;
	Maze[8][1] = true;
	Maze[8][3] = true;
	Maze[8][7] = true;
	Maze[8][11] = true;
	Maze[8][13] = true;
	Maze[9][1] = true;
	Maze[9][3] = true;
	Maze[9][4] = true;
	Maze[9][5] = true;
	Maze[9][7] = true;
	Maze[9][8] = true;
	Maze[9][9] = true;
	Maze[9][10] = true;
	Maze[9][11] = true;
	Maze[9][13] = true;
	Maze[10][1] = true;
	Maze[10][5] = true;
	Maze[10][11] = true;
	Maze[10][13] = true;
	Maze[11][1] = true;
	Maze[11][2] = true;
	Maze[11][3] = true;
	Maze[11][5] = true;
	Maze[11][6] = true;
	Maze[11][7] = true;
	Maze[11][8] = true;
	Maze[11][9] = true;
	Maze[11][11] = true;
	Maze[11][12] = true;
	Maze[11][13] = true;
	Maze[12][1] = true;
	Maze[12][3] = true;
	Maze[12][9] = true;
	Maze[13][1] = true;
	Maze[13][1] = true;
	Maze[13][3] = true;
	Maze[13][4] = true;
	Maze[13][5] = true;
	Maze[13][6] = true;
	Maze[13][7] = true;
	Maze[13][9] = true;
	Maze[13][10] = true;
	Maze[13][11] = true;
	Maze[13][12] = true;
	Maze[13][13] = true;
	Maze[14][7] = true;
	*/
}

void printMaze(vector<vector<bool>> & Maze) {
//	int position = 1;
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (!Maze[i][j]) {
				cout << "-----";
			}
			else {
				cout << "     ";
			}
		}
		cout << "+" << endl;
		for (int j = 0; j < HEIGHT; j++) {
			if (!Maze[i][j]) {
				cout << right << setw(4) << "X" << " ";
			}
			else {
				cout << right << /*setw(4) << position*/ "    " << " ";
//				++position;
			}
		}
		if (i != WIDTH - 1) {
			cout << "|" << endl;
		}
		else{
			cout << endl;
		}
	}
	for (int i = 0; i < HEIGHT; i++) {
		cout << "-----";
	}
	cout << "+" << endl;
}

bool solve(vector<vector<bool>> & Maze, int startx, int starty, int endx, int endy, vector<vector<bool>> & solvedMaze) {
	if (startx == endx && starty == endy) {
		printMaze(solvedMaze);
		return true;
	}
	for (int i = 0; i < 4; i++) {
		int newX = startx + xmove[i];
		int newY = starty + ymove[i];
		if (isValid(Maze, newX, newY)) {
			changeStartPos(startx, starty, xmove[i], ymove[i], solvedMaze);
			if (solve(Maze, startx, starty, endx, endy, solvedMaze)) return true;
			revertStartPos(startx, starty, xmove[i], ymove[i], solvedMaze);
		}
	}
	return false;
}

bool isValid(vector<vector<bool>> & Maze, int x, int y) {
//	cout << "isValid" << endl;
	if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)
		return false;
	return Maze[x][y];
}

void changeStartPos(int & x, int & y, int xadd, int yadd, vector<vector<bool>> & solvedMaze) {
//	cout << "startPos changed" << endl;
	x += xadd;
	y += yadd;
	solvedMaze[x][y] = true;
}

void revertStartPos(int & x, int & y, int takex, int takey, vector<vector<bool>> & solvedMaze) {
//	cout << "startPos reverted to og" << endl;
	solvedMaze[x][y] = false;
	x = x - takex;
	y = y - takey;
	solvedMaze[x][y] = false;
}

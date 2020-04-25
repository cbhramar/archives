#include <iostream>

using namespace std;

class Matrix {
	private:
		int n;
		int m;
		vector<vector<int> > M;

	public:
		Matrix(int n = 1, int m = 1);

		~Matrix(); 
		
};
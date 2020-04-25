#include <bits/stdc++.h>

using namespace std;

const int SENTINEL = -1;

class Radix{
public:
	Radix(){
		height = 0;
		for (int i = 0; i < 64; ++i){
			Values.push_back(SENTINEL);
		}
	}
	void insert(int key, int value){
		if (Values[key] == SENTINEL){
			++height;
		}
		Values[key] = value;
	}
	void deleter(int key){
		Values[key] = SENTINEL;
		--height;
	}
	int lookup(int key){
		if (key > 63){
			return SENTINEL;
		}
		else{
			return Values[key];
		}
	}
	void print(){
		cout << height << " " <<  << endl;
	}
private:
	int height;
	vector<int> Values;
};

int main(){
	Radix R;
	char ch;
	cin >> ch;
	while (ch != 'e'){
		if (ch == 'i'){ // implement insertion
			int key, value;
			cin >> key >> value;
			R.insert(key, value);
		}
		else if (ch == 'd'){ // implement deletion
			int key;
			cin >> key;
			R.deleter(key);
		}
		else if (ch == 'l'){ // implement lookup
			int key;
			cin >> key;
			cout << R.lookup(key) << endl;
		}
		else if (ch == 'p'){ // implement printing
			R.print();
		}
		else if (ch == 'e'){ // exit
			break;
		}
		cin >> ch;
	}

	return 0;
}
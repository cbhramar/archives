#include <bits/stdc++.h>

using namespace std;

struct valNode{
	int value;
};

struct radNode{
	int height;
	int count;
	radNode* pointerArray[64];
	valNode* valueArray[64];
};

class radix{
public:
	radix(){
		totalheight = 0;
		totalcount = 0;
		HEAD = new radNode;
		HEAD->height = 0;
		HEAD->count = 0;
		for (int i = 0; i < 64; ++i){
			HEAD->pointerArray[i] = NULL;
			HEAD->valueArray[i] = NULL;
		}
	}
	void insert(int key, int value){
		if (totalheight == 0){
			//create root 
			totalheight = log(key)/log(64) + 1;
			int offset = key - pow(64, totalheight - 1);
		}
		else{
			//radix tree exists; update it
		}
	}
	bool exists(int key, valNode* tempVal){
		//return true if key val pair exists, tempVal points to value of key, or to NULL
	}
	void deleter(int key){
		//call exists, set tempVal to NULL
	}
	int lookup(int key){
		//call exists, return value of key
	}
	void print(){
		//no idea
	}
	~radix(){
		delete HEAD;
	}
private:
	int totalheight;
	int totalcount;
	radNode* HEAD;
};

int main(){
	radix R;
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
#include <iostream>
#include <vector>

using namespace std;

int lcm(int,int);
int gcd(int,int);

int main() {

	int n;
	cin >> n;

	vector<int> f;
	f.resize(n);
	for (int i = 0; i < n; i++)
		cin >> f[i];

	int initial = 0, period = 1;

	for (int i = 0; i < n; i++) {
		vector<int> occurs(n, -1);
		int j = 0;
		int k = i;
		while (occurs[k] == -1) {
			occurs[k] = j;
			j++;
			k = f[k];
		}
		if (occurs[k] > initial) initial = occurs[k];
		int d = j - occurs[k];
		period = lcm(period,d);
	}

	cout << initial << endl;
	cout << period << endl;

	vector<int> d(n);
	for (int i = 0; i < n; i++)
		d[f[i]]++;

	vector<bool> included(n,false);

	bool found = true;
	int minnum = 0;

	while (found) {
		found = false;
		for (int i = 0; i < n; i++)
			if ((d[i] == 0) && !included[i] && !included[f[i]]) {
				included[f[i]] = true;
				d[f[f[i]]]--;
				minnum++;
				found = true;
			}
		if (!found) {
			for (int i = 0; (i < n) && !found; i++)
				if (!included[i] && !included[f[i]]) {
					included[i] = true;
					d[f[i]]--;
					minnum++;
					found = true;
				}
		}
	}

	cout << minnum << endl;

	return 0;
}

int lcm(int i, int j) {
	return (i/gcd(i,j))*j;
}

int gcd(int i, int j) {
	if (j == 0) return i;
	else return gcd(j, i % j);
}


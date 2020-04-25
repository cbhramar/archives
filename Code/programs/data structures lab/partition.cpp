#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
using namespace std;

bool check(vector<vector<int> > &, vector<int> &, int);
bool compress(vector<vector<int> > &, vector<int> &, int);

int main()
{
	int n, seed, maxd;
	set<int> S;
	vector<vector<int> > A;
	vector<int> match;
	cin >> n;
	A  = vector<vector<int> >(n, vector<int>(n));
	for (int i = 0; i < n-1; i++)
	{
	for (int j = i+1; j < n; j++)
	{
		cin >> A[i][j];
		S.insert(A[i][j]);
		A[j][i] = A[i][j];
	}
	A[i][i] = 0;
	}
	A[n-1][n-1] = 0;
	S.insert(0);
	vector<int> distinct(S.size());
	int i = 0;
	for (set<int>::iterator p = S.begin(); p != S.end(); p++)
	distinct[i++] = *p;
	match = vector<int>(n,-1);
	int d2 = 0;
	int d1 = distinct.size()-2;
	int mindisp = distinct.back();
	bool found = true;
 	while ((d1 >= 0) && found)
	{
		int dist = distinct[d1];
		if (!compress(A,match,dist)) break;
		found = false;
		while (!found)
		{
			if (check(A,match,distinct[d2])) found = true;
			else d2++;
		}
		if (mindisp > dist+distinct[d2])
		mindisp = dist+distinct[d2];
		d1--;
	}
	cout << mindisp << endl;
	return 0;
}





bool check(vector<vector<int> > &A, vector<int> &match, int dist)
{
	int n = A.size();
	vector<int> sel(n, -1);
	for (int start = 0; start < n; start++)
	if ((match[start] != -1) && (sel[start] == -1) && (sel[match[start]] == -1))
	{
		vector<int> even, inq(n,-1);
		even.push_back(start);
		inq[start] = 0;
		bool found = false;
		int cnt = 0;
		while (!found && (cnt < even.size()))
		{
			int curr = even[cnt++];
			for (int i = 0; (i < n) && !found; i++)
			if ((i != match[curr]) && (sel[i] == -1) && (match[i] != -1) && (A[i][curr] > dist))
			{
				if (inq[i] == 0) found = true;
				else if (inq[i] == -1)
				{
					inq[i] = 1;
					even.push_back(match[i]);
					inq[match[i]] = 0;
				}
			}
		}
		if (!found)
		{
			for (int i = 0; i < even.size(); i++)
			{
				sel[even[i]] = 1;
				sel[match[even[i]]] = 0;
			}
		}
		else
		{
			even.clear();
			inq = vector<int>(n,-1);
			sel[start] = 0;
			even.push_back(match[start]);
			inq[match[start]] = 0;
			sel[match[start]] = 1;
			found = false;
			cnt = 0;
			while (!found && (cnt < even.size()))
			{
				int curr = even[cnt++];
				for (int i = 0; (i < n) && !found; i++)
				if ((i != match[curr]) && (match[i] != -1) && (A[i][curr] > dist))
				{
					if (inq[i] == 0) return false;
					else if (inq[i] == -1)
					{
						sel[i] = 0;
						inq[i] = 1;
						even.push_back(match[i]);
						inq[match[i]] = 0;
						sel[match[i]] = 1;
					}
				}
			}
		}
	}
	return true;
}


bool compress(vector<vector<int> > &A, vector<int> &match, int dist)
{
	int n = A.size();
	vector<int> level(n,-1);
	vector<bool> del(n,false);
	for (int start = 0; start < n; start++)
	if (level[start] == -1)
	{
		level[start] = 0;
		int s = 0;
		int t = 1;
		int currlevel = 0;
		vector<int> q;
		q.push_back(start);
		while (s < t)
		{
		currlevel++;
		for (int i = s; i < t; i++)
		{
			int curr = q[i];
			for (int j = 0; j < n; j++)
			if (A[curr][j] > dist) 
			{
				if (level[j] == -1)
				{
					level[j] = currlevel;
					q.push_back(j);
				}
				else if ((level[j] % 2) != (currlevel % 2)) return false;
			}
		}
		s = t;
		t = q.size();
		}
		int evenmin = start;
		int oddmin = n+1;
		for (int i = 0; i < q.size(); i++)
		if ((level[q[i]] % 2 == 1) && (q[i] < oddmin)) oddmin = q[i];
		for (int i = 0; i < q.size(); i++)
			del[q[i]] = true;
		del[evenmin] = false;
		if (oddmin < n) del[oddmin] = false;
		for (int i = 0; i < q.size(); i++)
		if ((q[i] != evenmin) && (level[q[i]] % 2 == 0))
		{
			for (int j = 0; j < n; j++)
			if (A[q[i]][j] > A[evenmin][j])
			{
				A[evenmin][j] = A[j][evenmin] = A[q[i]][j];
			}
			if (A[q[i]][q[i]] > A[evenmin][evenmin]) A[evenmin][evenmin] = A[q[i]][q[i]];
		}
		else if ((q[i] != oddmin) && (level[q[i]] % 2 == 1))
		{
			for (int j = 0; j < n; j++)
			if (A[q[i]][j] > A[oddmin][j])
			{
				A[oddmin][j] = A[j][oddmin] = A[q[i]][j];
			}
			if (A[q[i]][q[i]] > A[oddmin][oddmin]) A[oddmin][oddmin] = A[q[i]][q[i]];
		}
		if (oddmin < n)
		{	
			match[evenmin] = oddmin;
			match[oddmin] = evenmin;
		}
		
	}
		
	int cnt = 0;
	vector<int> newnum(n,-1);
	for (int i = 0; i < n; i++)
		if (!del[i]) newnum[i] = cnt++;
	for (int i = 0; i < n; i++)
	if (newnum[i] != -1) A[newnum[i]] = A[i];
	A.erase(A.begin()+cnt, A.end());
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < n; j++)
		if (newnum[j] != -1) A[i][newnum[j]] = A[i][j];
		A[i].erase(A[i].begin()+cnt, A[i].end());
	}
	vector<int> newmatch(cnt);
	for (int i = 0; i < n; i++)
	if (newnum[i] != -1)
	{
		if (match[i] == -1) newmatch[newnum[i]] = -1;
		else newmatch[newnum[i]] = newnum[match[i]];
	}
	match = newmatch;
	return true;
}

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double dist(int,int);

struct node
{
	int num;
	double cost, priority;
};

struct point
{
	double x,y;
};

vector<point> P;
vector<bool> deleted;
vector<int> pointpos, invpos;

struct comp
{
	bool operator()(int const &i, int const &j) const
	{
		if (P[i].x == P[j].x) return (P[i].y < P[j].y);
		else return (P[i].x < P[j].x);
	}
};


bool operator<(node const &n, node const &m) 
{
	if (n.priority == m.priority) return (n.cost > m.cost);
	else return (n.priority < m.priority);
}


class heap {
	vector<node> v;
	vector<int> pos;
	public:
	heap(int n)
	{
		v.clear();
		pos = vector<int>(n);
		for (int i = 0; i < n; i++) pos[i] = -1;
	}
	node deletemin()
	{
		node temp = v[0];
		pos[temp.num] = -1;
		v[0] = v.back();
		v.pop_back();
		pos[v[0].num] = 0;
		bool found = true;
		int i = 0;
		while (found)
		{
			if (2*i+1 >= v.size()) found = false;
			else
			{
				int x = 2*i+1;
				if ((2*i+2 < v.size()) && (v[2*i+2] < v[x])) x = 2*i+2;
				if (v[x] < v[i])
				{
					node t = v[i];
					v[i] = v[x];
					v[x] = t;
					pos[v[i].num] = i;
					pos[v[x].num] = x;
					i = x;
				}
				else found = false;
			}
		}
		return temp;
	}
	void update(node t)
	{
		int i = -1;
		if (pos[t.num]==-1) 
		{
			v.push_back(t);
			pos[t.num] = i = v.size()-1;
		}
		else if (t < v[pos[t.num]])
		{
			v[pos[t.num]] = t;
			i = pos[t.num];
		}
		bool found = true;
		while ((i > 0) && found)
		{
			if (v[i] < v[(i-1)/2])
			{
				node temp = v[i];
				v[i] = v[(i-1)/2];
				v[(i-1)/2] = temp;
				pos[v[i].num] = i;
				pos[v[(i-1)/2].num] = (i-1)/2;
				i = (i-1)/2;
			}
			else found = false;
		}
	}
	bool empty()
	{
		return v.empty();
	}
};




int main()
{
	int n, s, t;
	double D;
	cin >> n >> D >> s >> t;
	P.resize(n);
	pointpos = invpos = vector<int>(n);
	deleted = vector<bool>(n,false);
	for (int i = 0; i < n; i++)
		cin >> P[i].x >> P[i].y;
	for (int i = 0; i < n; i++) pointpos[i] = i;
	sort(pointpos.begin(),pointpos.end(),comp());
	for (int i = 0; i < n; i++) invpos[pointpos[i]] = i;
	node temp;
	heap H(n);
	temp.num = s;
	temp.cost = 0;
	temp.priority = dist(s,t);
	H.update(temp);
	while (!H.empty())
	{
		temp = H.deletemin();
		deleted[temp.num] = true;
		if (temp.num == t) break;
		int k = invpos[temp.num];
		for (int j = k+1; (j < n) && (P[pointpos[j]].x - P[pointpos[k]].x <= D); j++)
		if ((dist(pointpos[j],pointpos[k]) <= D) && !deleted[pointpos[j]])
		{	
			node t1;
			t1.num = pointpos[j];
			t1.cost = temp.cost + dist(temp.num,t1.num);
			t1.priority = t1.cost + dist(t1.num,t);
			H.update(t1);
		}
		for (int j = k-1; (j >= 0) && (P[pointpos[k]].x - P[pointpos[j]].x <= D); j--)
		if ((dist(pointpos[j],pointpos[k]) <= D) && !deleted[pointpos[j]])
		{	
			node t1;
			t1.num = pointpos[j];
			t1.cost = temp.cost + dist(temp.num,t1.num);
			t1.priority = t1.cost + dist(t1.num,t);
			H.update(t1);
		}
	}
	if (deleted[t])
	{
		cout << temp.cost << endl;
	}
	else cout << "INFINITY\n";
	return 0;
}

double dist(int i, int j)
{
	return sqrt(pow(P[j].x-P[i].x,2)+pow(P[j].y-P[i].y,2));
}

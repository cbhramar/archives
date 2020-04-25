#include <iostream>
#include <cmath>
#include <map>

using namespace std;

// void print(int *a)
// {
// 	for(int i=0; i<N; i++)
// 	{
// 		cout << a[i] << "	";
// 	}
// }

// bool reject(int *a, int pos)
// {
// 	for(int i=0; i<pos; i++)
// 	{
// 		if(a[pos] == a[i])
// 			return true;
// 		else if(abs(a[pos]-a[i]) == abs(pos-i))
// 			return true;
// 		else 
// 			return false;	
// 	}
// }

// void backtrack(int *a)
// {
// 	if (reject(a, pos)) return;
// 	if (accept(a)) print(a);
// 	int s = first(a, pos);
// 	while (s != -2)
// 	{
// 		backtrack(s);
// 		s = next(s, pos);
// 	}
// }


int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w]=max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main()
{
    cout << "Enter the number of items in a Knapsack:";
    int n, W;
    cin >> n;
    int val[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight for item " << i << ":";
        cin >> val[i];
        cin >> wt[i];
    }
    //    int val[] = { 60, 100, 120 };
    //    int wt[] = { 10, 20, 30 };
    //    int W = 50;
    cout << "Enter the capacity of knapsack";
    cin >> W;
    cout << "Maximal Value for given capacity = " << knapSack(W, wt, val, n) << endl;
}

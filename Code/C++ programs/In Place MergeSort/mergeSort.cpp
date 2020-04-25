#include <iostream>
#include <limits>
#include <vector>
#include <numeric>

using namespace std;

void mergesort(int * data, int start, int ender);
void mergedata(int * data, int start, int mid, int ender);

int main(int argc, char const *argv[])
{
	int data[20] = {20,19,18,17,16,15,14,13,12,11,10,9,15,7,6,5,14,3,2,100};
	mergesort(data, 0, 19);

    for (int i = 0; i < 20; ++i)
    {
        cout << data[i] << " ";
    }
	cout << endl;

	return 0;
}

void mergesort(int * data, int start, int ender)
{
	if (start < ender)
	{
		int mid = (start + ender)/2;
		mergesort(data, start, mid);
		mergesort(data, mid + 1, ender);
		mergedata(data, start, mid + 1, ender);
	}
}

void mergedata(int * data, int start, int mid, int ender)
{
	int L[mid - start + 1];
	for (int i = 0; i < mid - start; ++i)
	{
		L[i] = data[i + start];
	}
	int R[ender - mid + 2];
	for (int i = 0; i < ender - mid + 1; ++i)
	{
		R[i] = data[i + mid];
	}
	L[mid - start] = max(L[mid - start - 1], R[ender - mid]) + 2;
	R[ender - mid + 1] = max(L[mid - start - 1], R[ender - mid]) + 2;
	int i = 0;
	int j = 0;
	for (int k = start; k <= ender; ++k)
	{
		if (L[i] < R[j])
		{
			data[k] = L[i];
			++i;
		}
		else
		{
			data[k] = R[j];
			++j;
		}
	}
}

#include <iostream>

using namespace std;

const int SENTINEL = -1; //added for offset purposes ( i really want to start my array from 1)

void max_heapify(int * data, int i, int n);
void heapsort(int * data, int n);
void build_maxheap(int * data, int n);

int main(int argc, char const *argv[])
{
	int data[21] = {SENTINEL,20,19,18,187,16,15,14,13,12,11,10,9,8,7,6,54,45,3,2,1};
	build_maxheap(data, 20);
	cout << "The corresponding max_heap is: " << endl;
	for (int i = 1; i < 21; ++i)
	{
		cout << data[i] << " ";
	}
	cout << endl;
	heapsort(data, 20);
	cout << "The sorted input is: " << endl;
	for (int i = 1; i <= 20; ++i)
	{
		cout << data[i] << " ";
	}
	cout << endl;
	return 0;
}

void max_heapify(int * data, int i, int n)
{
	int j = 2*i;
	int temp = data[i];
	while (j <= n)
	{
		if (j < n && data[j + 1] > data[j])
		{
			++j;
		}
		if (temp > data[j])
		{
			break;
		}
		else
		{
			data[j/2] = data[j];
			j = 2*j;
		}
	}
	data[j/2] = temp;
	// cout << "The heap uptil now is: " << endl;
	// for (int k = 1; k <= n; ++k){
	// 	cout << data[k] << " ";
	// }
	// cout << endl;
	return;
}

void heapsort(int * data, int n)
{
	int temp;
	for (int i = n; i >= 2; --i)
	{
		temp = data[i];
		data[i] = data[1];
		data[1] = temp;
		max_heapify(data, 1, i - 1);
	}
}

void build_maxheap(int * data, int n)
{
	for (int i = n/2; i >= 1; --i)
	{
		max_heapify(data, i, n);
	}
}

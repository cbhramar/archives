#include <iostream>

int array[10] = {0,1,2,3,4,5,6,7,8,9};

void swap(int x, int y){
    int temp = array[x];
    array[x]=array[y];
    array[y]=temp;

    return;
}

void printArray(int size){
    int i;

    for (i=0;i<size;i++)
        std::cout << array[i] << " ";

    std::cout << std::endl;

    return;
}

bool check(int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (i != j)
			{	if ( (array[j] - array[i]) != (j - i) )
					if ( (array[j] - array[i]) != (i - j) )
										return true;
				else
					return false;
			}
			else if (i == j)
				return false;
		}
	}
}

void permute(int k,int size){
    int i;

    if (k==0)
    {
        if (check(size))
        	printArray(size);
        else
        	std::cout << "no solution yet \n";
    }
    else{
        for (i=k-1;i>=0;i--){
            swap(i,k-1);
            permute(k-1,size);
            swap(i,k-1);
        }
    }

    return;
}

int main(){

    permute(4,4);

}
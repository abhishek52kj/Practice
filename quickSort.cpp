#include <iostream>

using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

int partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int pi = start;

	for(int i=start; i<end; i++)
	{
		if(arr[i] <= pivot)
		{
			swap(arr[i],arr[pi]);
			pi++;
		}
	}
	swap(arr[end],arr[pi]);
	return pi;
}

void quickSort(int arr[],int start, int end)
{
	if(start < end)
	{
		int m=partition(arr,start,end);
		quickSort(arr,start,m-1);
		quickSort(arr,m+1,end);
	}	
}

int main()
{
	int arr[]={7, 6, 5, 4, 3, 2, 1, 0};
	int size=sizeof(arr)/sizeof(int);
	quickSort(arr,0,size-1);

	for(int i=0; i<size; i++)
		cout<<arr[i]<<" ";

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int avggk(int arr[], int n, int k)
{ 
	arr[0]-=k;
	cout<<arr[0]<<" ";
	for (int i = 1; i < n; i++)
	{
		arr[i]=arr[i]+arr[i-1]-k;
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
}

int main()
{
    int arr[] = {9, 10, 5, 2, 7, 1, -10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
    cout<<endl;
    avggk(arr, n, k);
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int missingNo(vector<int> &arr)
{
	int l,mid,r;
	
	l = 0;
	r = arr.size()-1;

	while(l<=r)
	{
		mid = (l + r)>>1;
		if(arr[mid] == (mid+1))
		{
			l = mid + 1;
		}
		else if(arr[mid] > (mid+1))
		{
			r = mid - 1;
		}
	}
	return mid+1;	
}

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 10};
	cout<<missingNo(arr);	
	return 0;
}
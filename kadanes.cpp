#include <iostream>
#include <vector>

using namespace std;

int largestcontsum(vector<int> &arr)
{
	int ans=0,tempans=0;
	for(auto it=arr.begin(); it != arr.end(); it++)
	{
		tempans += *it;
		if(tempans < 0)
			tempans = 0;
		if(ans < tempans)
			ans = tempans;
	}
	return ans;
}

int main()
{
	vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
	cout<<largestcontsum(arr);	
	return 0;
}
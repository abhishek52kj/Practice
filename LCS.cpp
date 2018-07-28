#include <bits/stdc++.h>

using namespace std;

int lcs(vector<int> arr)
{
	int n = arr.size(),max = 0;
	int len[n] = {1};

	for (int i = 1; i <	n; i++)
	{
		for (int j = 0; j < i; j++)
			{
				if(arr[j] < arr[i] && len[i] < len[j]+1)
				{
					len[i] = len[j]+1;
				}
			}
		if(len[i] > max)
			max = len[i];		
	}
	return max;
}

int main()
{
	std::vector<int> arr;
	int n,no;

	cin>>n;

	for (int i = 0; i < n; i++)
	{
		cin>>no;
		arr.push_back(no);
	}

	cout<<lcs(arr);

	return 0;
}

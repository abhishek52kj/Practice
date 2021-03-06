#include <iostream>

using namespace std;

int flipbits(int arr[100000],int n)
{
	int l,r,s,ml,mr,ms,oc=0;
	l = r = s = ml = mr = ms = -1;
	for (int i = 0; i < n; i++)
	{
			if(arr[i] == 1)
			{
				l = r = s = -1; 
				oc++;
			}
			else
			{
				if(l == -1)
				{
					l = r = i;
					s = 1;
				}
				else
				{
					r++;
					s++;
				}
			}
			if(ms < s)
			{
				ml = l;
				mr = r;
				ms = s;
			}
	}
	cout<<"Flip : ["<<ml<<","<<mr<<"]"<<endl;
	return oc+ms;
}

int main()
{
	int t,n;
	cin>>t;

	for (int i = 0; i < t; i++)
	{
		cin>>n;
		int arr[n];
		for (int j = 0; j < n; j++)
		{
			cin>>arr[j];
		}
		cout<<flipbits(arr,n)<<endl;
	}
}	
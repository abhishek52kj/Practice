#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void binarysearch(vector<int> &arr, int item, int l, int r, int mid, int &st, int &en)
{
	if(r<=l)
	{
		cout<<l<<" "<<mid<<" "<<r<<" "<<st<<" "<<en<<" "<<"\nCall..."<<endl;
		cout<<"End Return"<<endl;
		return;
	}

	if(arr[mid] == item)
	{
		if(st>mid)
		{
			st=mid;
		}
		if(en<mid)
		{
			en=mid;
		}
		cout<<"Found\nLeft Search"<<endl;
		binarysearch(arr ,item, l, mid-1, (l+mid-1)>>1, st, en);
		cout<<l<<" "<<mid<<" "<<r<<" "<<st<<" "<<en<<" "<<"\nCall..."<<endl;
		cout<<"Found\nRight Search"<<endl;
		binarysearch(arr ,item, mid+1, r, (mid+1+r)>>1, st, en);
		cout<<l<<" "<<mid<<" "<<r<<" "<<st<<" "<<en<<" "<<"\nCall..."<<endl;
	}

	else	if(arr[mid] < item)
	{
		cout<<"Small\nRight Search"<<endl;
		binarysearch(arr ,item, mid+1, r, (mid+1+r)>>1, st, en);
		cout<<l<<" "<<mid<<" "<<r<<" "<<st<<" "<<en<<" "<<"\nCall..."<<endl;
	}

	else	if(arr[mid] > item)	
	{
		cout<<"Large\nLeft Search"<<endl;
		binarysearch(arr ,item, l, mid-1, (l+mid-1)>>1, st, en);
		cout<<l<<" "<<mid<<" "<<r<<" "<<st<<" "<<en<<" "<<"\nCall..."<<endl;
	}

}

void rangeSearch(vector<int> &arr, int item, vector<int> &range)
{
	int l=0;
	int r=arr.size()-1;
	int st=arr.size(),en=-1;

	cout<<l<<" "<<((l+r)>>1)<<" "<<r<<" "<<st<<" "<<en<<" "<<"\nCall..."<<endl;
	binarysearch(arr ,item, l, r, (l+r)>>1, st, en);
	
	if(st=arr.size())
	{
		st=-1;
	}
	range[0]=st;
	range[1]=en;
	
}

int main()
{
	int item=8;
	vector<int> arr={5, 8, 8, 8, 8, 8, 10},range;
	rangeSearch(arr,item,range);
	cout << "\nRange is : ";
    for (auto it = range.begin(); it != range.end(); it++)
    {
        cout << *it << " ";
    }
	return 0;
}
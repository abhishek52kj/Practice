#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int temp=a;
		a=b;
		b=temp;
}

void swapsmall(int &a, int &b)
{
	if(a>b)
	{
		swap(a,b);
	}

	return;
}

int main()
{
	int n=1,x1=0,x2=1,x3=-2,x4=0,y1=2,y2=1,y3=-3,y4=2,res=0;
	//cin>>n;

	for(int i=0; i<n; i++)
	{
		//cin>>x1>>y1>>x2>>y2;
		res=0;
		
		swapsmall(x1,x2);
		cout<<x1<<" "<<x2<<endl;
		swapsmall(y1,y2);
		cout<<y1<<" "<<y2<<endl;

		//cin>>x3>>y3>>x4>>y4;

		swapsmall(x3,x4);
		cout<<x3<<" "<<x4<<endl;
		swapsmall(y3,y4);
		cout<<y3<<" "<<y4<<endl;

		if(x2<x3)
		{
			res+=2;
		}
		if(x2=x3)
		{
			res-=1;
		}

		if(y2<y3)
		{
			res+=2;
		}
		if(y2=y3)
		{
			res-=1;
		}
		if(res>0)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}

	return 0;
}
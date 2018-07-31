#include <bits/stdc++.h>

using namespace std;

int minimmum(int a, int b)
{
	if(a>b)
		return b;
	return a; 
}

bool isprime(int n)
{
	if( (n%2) == 0 )
		return false;

	for(int i=3; i<n; i+=2)
	{
		if( (n%i) == 0 )
			return false;
	}
	return true;
}

int leftnear(int n, int step, int min)
{
	if(isprime(n))
		return step+1;
	if((step+2)<min)
		return leftnear(n-2,step+2,min);
	return min;
}

int rightnear(int n, int step, int min)
{
	if(isprime(n))
		return step+1;
	if((step+2)<min)
		return rightnear(n+2,step+2,min);
	return min;
}

int nearprime(int n, int min)
{
	int step=0;
	if((n%2) == 0)
	{
		return minimmum(leftnear(n-1,step+1,min),rightnear(n+1,step+1,min));
	}
		return minimmum(leftnear(n-2,step+2,min),rightnear(n+2,step+2,min));
}

int factor(int n)
{
	int step=0;
	while( n != 1 )
	{
		while( (n%2) == 0)
		{
			n=n>>1;
			step++;
		}
		for(int i=3; i<=n; i+=2)
		{
			while( (n%i) == 0 )
			{
				n=n/i;
				step++;
			}
		}
	}
	return step;
}

int minto1(int n)
{
	if(isprime(n))
		return 1;
	return nearprime(n,factor(n));
}

int main()
{
	int n;
	cin>>n;
	cout<<minto1(n);
	return 0;
}
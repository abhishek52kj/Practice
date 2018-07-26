#include<iostream>

using namespace std;

int matrixMedian(int mat[3][3], int m, int n)
{
	int x=0,y=0;
	int arr[m]={0};
	int medianpos=((m*n)>>1)+1;

	for(int i=0; i<medianpos; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(arr[j]<n)
			{
				x=j;
				y=arr[j];
			}
		}
		for(int j=0; j<m; j++)
		{
			if(arr[j]<n)
			{
				if(mat[j][arr[j]] < mat[x][y])
				{
					x=j,
					y=arr[j];
				}
			}		
		}
		arr[x]++;	
	}
	return mat[x][y];
}

int main()
{
	int m=3,n=3;
	int mat[3][3]={{1,3,5},{2,6,9},{6,9,9}};
	cout<<matrixMedian(mat,m,n);
	return 0;
}
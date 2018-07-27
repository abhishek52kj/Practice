#include <iostream>
#include <string.h>

using namespace std;

int max(int x, int y){return (x > y)? x :y; }

int lps(char str[])
{
	int n=strlen(str);
	int j;
	int dp[n][n]={0};

	for(int i=0; i<n; i++)
		dp[i][i]=1;

	for(int cl=2; cl<=n; cl++)
	{
		for(int i=0; i<n-cl+1; i++)
		{
			j=i+cl-1;

			if(str[j] == str[i] && cl == 2)
				dp[i][j] = 2;
			else if(str[j] == str[i])
				dp[i][j] = dp[i+1][j-1]+2;
			else
				dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
		}
	}

return dp[0][n-1];

}

int main(){
	
	char str[]="level";	
	cout<<lps(str);

	return 0;
}
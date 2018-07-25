#include<iostream>

using namespace std;

int solve(int x, int y, int no);
void printGrid(void);
int nextX(int x, int no);
int nextY(int y, int no);

int grid[8][8]={0};
int sq= 8;

int main()
{
	cin>>sq;
	printGrid();
	solve(0,0,1);
	cout<<endl<<endl;
	printGrid();
	return 0;
}

int solve(int x, int y, int no)
{
	int move=0;

	if(no == 65)
	{
		return 1;
	}
	if(grid[x][y] == 0){
		while(move < sq)
		{
			if( (nextX(x,move) != -1) && (nextY(y,move) != -1 ) )
			{
				grid[x][y]=no;
				if(solve(nextX(x,move),nextY(y,move),no+1))
				{
					return 1;
				}
			}
			move++;
		}
		grid[x][y] = 0;
	}
	return 0;
}

int nextX(int x, int move)
{
	if(move == 0 || move == 3){
		x = x + 1;
	}
	else if (move == 1 || move == 2){
		x = x + 2;
	}
	else if (move == 4 || move == 7){
		x = x - 1;
	}
	else if (move == 5 || move == 6){
		x = x - 2;
	}

	if(x<0 || x>7){
		return -1;
	}
	else{
		return x;
	}
}

int nextY(int y, int move)
{
	if(move == 0 || move == 7){
		y = y - 2;
	}
	else if (move == 1 || move == 6){
		y = y - 1;
	}
	else if (move == 2 || move == 5){
		y = y + 1;
	}
	else if (move == 3 || move == 4){
		y = y + 2;
	}

	if(y<0 || y>7){
		return -1;
	}
	else{
		return y;
	}
}

void printGrid()
{
	for(int i=0; i<sq; i++)
	{
		for(int j=0; j<sq; j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}
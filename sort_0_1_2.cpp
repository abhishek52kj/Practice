#include <iostream>
#include <vector>

using namespace std;

vector<int> sort(vector<int> &arr)
{
	int head_1,tail_1,head_2;
	head_1 = tail_1 = head_2 = arr.size();
	vector<int> res;
	
	for(auto it = arr.begin(); it != arr.end(); it++)
		res.push_back(0);

	for(auto it = arr.begin(); it != arr.end(); it++)
	{
		if(*it == 2)
		{
			if(tail_1 == head_2)
			{
				res[--head_2] = 2;
				head_1 = tail_1 = head_2;							
			}
			else if(tail_1 != head_2)
			{
				res[tail_1--] = 2;
				res[--head_1] = 1;
			}
		}
		else if(*it == 1)
		{
			if(head_1 == tail_1 && head_1 == head_2)
			{
				res[--tail_1] = 1;
				head_1 = tail_1;							
			}			
			else if(tail_1 != head_2)
			{
				res[--head_1] = 1;
			}	
		}
	}
	return res;
}

int main()
{
	vector<int> arr = {0, 2, 1, 2, 0, 1, 2, 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 0},res;
	res = sort(arr);
	for(auto it = res.begin(); it != res.end(); it++)
		cout<<*it<<" ";	
	return 0;
}	
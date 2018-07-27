#include <bits/stdc++.h>

using namespace std;

int myCompare(int x, int y)
{
	string XY = to_string(x).append(to_string(y));
	string YX = to_string(y).append(to_string(x));

	return XY.compare(YX) > 0 ? 1 : 0;
}

void biggestNo(vector<int> arr)
{
	sort(arr.begin(), arr.end(), myCompare);

	for(auto it = arr.begin(); it != arr.end(); it++)
		cout<<*it;
}

int main()
{
	vector <int> arr;
	arr.push_back(54);
	arr.push_back(546);
	arr.push_back(548);
	arr.push_back(60);
	biggestNo(arr);
	return 0;
}
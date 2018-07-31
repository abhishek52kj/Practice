#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;
 
int main()
{
    vector<int> values(10000);
 
    auto f = []() -> int { return rand() % 10000; };
 
    generate(values.begin(), values.end(), f);
 
    auto start = high_resolution_clock::now();
 
    sort(values.begin(), values.end());
 
    auto stop = high_resolution_clock::now();
 
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout<<"Time taken by function: "<<duration.count()<<" microseconds"<<endl;
 
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
 
int isTriplet(int arr[], int n)
{
    for (int i=0; i<n; i++)
        arr[i] = arr[i]*arr[i];
 
    sort(arr, arr + n);

    int triple_count = 0;
 
    for (int i = n-1; i >= 2; i--)
    {
        int l = 0; 
        int r = i-1; 
        while (l < r)
        {
            if (arr[l] + arr[r] == arr[i])
            {
                cout<<sqrt(arr[l])<<" "<<sqrt(arr[r])<<" "<<sqrt(arr[i])<<endl;
                triple_count++;
            }
 
            (arr[l] + arr[r] < arr[i])?  l++: r--;
        }
    }
    return triple_count;
}

int maptriple(int arr[], int n)
{
    map <int,int> ar;
    int j=1,count=0,last=0;

    for(int i=0 ;i<n; i++)
        ar.insert(pair<int,int> (arr[i],arr[i]));
    
    auto it = ar.end();
    it--;
    last = it->first;
    it++;

    for(int i=2 ; ((i*i)+(j*j)) < last+1; i++)
    {
        for(j=1 ; j<i && ((i*i)+(j*j)) < last+1; j++)
        {
            if( (ar.find(2*i*j) != it && ar.find((i*i)-(j*j)) != it && ar.find((i*i)+(j*j)) != it) )
            {
                cout<<2*i*j<<" "<<(i*i)-(j*j)<<" "<<(i*i)+(j*j)<<endl;
                count++;
            }
        }
        j=1;
    }
    return count;
}

int main()
{
    int values[] = {3,4,5,6,7,8,9,10,12,13,15,16,17,20,21,24,25,26,29,30,34,35,37};  // 

    int n = sizeof(values)/sizeof(values[0]);

    auto start = high_resolution_clock::now();
 
    cout<<maptriple(values,n)<<endl;
 
    auto stop = high_resolution_clock::now();
 
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout<<"Execution Time Using Map : "<<duration.count()<<endl;

    start = high_resolution_clock::now();
 
    cout<<isTriplet(values,n)<<endl;
 
    stop = high_resolution_clock::now();
 
    duration = duration_cast<microseconds>(stop - start);
 
    cout<<"Execution Time Using Sort : "<<duration.count()<<endl;

    return 0;
}

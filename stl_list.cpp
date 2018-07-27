#include <iostream>
#include <list>
#include <iterator>

using namespace std;
 
void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << "-->" << *it;
    cout << '\n';
}
 
int main()
{
 
    list <int> llist;
 
 
    for (int i = 0; i < 10; ++i)
    {
        llist.push_back(i * 2);
    }
    cout << "\nList is : head";
    showlist(llist);

    cout << "\nPop Front : head";
    llist.pop_front();
    showlist(llist);
 
    cout << "\nPop Back : head";
    llist.pop_back();
    showlist(llist);
 
    cout << "\nReverse : head";
    llist.reverse();
    showlist(llist);
 
    cout << "\nSort() : head";
    llist.sort();
    showlist(llist);
 
    return 0;
 
}

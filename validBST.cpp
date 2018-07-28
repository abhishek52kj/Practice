#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
int isBST(struct node* node, int min, int max) 
{ 
  if (node==NULL) 
     return 1;
       
  if (node->data < min || node->data > max) 
     return 0; 
 
  return
    isBST(node->left, min, node->data-1) && isBST(node->right, node->data+1, max);  
}
 
int isvalidBST(struct node* node) 
{ 
  return(isBST(node, INT_MIN, INT_MAX)); 
} 
 
 
struct node* newNode(int data)
{
  struct node* ptr = new node;
  ptr->data = data;
  ptr->left = NULL;
  ptr->right = NULL;
 
  return(ptr);
}
 
int main()
{
    int q;
  
    for(int i=0; i<q; i++)
    {
        int n,val;
        cin>>n;
        cin>>val;
        struct node *root = newNode(4);
        cin>>val;
        for(int j=1; j<n; j++)
        {
            cin>>val;
            if(val < root->data)
                root->left = newNode(val);
            else
                root->right = newNode(val);
        }
        if(isvalidBST(root))
        printf("YES");
        else
        printf("NO");
    }
  return 0;
}  

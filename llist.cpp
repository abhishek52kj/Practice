// C program to find n'th node in linked list 
// using recursion
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
 
/*  Given a reference (pointer to pointer) to 
    the head of a list and an int, push a 
    new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Takes head pointer of the linked list and index
    as arguments and return data at index*/
int GetNth(struct Node *head,int n)
{
    int count = 1;
     
    //if count equal too n return node->data
    if(count == n)
    return head->data;
     
    //recursively decrease n and increase 
    // head to next pointer 
    return GetNth(head->next, n-1); 
}
 
/* Drier program to test above function*/
int main()
{
     /* Start with the empty list */
    struct Node* head = NULL;
    
    /* Use push() to construct below list
     1->12->1->4->1  */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);  
    
    /* Check the count function */
    printf("Element at index 3 is %d", GetNth(head, 3));  
    getchar();
}

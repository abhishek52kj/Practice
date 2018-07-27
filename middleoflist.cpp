#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void push_front(struct Node* &front, struct Node* &back, int data)
{
	struct Node* ptr = new Node;
	ptr->data = data;
	
	if(front == NULL)
	{
		ptr->next = NULL;
		front = ptr;
		back = ptr;
	}
	else
	{
		ptr->next = front;
		front = ptr;
	}
}

void push_back(struct Node* &front, struct Node* &back, int data)
{
	struct Node* ptr = new Node;
	ptr->data = data;
	
	if(front == NULL)
	{
		ptr->next = NULL;
		front = ptr;
		back = ptr;
	}
	else
	{
		back->next = ptr;
		back = ptr;
	}
}

void pop_front(struct Node* &front, struct Node* &back)
{
	struct Node* ptr = new Node;
	ptr = front;
	
	if(front == back)
	{
		front = back = NULL;
	}
	else
	{
		front = front->next;
	}
	delete(ptr);
}

void pop_back(struct Node* front, struct Node* back)
{

	struct Node* ptr = new Node;
	ptr = front;

	while(ptr->next != back)
		ptr = ptr->next;
	
	if(front == back)
	{
		front = back = NULL;
	}
	else
	{
		ptr->next->next = NULL;
		ptr = ptr->next;
	}
	delete(ptr);
}

void show_list(struct Node* &front, struct Node* &back)
{
	struct Node* ptr = new Node;
	ptr = front;

	while(ptr != NULL)
	{
		cout<<"->"<<ptr->data;
		ptr = ptr->next;
	}
	cout<<endl;
}

int middle(struct Node* &front, struct Node* &back)
{
	struct Node* fastptr = new Node;
	struct Node* slowptr = new Node;
	
	fastptr = slowptr = front;

	if(front == NULL)
		return -1;

	while(fastptr != back)
	{
		fastptr = fastptr->next->next;
		slowptr = slowptr->next;
	}
	return slowptr->data;
}

int main()
{
	struct Node* front=NULL;
	struct Node* back=NULL;
	push_front(front,back,1);
	push_front(front,back,2);
	push_front(front,back,3);
	push_front(front,back,4);
	push_front(front,back,5);
	cout<<"head";
	show_list(front,back);

	cout<<middle(front,back);

	return 0;
}
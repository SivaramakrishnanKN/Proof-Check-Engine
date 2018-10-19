#include<iostream>
#include<stdio.h>

// Structure of a Node of the Parse tree
struct node{
	struct node * left;
	struct node * right;
	char x;
} node;

// Function to insert a node into the Parse tree
void insert(struct node ** head, char data)
{
	struct node * temp;
	
	if(*head == NULL) {
		temp = new struct node;
		temp->x = data;
		temp->left = NULL;
		temp->right = NULL;
		*head = temp;
	}
	
	else if((*head)->x=='!') {
	char ch;
	std::cin>>ch;
	insert(&(*head)->right, data);
	}
	
	else {
	printf("Insert left(l) or right(r)");
	char ch;
	std::cin>>ch;
	if(ch=='l')
	{
		insert(&(*head)->left, data);
	}
	else if (ch=='r')
	{
		insert(&(*head)->right, data);
	}
	}
}

void inorder(struct node * head)
{
	if(head !=NULL)
	{
		inorder(head->left);
		std::cout<<head->x;
		inorder(head->right);
	}
}	

int main()
{
	struct node * head = NULL;
	
	int n=0;
	do {
	std::cout<<"1.Insert a node\n2.Parse In-Order\n3.Parse Pre-Order\n4.Parse Post-Order\n5.Exit\n";
	std::cin>>n;
	if(n==1)
	{
		char d;
		printf("Enter the node data");
		fflush(stdin);
		std::cin>>d;
		insert(&head, d);
	}
	else if(n==2)
	{
		inorder(head);
	}
	}while(n!=5);		
return 0;
}


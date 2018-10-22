#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;



// Stack with Push, Pop, Display Functions
class Stack {

	public:
	// Structure of Stack
	struct Node {
		char Value; // Holds Symbol
		int Priority; // Holds Priority value of the Symbol
		Node * Next; // Pointer to next Node
	};
	Node * top; //Pointer to the top of the Stack

	// Default Constructor assigns top as NULL
	Stack() {
		top=NULL;
	}

	// Push X to top of the Stack
	void Push(char X, int P = 0) {
		Node * temp = new Node;
		temp->Value = X;
		temp->Priority = P;
		temp->Next = top;
		top = temp;
	}

	// Pop the last element from the stack
	void Pop() {
		// If there is no Node in the stack then exit
		if(top==NULL)
			return;
		Node * temp = top;
		top = top->Next;
		delete temp; // Deletes old Top node
	}

	// Displays Every node in the Stack from Top to Bottom
	void Display() {
		Node * temp =top;
		while(temp!=NULL) {
			std::cout<<temp->Value;
			temp = temp->Next;
		}
	}
};

/*
	1. Scan the infix expression from left to right.
	2. If the scanned character is an operand, output it.
	3. Else,
	…..3.1 If the precedence of the scanned operator is greater than the precedence of the
	operator in the stack(or the stack is empty), push it.
	…..3.2 Else, Pop the operator from the stack until the precedence of the scanned operator
	is less-equal to the precedence of the operator residing on the top of the stack. Push
	the scanned operator to the stack.
	4. If the scanned character is an ‘(‘, push it to the stack.
	5. If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is
	encountered.
	6. Repeat steps 2-6 until infix expression is scanned.
	7. Pop and output from the stack until it is not empty.
*/

int Check_Operator(char op, Stack s) {
	if(s.top == NULL)
		return 1;
	int P;
	if(op=='^')
		P = 4;
	else if(op=='+')
		P = 3;
	else if(op=='~')
		P = 5;
	else if(op=='>')
		P = 2;
    if(s.top->Priority=='^')
		P = 4;
	else if(s.top->Priority=='+')
		P = 3;
	else if(s.top->Priority=='~')
		P = 5;
	else if(s.top->Priority=='>')
		P = 2;
	if(P>s.top->Priority)
		return 1;
	else return 0;
}

string Infix_to_Postfix(string Infix) {
	string Postfix;
	Stack tack;
	for(int i=0; i<Infix.length(); i++) {

		// If Infix[i] is an Operand push it into the Postfix string
		if(tolower(Infix[i])>='a'&&tolower(Infix[i])<='z')
			Postfix+=Infix[i];

		// If Infix[i] is '(' then push it into the stack
		else if(Infix[i]=='(') {
			tack.Push(Infix[i]);
		}

		// If Infix[i] is an Operator push it into the stack if it is of a higher precedence
		// than the last element of the  stack
		else if(Infix[i]=='^'||Infix[i]=='+'||Infix[i]=='~'||Infix[i]=='>') {
			tack.Push(Infix[i]);

		}
		else if(Infix[i]==')') {
			while(tack.top->Value!='(')
				Postfix+=tack.top->Value;
				tack.Pop();
            tack.Pop();
		}
		cout<<"Stack: ";
		tack.Display();
		cout<<" Postfix: "<<Postfix<<"\n";
	}
}

// Binary Parse tree with Insert and Traverse Functions
class Parse_Tree {
	public:
	struct node{
		node * left;
		node * right;
		char x;
	};
	node * Root;
	Parse_Tree() {
		Root->left = NULL;
		Root->right = NULL;
		Root->x = '\0';
	}
	// Function to insert a node into the Parse tree
	void Insert(node ** head, char data)
	{
		node * temp;

		if(*head == NULL) {
			temp = new node;
			temp->x = data;
			temp->left = NULL;
			temp->right = NULL;
			*head = temp;
		}

		else if((*head)->x=='!') {
		char ch;
		std::cin>>ch;
		Insert(&(*head)->right, data);
		}

		else {
		printf("Insert left(l) or right(r)");
		char ch;
		std::cin>>ch;
		if(ch=='l')
		{
			Insert(&(*head)->left, data);
		}
		else if (ch=='r')
		{
			Insert(&(*head)->right, data);
		}
		}
	}

	void inorder(node * head)
	{
		if(head !=NULL)
		{
			inorder(head->left);
			std::cout<<head->x;
			inorder(head->right);
		}
	}

};

int main() {

	Stack s;
	int n=0;
	/*
	do {
		cout<<"\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
		cin>>n;
		if(n==1) {
			cout<<"Enter the symbol: ";
			char X;
			fflush(stdin);
			std::cin>>X;
			if(X=='^')
				s.Push(X,4);
			else if(X=='V')
				s.Push(X,3);
			else if(X=='>')
				s.Push(X,2);
			else if(X=='~')
				s.Push(X,5);
			else if(X=='(')
				s.Push(X,1);
			else if(X==')')
				s.Push(X,1);
			else if(tolower(X)>='a'&&tolower(X)<='z')
				s.Push(X,0);		}
		else if(n==2)
			s.Pop();
		else if(n==3)
			s.Display();
		else if(n==4);
		else cout<<"Invalid Input";

	} while(n!=4);
	*/
	string Infix;
	cout<<"Enter an infix with Proper Paranthesis: ";
	cin>>Infix;
	Infix = "(" + Infix + ")";
	cout<<Infix;
	string Postfix = Infix_to_Postfix(Infix);
	cout<<"\nThe final Postfix is: "<<Postfix;
	return 0;
}

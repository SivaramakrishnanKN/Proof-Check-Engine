#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

struct Operator {
	char Symbol;
	int Priority;
};

// Stack with Push, Pop, Display Functions
class Stack {
	// Structure of Stack
	struct Node {
		char Value; // Holds Symbol
		int Priority; // Holds Priority value of the Symbol
		Node * Next; // Pointer to next Node
	};
	Node * top; //Pointer to the top of the Stack
		
	public:
	
	// Default Constructor assigns top as NULL
	Stack() {
		top=NULL;
	}
	
	// Push X to top of the Stack
	void Push(char X, int p ) {
		Node * temp = new Node;
		temp->Value = X;
		temp->Priority = p;
		temp->Next = top;
		top = temp;	
	}
	
	// Pop the last element from the stack
	Node Pop() {
		// If there is no Node in the stack then exit
		if(top==NULL) {
			cout<<"Error";
			return;
		}		
		Node * temp = top;
		top = top->Next;
		delete(temp); // Deletes old Top node
	}
	
	// Displays Every node in the Stack from Top to Bottom
	void Display() {
		Node * temp =top;
		while(temp!=NULL) {
			std::cout<<temp->Value<<" ";
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
	
	if(s.top->Priority
}

void Infix_to_Postfix(string s) {
	string Postfix;
	Stack stack;
	for(int i=0; i<s.length(); i++) {
	
		// If s[i] is an Operand push it into the Postfix string
		if(tolower(s[i])>='a'&&tolower(s[i])<='z')
			Postfix+=s[i];
		
		// If s[i] is '(' then push it into the stack
		else if(s[i]=='(') {
			stack.Push(s[i]);
		}
		
		// If s[i] is an Operator push it into the stack if it is of a higher precedence
		// than the last element of the  stacl
		else if(s[i]=='^') {
			
		}
		
	}
}

int main() {

	Stack s;
	int n=0;
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
			else if(X=='V',3)
				s.Push(X);
			else if(X=='>',2)
				s.Push(X);
			else if(X=='~')
				s.Push(X,5);
			else if(X=='(')
				s.Push(X,1);
			else if(X==')')
				s.Push(X,1);
			else if(tolower(X)>='a'&&tolower(X)<='b')
				s.Push(X,0);
		
		}
		else if(n==2)
			s.Pop();
		else if(n==3)
			s.Display();
		else if(n==4);
		else cout<<"Invalid Input";
	
	} while(n!=4);

	return 0;
}

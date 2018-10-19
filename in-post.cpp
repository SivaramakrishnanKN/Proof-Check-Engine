#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

// Stack with Push, Pop, Display Functions
class Stack {
	// Structure of Stack
	struct Node {
		char Value; // Holds Symbol
		Node * Next; // Pointer to next Node
	};
	Node * top; //Pointer to the top of the Stack
		
	public:
	
	// Default Constructor assigns top as NULL
	Stack() {
		top=NULL;
	}
	
	// Push X to top of the Stack
	void Push(char X) {
		Node * temp = new Node;
		temp->Value = X;
		temp->Next = top;
		top = temp;	
	}
	
	// Pop the last element from the stack
	char Pop() {
		// If there is no Node in the stack then exit
		if(top==NULL) {
			cout<<"Error";
			return;
		}		
		char Val = top->Value;
		Node * temp = top;
		top = top->Next;
		delete(temp); // Deletes old Top node
		return Val;
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
	int P;
	if(op=='^')
		P = 4;
	else if(op=='V')
		p = 3;
	else if(op=='~')
		p = 5;
	else if(op=='>')
		p = 2;	
	if(P>s.top->Priority)
		return 1;
	else return 0;
}

string Infix_to_Postfix(string Infix) {
	string Postfix;
	Stack stack;
	for(int i=0; i<Infix.length(); i++) {
	
		// If Infix[i] is an Operand push it into the Postfix string
		if(tolower(Infix[i])>='a'&&tolower(Infix[i])<='z')
			Postfix+=Infix[i];
		
		// If Infix[i] is '(' then push it into the stack
		else if(Infix[i]=='(') {
			stack.Push(Infix[i]);
		}
		
		// If Infix[i] is an Operator push it into the stack if it is of a higher precedence
		// than the last element of the  stack
		else if(Infix[i]=='^'||Infix[i]=='V'||Infix[i]=='~'||Infix[i]=='>') {
			if(Check_Operator(Infix[i], stack)) {
				stack.Push(Infix[i]);
			}
			else {
				while(Check_Operator(Infix[i], stack)) {
					Postfix+=stack.Pop();
				}
			}
		}
		else if(Infix[i]=='(')
			stack.Push(Infix[i]);
		else if(Infix[i]==')') {
			while(stack.top->Value!='(')
				Postfix+=stack.Pop();
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
			s.Push(X);
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

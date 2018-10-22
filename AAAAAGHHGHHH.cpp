#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int ret_priority(char Op) {
    if(Op=='>') {
        return 1;
    }
    else if(Op=='^')
        return 3;
    else if(Op=='+')
        return 2;
    else if(Op=='~')
        return 4;
    else
        return 0;
}

// Stack with Push, Pop, Display Functions
class Stack {

	public:
	// Structure of Stack
	struct Node {
		char Value; // Holds Symbol
		Node * Next; // Pointer to next Node
	};
	Node * top; //Pointer to the top of the Stack

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

Infix_to_Postfix(string Infix) {
    string Postfix;
    Stack s;
    for(int i=0; i<Infix.length(); i++) {
        if(tolower(Infix[i])>='a'&&tolower(Infix[i])<='z')
            Postfix+=Infix[i];
        else if(Infix[i]=='(')
            s.Push(Infix[i]);
        else if(Infix[i]==')')
            while(s.top->Value!='(') {
                    Postfix+=s.top->Value;
                    s.Pop();
                  }

        else if(Infix[i]=='^'||Infix[i]=='+'||Infix[i]=='~'||Infix[i]=='>')
            if(ret_priority(Infix[i])>ret_priority(s.top->Value))
                s.Push(Infix[i]);
            else
    }
}
s

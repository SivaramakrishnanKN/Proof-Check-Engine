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

//Converts Infix to Postfix
string Infix_to_Postfix(string Infix) {
    string Postfix;
    Stack s;
    for(int i=0; i<Infix.length(); i++) {
    		// If it is a Literal then add it to Postfix
		if(tolower(Infix[i])>='a'&&tolower(Infix[i])<='z')
            Postfix+=Infix[i];
          // If it is a ( add it to the Stack
		else if(Infix[i]=='(')
			s.Push(Infix[i]);
		// If it is a ) Pop from the stack until an ( is encountered            
		else if(Infix[i]==')') {
			while(s.top->Value!='('&&s.top!=NULL) {
                    Postfix+=s.top->Value;
                    s.Pop();
                  }
          	s.Pop();
          }
          // If it is an Operator, Push to the stack if it has a higher Precedence than the
          // last element of the stack, else Pop from the stack until its precedence Becomes
          // lesser than or equal to it 
		else if(Infix[i]=='^'||Infix[i]=='+'||Infix[i]=='~'||Infix[i]=='>') {
			if(ret_priority(Infix[i])>ret_priority(s.top->Value))
				s.Push(Infix[i]);
			else if(ret_priority(Infix[i])<=ret_priority(s.top->Value)) {
				Postfix+=s.top->Value;
				s.Pop();
				i--;
			}				
		}
	}
	return Postfix;
}

class Parse_Tree {
	
	struct node{
		node * left;
		node * right;
		char x;
	};
	
	public: 
	node * root;
	// Constructors
	Parse_Tree(string Postfix) {
		node * temp = new node;
		temp->x = Postfix[0];
		temp->left = NULL;
		temp->right = NULL;
		root = temp;
	}
	Parse_Tree() {
		root = NULL;
	}
	
	// Function to insert a node into the Parse tree
	void Insert(node ** head, char data) {
		node * temp = new node;
		temp->x = data;
		temp->left = NULL;
		temp->right = NULL;
		*head = temp;
	}
		
	void Inorder(node * head)
	{
		if(head !=NULL)
		{
			Inorder(head->left);
			cout<<head->x;
			Inorder(head->right);
		}
	}	
	
	void Postfix_to_Parsetree(node ** head, string Postfix, int i=0) {
		if(ret_priority(Postfix[i])) {
			Insert(head, Postfix[i]);
			if((*head)->x=='~')				
				Postfix_to_Parsetree(&(*head)->right, Postfix, ++i);
			
			else {
				Postfix_to_Parsetree(&(*head)->right, Postfix, ++i);
				Postfix_to_Parsetree(&(*head)->left, Postfix, ++i);
			}
		}
		else 
			Insert(head, Postfix[i]);
	}
	
	

};

string String_Rev(string S) {
	string temp;
	for( int i=S.length()-1; i>=0; i--)
		temp += S[i];
	return temp;
}

int main() {
	int n=0;
	string Infix;
	cout<<"Enter an infix with Proper Paranthesis: ";
	cin>>Infix;
	Infix = "(" + Infix + ")";
	string Postfix = Infix_to_Postfix(Infix);
	cout<<"Postfix: "<<Postfix<<"\n"<<"Reverse String: "<<String_Rev(Postfix)<<"\n";
	Parse_Tree Tree(Postfix);
	Tree.Postfix_to_Parsetree(&Tree.root, String_Rev(Postfix));
	cout<<"In-Order Traversal of the Parse Tree: ";
	Tree.Inorder(Tree.root);
	
	return 0;
}

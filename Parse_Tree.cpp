#include <iostream>
#include "Parse_Tree.h"
#include "ret_priority.h"

using namespace std;
int i=-1;
    // Parametrized constructor which initialised the Root node of a Postfix
    Parse_Tree::Parse_Tree(string Postfix) {
        node * temp = new node;
        temp->x = Postfix[0];
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
    }
    // Default Constructor
    Parse_Tree::Parse_Tree() {
        root = NULL;
    }

    // Function to insert a node into the Parse tree
    void Parse_Tree::Insert(node ** head, char data) {
        node * temp = new node;
        temp->x = data;
        temp->left = NULL;
        temp->right = NULL;
        *head = temp;
    }

    // Performs In-Order traversal of the Parse Tree and prints each node
    void Parse_Tree::Inorder(node * head)
    {
        if(head!=NULL)
        {
        	if ((head->left==NULL&&head->right==NULL)||head->x=='~') {
		        
		        Inorder(head->left);
		        cout<<head->x;
		        Inorder(head->right);
		    	
        	}
        	else {
 		       	cout<<"(";
        		Inorder(head->left);
		        cout<<head->x;
		        Inorder(head->right);
		        cout<<")";
        	}
        }
    }

    // Recursive funtion which converts a given Postfix into a Parse Tree
    void Parse_Tree::Postfix_to_Parsetree(node ** head, string Postfix, int i) {
        ::i++;
        if(ret_priority(Postfix[i])) {
            Insert(head, Postfix[i]);
            if((*head)->x=='~')    {
                i = ::i;
                Postfix_to_Parsetree(&(*head)->right, Postfix, ++i);
            }
            else {
                i = ::i;
                Postfix_to_Parsetree(&(*head)->right, Postfix, ++i);
                i = ::i;
                Postfix_to_Parsetree(&(*head)->left, Postfix, ++i);
            }
        }
        else {
            i = ::i;
            Insert(head, Postfix[i]);
        }
    }


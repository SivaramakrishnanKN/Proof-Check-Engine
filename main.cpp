#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "Parse_Tree.h"
#include "Stack.h"
#include "String_Rev.h"
#include "ret_priority.h"
#include "Infix_to_Postfix.h"

using namespace std;

int main() {
    int n=0;
    string Infix;
    cout<<"Enter an infix with Proper Paranthesis: ";
    cin>>Infix;
    Infix = "(" + Infix + ")";
    string Postfix = Infix_to_Postfix(Infix);
    cout<<"Postfix: "<<Postfix<<"\n";
    Parse_Tree Tree(String_Rev(Postfix));
    Tree.Postfix_to_Parsetree(&Tree.root, String_Rev(Postfix), 0);
    cout<<"In-Order Traversal of the Parse Tree: ";
    Tree.Inorder(Tree.root);
    cout<<"\n";
    return 0;
}

#ifndef _removeneg_h
#define _removeneg_h
using namespace std;

class Parse_Tree {

    struct node{
        node * left;
        node * right;
        char x;
    };

    public:

    //Contains the root node of the Parse Tree
    node * root;

    // Parametrized constructor which initialised the Root node of a Postfix
    Parse_Tree(string Postfix);
    Parse_Tree();
    void Insert(node ** head, char data);
    void Inorder(node * head);
    void Postfix_to_Parsetree(node ** head, string Postfix, int i);
};

#endif

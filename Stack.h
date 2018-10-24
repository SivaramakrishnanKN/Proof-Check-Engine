#ifndef _Stack_h
#define _Stack_h

class Stack {

    public:
    // Structure of Stack
    struct Node {
        char Value; // Holds Symbol
        Node * Next; // Pointer to next Node
    };
    Node * top; //Pointer to the top of the Stack

    // Default Constructor assigns top as NULL
    Stack();
    void Push(char X);
    void Pop();
    void Display();

};

#endif


#include <iostream>
#include "Stack.h"
using namespace std;
// Stack with Push, Pop, Display Functions
    Stack::Stack() {
        top=NULL;
    }

    // Push X to top of the Stack
    void Stack::Push(char X) {
        Node * temp = new Node;
        temp->Value = X;
        temp->Next = top;
        top = temp;
    }

    // Pop the last element from the stack
    void Stack::Pop() {
        // If there is no Node in the stack then exit
        if(top==NULL)
            return;
        Node * temp = top;
        top = top->Next;
        delete temp; // Deletes old Top node
    }

    // Displays Every node in the Stack from Top to Bottom
    void Stack::Display() {
        Node * temp =top;
        while(temp!=NULL) {
            std::cout<<temp->Value;
            temp = temp->Next;
        }
    }

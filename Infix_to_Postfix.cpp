#include "Infix_to_Postfix.h"
#include <iostream>
#include <string>
#include "Stack.h"
#include "ret_priority.h"
using namespace std;
// Converts Infix to Postfix
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


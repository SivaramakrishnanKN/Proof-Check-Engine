#include "ret_priority.h"

// Returns the Priority of an Operator and returns 0 if its not an Operator
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

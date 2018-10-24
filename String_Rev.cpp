#include <iostream>
#include <string>
#include "String_Rev.h"
using namespace std;

// Funtion to reverse a String
std::string String_Rev(std::string S) {
    string temp;
    for( int i=S.length()-1; i>=0; i--)
        temp += S[i];
    return temp;
}


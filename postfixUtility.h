#ifndef POSTFIXUTILITY_H
#define POSTFIXUTILITY_H

#include <iostream>
#include <string>
#include "genericLinkedListStack.h"

class postFix {
public:
    bool isOperator(char ch);
    bool precedence(char leftOp, char rightOp);
    float doCalc(float op1, float op2, char symbol);
    string getPostfix(string nexp);
    float evaluatePostfix(string pexp);
};

#endif // POSTFIXUTILITY_H

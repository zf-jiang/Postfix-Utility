#include <iostream>
#include <string>
#include <cctype>
#include "postfixUtility.h"

using namespace std;

// check if current scan is an operator
bool postFix::isOperator(char ch) {
    switch (ch) {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    default:
        return false;
    }
}

// check precedence of operator
bool postFix::precedence(char leftOp, char rightOp) {
    if (leftOp == '*' || leftOp == '/') {
        return true;
    }
    else if (rightOp == '*' || rightOp == '/') {
        return false;
    }
    return true;
}

// performs calculation on two operands
float postFix::doCalc(float op1, float op2, char symbol) {
    switch (symbol) {
    case '+':
        return op1+op2;
    case '-':
        return op1-op2;
    case '*':
        return op1*op2;
    case '/':
        return op1/op2;
    }
}

// transforms infix expression to postfix
string postFix::getPostfix(string nexp) {
    genericLinkedListStack<char> cStack;
    string postfix;
    cStack.push('(');  // push left parenthesis to test parenthesis matching

    // begin scanning infix from left to right
    for (int i = 0; i < nexp.length(); i++) {
        const char ch = nexp[i];
        // ignore spaces
        if (isspace(ch)) {
            continue;
        }
        // check if last element scanned is an operator
        // if true, find precedence and append to postfix accordingly
        else if (isOperator(ch)) {
            char rightOp = ch;
            while (!cStack.empty() &&
            isOperator(cStack.top()) &&
            precedence(cStack.top(), rightOp)) {
                postfix += ' ';
                postfix += cStack.top();
                cStack.pop();
            }
            postfix += ' ';
            cStack.push(rightOp);
        }
        // push left parenthesis onto stack
        else if (ch == '(') {
            cStack.push(ch);
        }
        // pop everything on stack until left parenthesis and append to postfix
        else if (ch == ')') {
            while (!cStack.empty() &&
            cStack.top() != '(') {
                postfix += ' ';
                postfix += cStack.top();
                cStack.pop();
            }
            // pop left parenthesis
            cStack.pop();
        }
        // append operand to postfix
        else {
            postfix += ch;
        }
    }
    while (!cStack.empty() &&
    cStack.top() != '(') {
        postfix += ' ';
        postfix += cStack.top();
        cStack.pop();
    }
    // check for missing left parenthesis
    if (cStack.empty()) {
        throw RuntimeException("Missing left parenthesis");
    }
    // pop dummy parenthesis
    cStack.pop();
    // check for missing right parenthesis
    if (!cStack.empty()) {
        throw RuntimeException("Missing right parenthesis");
    }
    return postfix;
}

// evaluating postfix
float postFix::evaluatePostfix(string pexp) {
    genericLinkedListStack<float> fStack;
    // scan postfix from left to right
    for (int i = 0; i < pexp.length(); i++) {
        char ch = pexp[i];
        // ignore spaces
        if (isspace(ch)) {
            continue;
        }
        // push operand onto stack
        else if (isalnum(ch)) {
            float operand = 0;
            while (i < pexp.length() && isalnum(pexp[i])) {
                ++i;
                operand = (operand*10) + (ch - '0');
            }
            fStack.push(operand);
        }
        // perform calculation on most recent two operands and push result to stack
        else {
            float operand2 = fStack.top();  fStack.pop();
            float operand1 = fStack.top();  fStack.pop();
            float result = doCalc(operand1, operand2, ch);
            fStack.push(result);
        }
    }
    return fStack.top();
}

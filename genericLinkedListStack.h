#ifndef GENERICLINKEDLISTSTACK_H
#define GENERICLINKEDLISTSTACK_H

#include <iostream>
#include "SLinkedList.h"
#include "StackExceptions.h"

using namespace std;

template <typename T>
class genericLinkedListStack {
public:
    genericLinkedListStack() : S(), n(0) {}
    int size() const { return n; }
    bool empty() const { return n==0; }
    const T& top() const throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("Top of empty stack");
        }
        return S.front();
    }
    void push(const T& e) {
        ++n;
        S.addFront(e);
    }
    void pop() throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("Pop from empty stack");
        }
        --n;
        S.removeFront();
    }
    void print() const { S.print(); }
private:
    SLinkedList<T> S;
    int n;
};

#endif // GENERICLINKEDLISTSTACK_H

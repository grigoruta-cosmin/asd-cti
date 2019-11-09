#ifndef STACK_H
#define STACK_H

class Stack{
    int len;
    struct Element{
        int data;
        Element *prev;
    };
    Element * top;
public:
    Stack();
    void push(int);
    int pop();
    int getLength(){return len;}
    int peek();
    bool empty();
    int search(int);
    void print();
    ~Stack();
};

#endif
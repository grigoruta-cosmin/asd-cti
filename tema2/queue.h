#ifndef QUEUE_H
#define QUEUE_H

#include <bits/stdc++.h>

struct Element{
    int data;
    Element *next;
};

class Queue{
    int length;
    Element *front, *rear;
public:
    Queue();
    void push(int);
    int pop();
    int peek();
    int getRearData(){if(rear == nullptr){return -1;}else{return rear->data;}}
    bool empty();
    int search(int);
    void afiseaza();
    friend std::istream & operator>>(std::istream &, Queue &);
    friend std::ostream & operator<<(std::ostream &, const Queue &);
    ~Queue();
};

#endif
#ifndef QUEUE_POZ_H
#define QUEUE_POZ_H

struct position{
    int x, y;
};

class Queue_poz{
    struct Element{
        position p;
        Element * next;
    };
    int len;
    Element *front, *rear;
public:
    Queue_poz();
    void push(int, int);
    position pop();
    position peek();
    bool empty();
    int search(int, int);
    void print();
    //~Queue() = ;
};

#endif
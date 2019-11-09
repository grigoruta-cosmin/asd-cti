#ifndef VECTORQUEUE_H
#define VECTORQUEUE_H

#include "queue.h"

class VectorQueue{
    friend class Queue;
    int length;
    Queue *vectorQueue;
public:
    VectorQueue();
    VectorQueue(int);
    Queue & operator[](int);
    int indexOfFree();
    bool empty();
    ~VectorQueue();
};

#endif
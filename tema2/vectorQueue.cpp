#include "vectorQueue.h"
#include <bits/stdc++.h>

VectorQueue::VectorQueue(){
    length = 0;
    vectorQueue = nullptr;
}

VectorQueue::VectorQueue(int n){
    length = n;
    vectorQueue = new Queue[n];
}

Queue & VectorQueue::operator[](int index){
    if(index > length - 1){
        std::cout << "Indexul depaseste lungimea vectorului" << std::endl;
    }
    return vectorQueue[index];
}

int VectorQueue::indexOfFree(){
    for(int i = 0; i < length; i++)
        if(vectorQueue[i].empty() == true){
            return i;
        }
    std::cout << "Nu mai exista nicio linie auxiliara libera" << std::endl;
    std::cout << "Se va returna -1" << std::endl;
    return -1;
}

bool VectorQueue::empty(){
    for(int i = 0; i < length; i++)
        if(vectorQueue[i].empty() == false){
            return false;           
        }
    return true;
}

VectorQueue::~VectorQueue(){
    delete[] vectorQueue;
}
#include <bits/stdc++.h>
#include "queue.h"

Queue::Queue(){
    length = 0;
    front = rear = nullptr;
}

void Queue::push(int data){
    if(front == nullptr){
        front = new Element;
        front->data = data;
        front->next = nullptr;
        rear = front;
        length++;
    }else{
        Element *tmp;
        tmp = new Element;
        tmp->data = data;
        tmp->next = rear;
        rear = tmp;
        length++;
    }
}

int Queue::pop(){
    if(rear == nullptr){
        std::cout << "Coada este goala" << std::endl;
        std::cout << "Se va returna -1" << std::endl;
        return -1;
    }else if(length == 1){
        int result;
        result = front->data;
        Element *tmp;
        tmp = front;
        front = rear = nullptr;
        delete tmp;
        length--;
        return result;
    }else{
        int result;
        Element *del, *tmp;
        del = front;
        tmp = rear;
        result = front->data;
        while(tmp->next != front){
            tmp = tmp->next;
        }
        length --;
        front = tmp;
        delete del;
        return result;
    }
}

int Queue::peek(){
    if(front == nullptr){
        std::cout << "Coada este goala" << std::endl;
        std::cout << "Se va returna -1" << std::endl;
        return -1;
    }else{
        return front->data;
    }
}

bool Queue::empty(){
    if(front != nullptr){
        return false;
    }else{
        return true;
    }
}

int Queue::search(int data){
    if(rear == nullptr){
        std::cout << "Coada este goala" << std::endl;
        std::cout << "Se va returna -1" << std::endl;
        return -1;
    }else{
        int result, count = 0, flag = 1;
        Element *tmp;
        tmp = rear;
        while(tmp != nullptr){
            count++;
            if(tmp->data == data){
                flag = 0;
                break;
            }
            tmp = tmp->next;
        }
        if(flag == 0){
            return length - count;
        }
        return -1;
    }
}

void Queue::afiseaza(){
    if(rear == nullptr){
        std::cout << "Coada este goala" << std::endl;
    }else{
        Element * tmp;
        tmp = rear;
        while(tmp != nullptr){
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
}

std::istream & operator>>(std::istream &in, Queue & queue){
    int val;
    std::cout << "Se vor citi elemente in coada pana la 0" << std::endl;
    while(std::cin >> val && val != 0){
        queue.push(val);
    }
    return in;
}

std::ostream & operator<<(std::ostream &out, const Queue & queue){
    Element * tmp;
    tmp = queue.rear;
    while(tmp != nullptr){
        out << tmp->data << " ";
        tmp = tmp->next;
    }
    out << std::endl;
    return out;
} 

Queue::~Queue(){
    Element *tmp;
    while(rear != nullptr){
        tmp = rear;
        rear = rear->next;
        delete tmp;
    }
    front = rear;
}
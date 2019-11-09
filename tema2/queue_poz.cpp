#include <bits/stdc++.h>
#include "queue_poz.h"

Queue_poz::Queue_poz(){
    len = 0;
    front = rear = nullptr;
}

void Queue_poz::push(int data_x, int data_y){
    if(rear == nullptr){
        rear = new Element;
        position aux;
        aux.x = data_x;
        aux.y = data_y;
        rear->p = aux;
        rear->next = nullptr;
        front = rear;
        len++;
    }else{
        Element *tmp = new Element;
        // tmp->data_x = data_x;
        // tmp->data_y = data_y;
        position aux;
        aux.x = data_x;
        aux.y = data_y;
        tmp->p = aux;
        tmp->next = rear;
        rear = tmp;
        len++;
    }
}

position Queue_poz::pop(){
    if(front == nullptr){
        position aux;
        aux.x = -1;
        aux.y = -1;
        std::cout << "coada este goala!" << std::endl;
        std::cout << "se va returna -1!" << std::endl;
        return aux;
    }else if(front == rear){
        position result = front->p;
        Element *tmp = front;
        front = rear = nullptr;
        delete tmp;
        len--;
        return result;
    }else{
        position result = front->p;
        Element *tmp, *it;
        tmp = front;
        it = rear;
        while(it->next->next != nullptr){
            //std::cout << it->data << std::endl;
            it = it->next;
        }
        front = it;
        front->next = nullptr;
        //std::cout << " ceva : " << front->data << std::endl;
        //std::cout << " --- " << result;
        delete tmp;
        len--;
        return result;
    }
}

position Queue_poz::peek(){
    if(front == nullptr){
        position aux;
        aux.x = -1;
        aux.y = -1;
        std::cout << "coada este goala!" << std::endl;
        std::cout << "se va returna -1" << std::endl;
        return aux;
    }else{
        return front->p;
    }
}

bool Queue_poz::empty(){
    if(front == nullptr){
        return true;
    }else{
        return false;
    }
}

void Queue_poz::print(){
    if(front == nullptr){
        std::cout << "Stiva este goala" << std::endl;
    }else{
        Element *it;
        it = rear;
        while(it != nullptr){
            std::cout << it->p.x << " " << it->p.y << " ";
            it = it->next;
        }
        std::cout << std::endl;
    }
}

// int Queue_poz::search(int data){

// }
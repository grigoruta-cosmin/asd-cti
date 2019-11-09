#include <bits/stdc++.h>
#include "stack.h"

Stack::Stack(){
    top = nullptr;
    len = 0;
}

void Stack::push(int data){
    if(top == nullptr){
        top = new Element;
        top->data = data;
        top->prev = nullptr;
        len++;
    }else{
        Element *add = new Element;
        add->data = data;
        add->prev = top;
        top = add;
        len++;
    }
}

int Stack::pop(){
    if(top == nullptr){
        std::cout << "Stiva este goala, se va returna -1" << std::endl;
        return -1;
    }else{
        int result;
        Element *tmp = top;
        result = tmp->data;
        top = top->prev;
        delete tmp;
        len--;
        return result;
    }
}

int Stack::peek(){
    if(top == nullptr){
        //std::cout << "Stiva este goala, se va returna -1" << std::endl;
        return -1;
    }else{
        int result;
        result = top->data;
        return result;
    }
}

bool Stack::empty(){
    if(top == nullptr){
        return true;
    }else{
        return false;
    }
}

int Stack::search(int data){
    if(top == nullptr){
        std::cout << "Stiva este goala se va returna -1" << std::endl;
        return -1;
    }else{
        Element * tmp = top;
        int count = 0;
        while(tmp != nullptr){
            count++;
            if(tmp->data == data){
                break;
            }
            tmp = tmp->prev;
        }
        if(tmp == nullptr){
            return -1;
        }
        return count;
    }
}

void Stack::print(){
    Element *tmp = top;
    while(tmp != nullptr){
        std::cout << tmp->data << " ";
        tmp = tmp->prev;
    }
    std::cout << std::endl;
}

Stack::~Stack(){
    Element *tmp;
    while(top != nullptr){
        tmp = top;
        top = top->prev;
        delete tmp;
    }
}
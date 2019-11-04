#include <bits/stdc++.h>
#include "list.h"

int main(){
    List lista;
    std::cin >> lista;
    int negCount = 0, pozCount = 0;
    double negSum = 0, negAverage;
    Node *tmp;
    tmp = lista.getFirst();
    while(tmp != nullptr){
        if(tmp->data < 0){
            negSum += (double) tmp->data;
            negCount++;
        }else{
            pozCount++;
        }
        tmp = tmp->next;
    }
    if(negCount == 0){
        std::cout<< "Nu exista numere negative" << std::endl;
    }else{
        std::cout << "Media aritmetica: " << negAverage << std::endl;
        negAverage = negSum / (double) negCount;
    }
    std::cout << "Numarul de termeni pozitivi: " << pozCount << std::endl;
    return 0;
}
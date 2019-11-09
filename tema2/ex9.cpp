#include <bits/stdc++.h>
#include "list.h"

int main(){
    List A, B;
    Node *aux_last = nullptr;
    std::cin >> A;
    Node *aux = A.getFirst();
    while(aux_last != A.getFirst()){
        //std::cout << aux_last << std::endl;
        while(aux->next != aux_last){
            //std::cout << aux->data << std::endl;
            aux = aux->next;
        }
        B.push(aux->data);
        aux_last = aux;
        aux = A.getFirst();
    }
    B.printList();
    int firstValue = aux->data;
    Node * pred, *current, *next;
    pred = next = nullptr;
    current = A.getFirst();
    while(current != nullptr){
        next = current->next;
        current->next = pred;
        pred = current;
        current = next;
    }
    A.setFirst(pred);
    std::cout << A;
    return 0;
}
#include <bits/stdc++.h>
#include "list.h"

int main(){
    List A, B, C;
    std::cin >> A >> B;
    Node *tmp1, *tmp2;
    tmp1 = A.getFirst();
    tmp2 = B.getFirst();
    while(tmp1 != nullptr && tmp2 != nullptr){
        if(tmp1->data > tmp2->data){
            C.push(tmp2->data);
            tmp2 = tmp2->next;
        }else{
            C.push(tmp1->data);
            tmp1 = tmp1->next;
        }
    }
    while(tmp1 != nullptr){
        C.push(tmp1->data);
        tmp1 = tmp1->next;
    }
    while(tmp2 != nullptr){
        C.push(tmp2->data);
        tmp2 = tmp2->next;
    }
    std::cout << C;
    return 0;
}
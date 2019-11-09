#include <bits/stdc++.h>
#include "list.h"

int main(){
    int count = 0;
    List C, A, B;
    std::cin >> C;
    Node *tmp = C.getFirst();
    while(tmp != nullptr){
        if(count % 2 == 0){
            A.push(tmp->data);
        }else{
            B.push(tmp->data);
        }
        count++;
        tmp = tmp->next;
    }
    std::cout << A << B;
    return 0;
}
#include <bits/stdc++.h>
#include "list.h"

int main(){
    List lista(10), ordList;
    std::cin >> ordList;
    std::cout << ordList;
    Node *tmp;
    ordList.orderedList();
    std::cout << ordList;
    return 0;
}
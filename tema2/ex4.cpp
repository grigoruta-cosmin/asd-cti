#include <bits/stdc++.h>
#include "stack.h"

int main(){
    Stack stack;
    int n, val, *vec;
    std::cin >> n;
    vec = new int[n];
    for(int i = 0; i < n; i++){
        std::cin >> vec[i];
    }
    for(int i = 0; i < n; i++){
        if(vec[i] != stack.peek()){
            stack.push(vec[i]);
        }else{
            stack.pop();
        }
    }
    if(stack.empty() == true){
        std::cout << "configuratie valida" << std::endl;
    }else{
        std::cout << "configuratie invalida" << std::endl;
    }
    return 0;
}
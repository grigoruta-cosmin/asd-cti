#include <bits/stdc++.h>
#include "stack.h"

int main(){
    // int flag = 1;
    Stack stack;
    std::string w;
    std::cin >> w;
    int val = 0;
    stack.push(w[0]);
    for(int i = 1; i < w.size(); i++){
        if((int) w[i] == stack.peek()){
            stack.push(w[i]);
        }else if((int) w[i] != stack.peek()){
            stack.pop();
        }
        // std::cout << "val : " << val << std::endl;
    }
    //stack.print();
    if(stack.empty() == true){
        std::cout << "numarul de aparitii este acelasi" << std::endl;
    }else{
        std::cout << "numarul de aparitii este diferit" << std::endl;
    }
    return 0;
}
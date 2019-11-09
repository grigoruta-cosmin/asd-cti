#include <bits/stdc++.h>
#include "stack.h"

int main(){
    int flag = 1;
    Stack stiva;
    std::string paranteze;
    std::cin >> paranteze;
    for(int i = 0; i < paranteze.size(); i++)
        if(paranteze[i] == '('){
            stiva.push(1);    
        }else if(paranteze[i] == ')'){
            int val;
            val = stiva.pop();
            if(val != 1){
                std::cout << "incorect parantezat" << std::endl;
                std::cout << i + 1 << std::endl;
                flag = 0;
                break;
            }
        }
    if(flag)
        std::cout << "corect parantezat" << std::endl;
    return 0;
}
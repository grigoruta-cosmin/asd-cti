#include <bits/stdc++.h>
#include "stack.h"

double ridicarePutere(double baza, double exponent){
    double rezultat = 1;
    for(int i = 0; i < exponent; i++)
        rezultat *= baza;
}

int main(){
    std::string formaPoloneza;
    Stack stiva;
    std::cin >> formaPoloneza;
    for(auto i = 0; i < formaPoloneza.size(); i++)
        if(formaPoloneza[i] >= '0' && formaPoloneza[i] <= '9'){
            stiva.push(formaPoloneza[i] - '0');
        }else{
            double operand1, operand2, rezultat;
            operand1 = stiva.pop();
            operand2 = stiva.pop();
            if(formaPoloneza[i] == '+'){
                rezultat = operand2 + operand1;
            }else if(formaPoloneza[i] == '-'){
                rezultat = operand2 - operand1;
            }else if(formaPoloneza[i] == '*'){
                rezultat = operand2 * operand1;
            }else if(formaPoloneza[i] == '/'){
                rezultat = operand2 / operand1;
            }else if(formaPoloneza[i] == '^'){
                rezultat = ridicarePutere(operand1, operand2);
            }
            stiva.push(rezultat);
        }
    if(stiva.getLength() == 1){
        std::cout << stiva.pop() << std::endl;
    }
    return 0;
}
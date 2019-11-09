#include <bits/stdc++.h>
#include "queue.h"
#include "vectorQueue.h"

int main(){
    int k, n, pozitie = 1, flag = 1;
    Queue coadaIn, coadaOut;
    std::cout << "n=" << std::endl;
    std::cin >> n;
    std::cout << "k= " << std::endl;
    std::cin >> k;
    VectorQueue vectorCozi(k);
    std::cout << "Se citesc vagoanele" << std::endl;
    std::cin >> coadaIn;
    std::cout << coadaIn;
    while(coadaIn.empty() == false){
        int val = coadaIn.pop();
        std::cout << "val :" << std::endl;
        // if(coadaIn.empty() == true){
        //     break;
        // }
        std::cout << "!!!-- "<<val << std::endl;
        if(val == pozitie){
            if(vectorCozi.indexOfFree() != -1){
                std::cout << "s-a adaugat in coada auxiliara vida: " << vectorCozi.indexOfFree() << std::endl;
                coadaOut.push(val);
                pozitie++;
            }else{
                std::cout << "Nu se poate cu aceasta configuratie" << std::endl;
                flag = 0;
                break;
            }
        }else{
            int flagForPushing = 0;
            for(int i = 0; i < k; i++){
                if(val > vectorCozi[i].getRearData() || vectorCozi[i].empty() == true){
                    vectorCozi[i].push(val);
                    flagForPushing = 1;
                    break;
                }
            }
            if(flagForPushing == 0){
                std::cout << "!!!Nu se poate cu aceasta configuratie" << std::endl;
                flag = 0;
                break;
            }
        }
    }
    std::cout << "Se vor printa vagoanele de pe liniile auxiliare" << std::endl;
    for(int i = 0; i < k; i++)
        std::cout << vectorCozi[i];
    for(int i = 0; i < k; i++)
        std::cout << vectorCozi[i].peek() << std::endl;
    std::cout << "Introducem vagoanele in ordinea crescatoare" << std::endl;
    while(vectorCozi.empty() == false){
        int minimum = 100000;
        for(int i = 0; i < k; i++){
            if(minimum > vectorCozi[i].peek() && vectorCozi[i].peek() != -1)
                minimum = vectorCozi[i].peek();
        }
        for(int i = 0; i < k; i++){
            std::cout << "minimum: " << minimum << std::endl;
            if(minimum == vectorCozi[i].peek()){
                int val = vectorCozi[i].pop();
                std::cout << "De pe linia " << i << " vagonul " << val << " pleaca" << std::endl;
                coadaOut.push(val);
            }
        }
    }
    std::cout << coadaOut;
    return 0;
}
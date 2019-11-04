#include <bits/stdc++.h>
#include "list.h"

int main(){
    int deRetinut = 0;
    std::string numarMare1, numarMare2, rezultat;
    std::cin >> numarMare1 >> numarMare2;
    List listaNrMare1, listaNrMare2, listaRezultat;
    for(int it = numarMare1.size() - 1; it >= 0; it--)
        listaNrMare1.push(numarMare1[it] - '0');
    for(int it = numarMare2.size() - 1; it >= 0; it--)
        listaNrMare2.push(numarMare2[it] - '0');
    if(listaNrMare2.get_len() > listaNrMare1.get_len()){
        while(listaNrMare1.get_len() != listaNrMare2.get_len()){
            listaNrMare1.push(0);
        }
    }else if(listaNrMare2.get_len() < listaNrMare1.get_len()){
        while(listaNrMare2.get_len() != listaNrMare1.get_len()){
            listaNrMare2.push(0);
        }
    }
    Node *tmp1 = listaNrMare1.getFirst();
    Node *tmp2 = listaNrMare2.getFirst();
    while(tmp1 != nullptr){
        listaRezultat.push((tmp1->data + tmp2->data + deRetinut) % 10);
        deRetinut = (tmp1->data + tmp2->data + deRetinut) / 10;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    if(deRetinut != 0){
        listaRezultat.push(deRetinut);
    }
    std::cout << deRetinut << std::endl;
    std::cout << listaNrMare1 << listaNrMare2 << listaRezultat;
    rezultat.resize(listaRezultat.get_len());
    for(int it = 0; it < rezultat.size(); it++)
        rezultat[it] = listaRezultat.pop() + '0';
    std::cout << rezultat << std::endl;
    return 0;
}
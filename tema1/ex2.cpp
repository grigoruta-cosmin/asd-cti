#include <bits/stdc++.h>
#include "list.h"

int main(){
    int optiune, flag = 1, valoare, pred, ind, val;
    List lista;
    while(flag){
        std::cout << "1. Adauga un nou element la finalul listei" << std::endl;
        std::cout << "2. Adauga un nou element la inceputul listei" << std::endl;
        std::cout << "3. Adauga un nou element dupa o anumita valoarea" << std::endl;
        std::cout << "4. Cauta un element dupa o pozitie" << std::endl;
        std::cout << "5. Stergerea unui element dupa o valoare" << std::endl;
        std::cout << "6. Stergerea unui element dupa o pozitie" << std::endl;
        std::cout << "7. Afisarea listei" << std::endl;
        std::cout << "8. Lista ordonata" << std::endl;
        std::cout << "9. Sterge lista" << std::endl;
        std::cout << "10. Cauta dupa valoare" << std::endl;
        std::cout << "11. Exit" << std::endl;
        std::cout << "Optiunea:" << std::endl;
        std::cin >> optiune;
        switch (optiune){
        case 1:
            std::cout << "Valoarea:" << std::endl;
            std::cin >> valoare;
            lista.push(valoare);
            break;
        case 2:
            std::cout << "Valoarea:" << std::endl;
            std::cin >> valoare;
            lista.unshift(valoare);
            break;
        case 3:
            std::cout << "Valoarea precedenta:" << std::endl;
            std::cin >> pred;
            std::cout << "Valoarea:" << std::endl;
            std::cin >> val;
            lista.addAfterVal(pred, val);
            break;
        case 4:
            std::cout << "Indice:" << std::endl;
            std::cin >> ind;
            std::cout << lista.getIndFromList(ind)->data<< std::endl;
            break;
        case 5:
            std::cout << "Valoare:" << std::endl;
            std::cin >> val;
            lista.deleteVal(val);
            break;
        case 6:
            std::cout << "Indice:" << std::endl;
            std::cin >> ind;
            lista.deleteInd(ind);
            break;  
        case 7:
            std::cout << lista << std::endl;
            break;
        case 8:
            lista.orderedList();
            std::cout << lista;
            break;
        case 9:
            lista.deleteList();
            break;
        case 10:
            std::cout << "Valoarea:" << std::endl;
            std::cin >> val;
            std::cout << lista.contains(val) << std::endl;
            break;
        case 11:
            flag = 0;
            break;
        default:
            std::cout << "Comanda incorecta" << std::endl;
            break;
        }
    }
    return 0;
}
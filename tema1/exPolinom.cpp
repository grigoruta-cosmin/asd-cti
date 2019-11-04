#include <bits/stdc++.h>
#include "polinom.h"

int main(){
    List polinom1, polinom2, rezultatSuma;
    int optiune, flag = 1, scalar, rezultat, x0;
    while(flag){
        std::cout << "1. Inmultirea polinomului cu un scalar" << std::endl;
        std::cout << "2. Polinomul evaluat intr-o valoarea x0" << std::endl;
        std::cout << "3. Suma a doua polinoame" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Optiunea:" << std::endl;
        std::cin >> optiune;
        switch (optiune){
            case 1:
                polinom1.deleteList();
                std::cout << "Intorduceti Polinomul:" << std::endl;
                std::cin >> polinom1;
                std::cout << "Introduceti scalarul:" << std::endl;
                std::cin >> scalar;
                if(scalar == 0){
                    std::cout << "Nu se poate imparti la 0! :)" << std::endl;                    
                }else{
                    polinom1.inmultireaCuScalar(scalar);
                    std::cout << polinom1;
                }
            break;
            case 2:
                polinom1.deleteList();
                std::cout << "Introduceti Polinomul:" << std::endl;
                std::cin >> polinom1;
                std::cout << "Introduceti valoarea x0:" << std::endl;
                std::cin >> x0;
                rezultat = polinom1.valInPunct(x0);
                std::cout << "Rezultatul: ";
                std::cout << rezultat << std::endl;
            break;
            case 3:
                polinom1.deleteList();
                std::cout << "Introduceti primul polinom" << std::endl;
                std::cin >> polinom1;
                std::cout << "Introduceti al doilea polinom" << std::endl;
                std::cin >> polinom2;
                Node *tmp1, *tmp2;
                tmp1 = polinom1.getFirst();
                tmp2 = polinom2.getFirst();
                while(tmp1 != nullptr && tmp2 != nullptr){
                    if(tmp1->grad < tmp2->grad){
                        rezultatSuma.push(tmp1->grad, tmp1->coef);
                        tmp1 = tmp1->next;
                    }else if(tmp1->grad == tmp2->grad){
                        rezultatSuma.push(tmp1->grad, tmp1->coef + tmp2->coef);
                        tmp1 = tmp1->next;
                        tmp2 = tmp2->next;
                    }else{
                        rezultatSuma.push(tmp2->grad, tmp2->coef);
                        tmp2 = tmp2->next;
                    }
                }
                if(tmp1 != nullptr){
                    while(tmp1 != nullptr){
                        rezultatSuma.push(tmp1->grad, tmp1->coef);
                        tmp1 = tmp1->next;
                    }
                }
                if(tmp2 != nullptr){
                    while(tmp2 != nullptr){
                        rezultatSuma.push(tmp2->grad, tmp2->coef);
                        tmp2 = tmp2->next;
                    }
                }
                std::cout << rezultatSuma;
            break;
            case 4:
                flag = 0;
            break;
        default:
            std::cout << "Optiune incorecta!" << std::endl;
            break;
        }
    }
    return 0;
}
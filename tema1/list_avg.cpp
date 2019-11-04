#include <bits/stdc++.h>
#include "list_avg.h"

List::List(){
    len = 0;
    first = nullptr;
}

List::List(int num){
    len = 0;
    first = nullptr;
    if(num == 0){
        List();
    }else{
        for(int i = 0; i < num;i++)
            push(0);
    }
}

Node * List::getFirst(){
    return first;
}

Node * List::getIndFromList(int ind){
    if(ind > len - 1){
        std::cout << "Indicele depaseste lungimea listei" << std::endl;
        return nullptr;
    }else{
        int count = 0;
        Node *tmp = first;
        while(count < ind){
            tmp = tmp->next;
            count++;
        }
        return tmp;
    }
}

void List::push(double data){
    if(first == nullptr){ 
        first = new Node;
        first->data = data;
        first->next = nullptr;
        len++;
    }else{
        Node *tmp, *add;
        add = new Node;
        tmp = first;
        while(tmp->next != nullptr){
            tmp = tmp->next;
        }
        add->data = data;
        add->next = nullptr;
        tmp->next = add;
        len++;
    }
}

double List::pop(){
    double result;
    if(len == 0){
        std::cout << "Lista este goala!" << std::endl;
    }else if(len == 1){
        result = first->data;
        delete first;
        first = nullptr;
        len--;
        return result;
    }else{
        Node *tmp;
        tmp = first;
        while(tmp->next->next != nullptr){
            tmp = tmp->next;
        }
        len--;
        result = tmp->next->data;
        delete tmp->next;
        tmp->next = nullptr;
        return result;
    }
}

void List::printList(){
    if(first == nullptr){
        std::cout << "lista este vida" << std::endl;
    }else{
        Node *tmp;
        tmp = first;
        while(tmp != nullptr){
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
}

int List::get_len(){
    return len;
}

double List::shift(){
    double result;
    if(len == 0){
        std::cout << "Lista este goala" << std::endl;
    }else{
        Node *tmp;
        tmp = first;
        result = tmp->data;
        first = first->next;
        len--;
        delete tmp;
        return result;
    }
}

void List::unshift(double data){
    Node *tmp;
    tmp = new Node;
    tmp->data = data;
    tmp->next = first;
    first = tmp;
    len++;
}

void List::set_len(){
    len++;
}

void List::deleteInd(int ind){
    if(ind > len - 1){
        std::cout << "Indicele depaseste lungimea listei!" << std::endl;
    }else if(ind == len - 1){
        pop();
    }else if(ind == 0){
        shift();
    }else{
        int count = 0;
        Node * tmp = first;
        Node * q;
        while(count < ind - 1){
            count++;
            tmp = tmp->next;
        }
        q = tmp->next;
        tmp->next = q->next;
        delete q;
        len--;
    }
}

void List::deleteVal(double val){
    if(first->data == val){
        shift();
    }else{
        Node *tmp, *pred, *q;
        tmp = first->next;
        pred = first;
        while(tmp->data != val){
            tmp = tmp->next;
            pred = pred->next;
        }
        if(tmp == nullptr){
            std::cout << "Valoarea nu a fost gasita!";
        }else{
            q = pred->next;
            pred->next = q->next;
            delete q;
            len--;
        }
    }
}

void List::addAfterVal(double val, double data){
    if(first == nullptr){
        std::cout << "Stiva este goala" << std::endl;
    }else{
        int ok = 1;
        Node *tmp, *add;
        tmp = first;
        while(tmp->data != val){
            tmp = tmp->next;
            if(tmp->next == nullptr && tmp->data != val){
                std::cout << "Valoarea nu a fost gasita" << std::endl;
                ok = 0;
                break;
            }
        }
        if(ok == 1){
            add = new Node;
            add->data = data;
            add->next = tmp->next;
            tmp->next = add;
            len++;
        }
    }
}

void List::addAfterInd(int ind, double data){
    if(ind > len - 1){
        std::cout << "Indicele depaseste lungimea listei" << std::endl;
    }else if(first == nullptr){
        std::cout << "Lista este goala" << std::endl; 
    }else if(ind == 0){
        Node *tmp = new Node;
        tmp->data = data;
        tmp->next = first->next;
        first->next = tmp;
        len++;
    }else if(ind == len - 1){
        push(data);
    }else{
        int ok = 1, count = 0;
        Node *tmp, *add;
        tmp = first;
        while(count < ind){
            tmp = tmp->next;
            count++;
        }
        add = new Node;
        add->data = data;
        add->next = tmp->next;
        tmp->next = add;
        len++;
    }
}

std::istream & operator >>(std::istream &in, List &list){
    std::cout << "Introduceti elemente in lista(se opreste la valoarea 0):" << std::endl;
    int val;
    std::cin >> val;
    while(val){
        list.push(val);
        std::cin >> val;
    }
    return in;
}

std::ostream & operator <<(std::ostream &out, List &list){
    Node *tmp;
    tmp = list.getFirst();
    while(tmp != nullptr){
        out << tmp->data << " ";
        tmp = tmp->next;
    }
    out << std::endl;
    return out;
}

bool List::contains(double value){
    Node *tmp;
    tmp = first;
    while(tmp != nullptr){
        if(tmp->data == value){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void List::deleteList(){
    Node *tmp;
    while(first != nullptr){
        tmp = first;
        first = first->next;
        delete tmp;
    }
    len = 0;
}

void List::orderedList(){
    std::cout << "Ati apelat metoda de creare a unei liste ordonate." << std::endl;
    std::cout << "Introduceti numere de la tastatura pana la valoarea 0." << std::endl;
    int tmp_val;
    Node *it, *q, *pred;
    deleteList();
    while(std::cin >> tmp_val && tmp_val){
        if(first == nullptr){
            push(tmp_val);
        }else{
            if(len == 1){
                if(first->data > tmp_val){
                    unshift(tmp_val);
                }else{
                    push(tmp_val);
                }
            }else{
                if(first->data > tmp_val){
                    unshift(tmp_val);
                }else{
                    it = first;
                    while(it->next != nullptr && it->next->data < tmp_val){
                        it = it->next;
                    }
                    q = new Node;
                    q->data = tmp_val;
                    q->next = it->next;
                    it->next = q;
                }
            }
        }
    }
}

List & List::operator=(const List & list){
    if(this != &list){
        deleteList();
        Node *aux_it;
        aux_it = list.first;
        while(aux_it != nullptr){
            push(aux_it->data);
            aux_it = aux_it->next;
        }
    }
    return *this;
}

List::~List(){
    Node *tmp;
    while(first != nullptr){
        tmp = first;
        first = first->next;
        delete tmp;
    }
}

List operator+(List& list1, List &list2){
    List reslist(list1.len + list2.len);
    Node *tmp1, *tmp2,*tmp;
    tmp = reslist.getFirst();
    tmp1 = list1.getFirst();
    while(tmp1 != nullptr){
        tmp->data = tmp1->data;
        tmp1 = tmp1->next;
        tmp = tmp->next;
    }
    tmp2 = list2.getFirst();
    while(tmp2 != nullptr){
        tmp->data = tmp2->data;
        tmp2 = tmp2->next;
        tmp = tmp->next;
    }
    return reslist;
}

void List::addAvgBetween(){
    if(len == 1 || len == 0){
        std::cout << "Lista nu are termeni sufiecienti!" << std::endl; 
    }else{
        Node *tmp = first;
        while(tmp->next != nullptr){
            Node * q = new Node;
            q->data = (tmp->data + tmp->next->data) / 2;
            q->next = tmp->next;
            tmp->next = q;
            tmp = tmp->next->next;
            len++;
        }
    }
}
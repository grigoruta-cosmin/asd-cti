#ifndef POLINOM_H
#define POLINOM_H
#include <bits/stdc++.h>

struct Node{
    int grad, coef;
    Node *next;
};

class List{
    private:
        int len;
        Node *first; 
    public:
        List();
        List(int);
        void printList();
        void push(int, int);
        int pop();
        int shift();
        void unshift(int);
        Node * getFirst();
        Node * getIndFromList(int);
        void orderedList();
        int valInPunct(int);
        void inmultireaCuScalar(int);
        void deleteVal(int);
        void deleteInd(int);
        void deleteList();
        void addAfterVal(int, int);
        void addAfterInd(int, int);
        void addAvgBetween();
        bool contains(int);
        int get_len();
        void set_len();
        friend std::istream & operator >>(std::istream&, List&);
        friend std::ostream & operator <<(std::ostream&, List&);
        friend List operator+(List &, List&);
        List & operator =(const List &);
        ~List();
};

#endif
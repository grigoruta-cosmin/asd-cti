#ifndef LIST_AVG_H
#define LIST_AVG_H
#include <bits/stdc++.h>

struct Node{
    double data;
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
        void push(double);
        double pop();
        double shift();
        void unshift(double);
        Node * getFirst();
        Node * getIndFromList(int);
        void orderedList();
        void deleteVal(double);
        void deleteInd(int);
        void deleteList();
        void addAfterVal(double, double);
        void addAfterInd(int, double);
        void addAvgBetween();
        bool contains(double);
        int get_len();
        void set_len();
        friend std::istream & operator >>(std::istream&, List&);
        friend std::ostream & operator <<(std::ostream&, List&);
        friend List operator+(List &, List&);
        List & operator =(const List &);
        ~List();
};

#endif
#include<iostream>
#include"SingleLinkedList.h"
using namespace std;



template <class T>
class Stack{
    private:
        SingleLinkedList<T> sll;
    public:
        void push(T value);
        T pop(); // return the first element and remove it.
        T top(); // return the first element without removing it.
        bool isEmpty();
        int stackSize();
        void clear();
        void print();
};
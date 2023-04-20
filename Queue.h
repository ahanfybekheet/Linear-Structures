#include<iostream>
#include"SingleLinkedList.cpp"
using namespace std;



template <class T>
class Queue{
    private:
        SingleLinkedList<T> sll;
    public:
        void enqueue (T element); 
        T dequeue (); //return the first element and remove it.
        T first (); //return the first element without removing it.
        bool isEmpty (); 
        int queueSize (); 
        void clear (); 
        void print (); 
};
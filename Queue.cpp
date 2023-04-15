#include"Queue.h"


template<class T>
void Queue<T>::enqueue(T value){
    sll.insertAtTail(value);
}

template<class T>
T Queue<T>::dequeue(){
    T x = sll.retrieveAt(0);
    sll.removeAtHead();
    return x;
}

template<class T>
T Queue<T>::first(){
    return  sll.retrieveAt(0);
}


template<class T>
bool Queue<T>::isEmpty(){
    return sll.isEmpty();
}

template<class T>
int Queue<T>::queueSize(){
    return sll.linkedListSize();
}

template<class T>
void Queue<T>::clear(){
    sll.clear();
}

template<class T>
void Queue<T>::print(){
    sll.print();
}


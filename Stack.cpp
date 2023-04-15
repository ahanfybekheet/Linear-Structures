#include"Stack.h"


template<class T>
void Stack<T>::push(T value){
    sll.insertAtHead(value);
}

template<class T>
T Stack<T>::pop(){
    T x = sll.retrieveAt(0);
    sll.removeAtHead();
    return x;
}

template<class T>
T Stack<T>::top(){
    return  sll.retrieveAt(0);
}


template<class T>
bool Stack<T>::isEmpty(){
    return sll.isEmpty();
}

template<class T>
int Stack<T>::stackSize(){
    return sll.linkedListSize();
}

template<class T>
void Stack<T>::clear(){
    sll.clear();
}

template<class T>
void Stack<T>::print(){
    sll.print();
}


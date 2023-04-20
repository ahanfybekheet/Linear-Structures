#include"DoublyLinkedList.h"

template<class T>
void DoublyLinkedList<T>::insertAtHead(T element) {
    Node<T> *newNode = new Node<T>(element);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    size++;
}

template<class T>
void DoublyLinkedList<T>::insertAtTail(T element) {
    Node<T> *newNode = new Node<T>(element);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template<class T>
void DoublyLinkedList<T>::insertAt(T element, int index) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        insertAtHead(element);
    } else if (index == size) {
        insertAtTail(element);
    } else {
        Node<T> *newNode = new Node<T>(element);
        Node<T> *current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
        size++;
    }
}

template<class T>
void DoublyLinkedList<T>::insertAfter(Node<T> *prev_node, T data){
    if (prev_node == NULL) {
        throw std::invalid_argument("Previous node cannot be null");
    }
    Node<T> *newNode = new Node<T>(data);
    newNode->next = prev_node->next;
    newNode->previous = prev_node;
    prev_node->next = newNode;
    if (newNode->next != NULL) {
        newNode->next->previous = newNode;
    } else {
        tail = newNode;
    }
    size++;
}
template<class T>
void DoublyLinkedList<T>::removeAtHead() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot remove from an empty list");
    }
    Node<T> *temp = head;
    head = head->next;
    if (head != NULL) {
        head->previous = NULL;
    } else {
        tail = NULL;
    }
    delete temp;
    size--;
}

template<class T>
void DoublyLinkedList<T>::removeAtTail() {
    if (isEmpty()) {
        throw std::runtime_error("List is empty!");
    }

    Node<T> *temp = tail;
    tail = tail->previous;
    tail->next = nullptr;
    delete temp;
    size--;
    }

template<class T>
void DoublyLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= doubleLinkedListSize()) {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0) {
        removeAtHead();
    } else if (index == doubleLinkedListSize() - 1) {
        removeAtTail();
    } else {
        Node<T> *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->previous->next = current->next;
        current->next->previous = current->previous;
        delete current;
        size--;
    }
    }
template<class T>
T DoublyLinkedList<T>::retrieveAt(int index) {
    if (index < 0 || index >= doubleLinkedListSize()) {
        throw std::out_of_range("Index out of range");
    }

    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

template<class T>
void DoublyLinkedList<T>::replaceAt(T newElement, int index) {
    if (index < 0 || index >= doubleLinkedListSize()) {
        throw std::out_of_range("Index out of range");
    }

    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = newElement;
}

template<class T>
bool DoublyLinkedList<T>::isExist(T element) {
    Node<T> *current = head;
    while (current != nullptr) {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<class T>
bool DoublyLinkedList<T>::isItemAtEqual(T element, int index) {
    if (index < 0 || index >= doubleLinkedListSize()) {
        throw std::out_of_range("Index out of range");
    }
    return retrieveAt(index) == element;
}

template<class T>
void DoublyLinkedList<T>::swap(int firstItemIdx, int secondItemIdx){
    if (firstItemIdx < 0 || firstItemIdx >= doubleLinkedListSize() || secondItemIdx < 0 || secondItemIdx >= doubleLinkedListSize()) {
        throw std::out_of_range("Indexs out of range");
    }
    Node<T> *node1,*node2;
    Node<T> *current = head;
    int biggerIndex = (firstItemIdx > secondItemIdx) ? firstItemIdx : secondItemIdx;
    for (int i = 0; i < biggerIndex; i++,current=current->next) {
        if(i < firstItemIdx){
            node1 = current;
        }
        if (i < secondItemIdx){
            node2 = current;
        }
    }
    T tmp = node1->value;
    node1->value = node2->value;
    node2->value = tmp;
}

template<class T>
void DoublyLinkedList<T>::reverse(){
    Node<T> *currentH = head;
    Node<T> *currentT = tail;
    for (int i = 0; i < size/2; i++,currentH=currentH->next,currentT=currentT->previous)
    {
        T tmp = currentH->value;
        currentH->value=currentT->value;
        currentT->value=tmp;
    }
    
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
    return !bool(size);
}

template<class T>
int DoublyLinkedList<T>::doubleLinkedListSize(){
    return size;
}

template<class T>
void DoublyLinkedList<T>::clear(){
    Node<T> *current = head;
    while(current){
        Node<T> *tmp = current;
        current = current->next;
        delete tmp;
        size--;
    }
    head = NULL;
    tail = NULL;
}

template<class T>
void DoublyLinkedList<T>::forwardTraversal(){
    for (Node<T> *current = head; current;current = current->next){
        cout << current->value << " ";
    }
        cout << endl;
}

template<class T>
void DoublyLinkedList<T>::backwardTraversal(){
    for (Node<T> *current = tail; current;current = current->previous){
        cout << current->value << " ";
    }
        cout << endl;
}
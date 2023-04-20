#include"CircularLinkedList.h"

template<class T>
void CircularLinkedList<T>::insertAtHead(T element) {
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
void CircularLinkedList<T>::insertAtEnd(T element) {
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
void CircularLinkedList<T>::insertAt(T element, int index) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        insertAtHead(element);
    } else if (index == size) {
        insertAtEnd(element);
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
void CircularLinkedList<T>::insertAfter(Node<T> *prev_node, T data){
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
void CircularLinkedList<T>::removeAtHead() {
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
void CircularLinkedList<T>::removeAtEnd() {
    if (isEmpty()) {
        throw std::runtime_error("List is empty!");
    }

    Node<T> *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    size--;
    }

template<class T>
void CircularLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= doubleLinkedListSize()) {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0) {
        removeFromHead();
    } else if (index == doubleLinkedListSize() - 1) {
        removeAtEnd();
    } else {
        Node<T> *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }
    }
template<class T>
T CircularLinkedList<T>::retrieveAt(int index) {
    if (index < 0 || index >= doubleLinkedListSize()) {
        throw std::out_of_range("Index out of range");
    }

    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template<class T>
void CircularLinkedList<T>::replaceAt(T newElement, int index) {
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
bool CircularLinkedList<T>::isExist(T element) {
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
bool CircularLinkedList<T>::isItemAtEqual(T element, int index) {
    if (index < 0 || index >= doubleLinkedListSize()) {
        throw std::out_of_range("Index out of range");
    }
    return retrieveAt(index) == element;
}

template<class T>
void CircularLinkedList<T>::swap(int firstItemIdx, int secondItemIdx){
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
void CircularLinkedList<T>::reverse(){
    Node *currentH = head;
    Node *currentT = tail;
    for (int i = 0; i < size/2; i++,currentH=currentH->next,currentT=currentT->previous)
    {
        T tmp = currentH->value;
        currentH->value=currentT->value;
        currentT->value=tmp;
    }
    
}

template <class T>
bool CircularLinkedList<T>::isEmpty(){
    return bool(size);
}

template<class T>
int CircularLinkedList<T>::circularLinkedListSize(){
    return size;
}

template<class T>
void CircularLinkedList<T>::clear(){
    Node *current = head;
    while(current){
        Node *tmp = current;
        current = current->next;
        delete tmp;
        size--;
    }
    head = Null;
    tail = Null;
}

template<class T>
void CircularLinkedList<T>::print(){
    for (Node<T> *current = head; current;current = current->next){
        cout << current->value << " ";
    }
        cout << endl;
}

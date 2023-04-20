#include<iostream>
#include<stdexcept>

using namespace std;


template<class T>
struct Node
    {
        T value;
        Node *next;
        Node *previous;
        Node(T x) : value(x), next(NULL), previous(NULL){};
    };
template<class T>

class   CircularLinkedList{
    private:
        Node *head;
        Node *tail;
        int size;
    public:
        CircularLinkedList() : head(NULL), tail(NULL), size(0){
            head->previous = tail;
            tail->next = head;
        };
        void insertAtHead(T element);
        void insertAtEnd(T element);
        void insertAt(T element, int index);
        void insertAfter(Node<T> *prev_node, T data);
        void removeAtHead();
        void removeAtEnd();
        void removeAt(int index);
        T retrieveAt(int index);
        void replaceAt(T newElement, int index);
        bool isExist(T element);
        bool isItemAtEqual(T element, int index);
        void swap(int firstItemIdx, int secondItemIdx); // swap two nodes without swapping data.
        void reverse();                   // reverse the data in the double linked list
        bool isEmpty();
        int circularLinkedListSize();
        void clear();
        void print();  
};
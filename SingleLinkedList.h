#include<iostream>

using namespace std;

template<class T>
struct Node
{
    T value;
    Node<T> *next;

    Node()
    {
        value = 0;
        next = NULL;
    }
};

template <class T>
class SingleLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    SingleLinkedList();

    void insertAtHead(T element);

    void insertAtTail(T element);

    void insertAt(T element, int index);

    void removeAtHead();

    void removeAtTail();

    void removeAt(int index);

    T retrieveAt(int index);

    void replaceAt(T newElement, int index);

    bool isExist(T element);

    bool isItemAtEqual(T element, int index);

    void swap(int firstItemIdx, int secondItemIdx);

    bool isEmpty();

    int linkedListSize();

    void clear();

    void print();
};
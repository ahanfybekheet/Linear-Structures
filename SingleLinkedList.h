#include<iostream>

using namespace std;

template <class T>
class SingleLinkedList
{
private:
    struct Node
    {
        T value;
        Node *next;

        Node()
        {
            value = 0;
            next = NULL;
        }
    };
    Node *head;
    Node *tail;
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
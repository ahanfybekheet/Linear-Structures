#include "SingleLinkedList.h"

template <class T>
SingleLinkedList<T>::SingleLinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
void SingleLinkedList<T>::insertAtHead(T element)
{
    Node<T> *newNode = new Node<T>;
    newNode->value = element;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template <class T>
void SingleLinkedList<T>::insertAtTail(T element)
{
    Node<T> *newNode = new Node<T>;
    newNode->value = element;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        tail = newNode;
    }
    size++;
}

template <class T>
void SingleLinkedList<T>::insertAt(T element, int index)
{
    if (index == 0)
    {
        insertAtHead(element);
    }
    else if (index == size)
    {
        insertAtTail(element);
    }
    else
    {
        Node<T> *newNode = new Node<T>;
        newNode->value = element;
        // newNode->next = NULL;
        Node<T> *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
}

template <class T>
void SingleLinkedList<T>::removeAtHead()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (size == 1)
    {
        delete head;
        head = nullptr;
        tail = head;
    }
    else
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    size--;
}

template <class T>
void SingleLinkedList<T>::removeAtTail()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (size == 1)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    size--;
}

template <class T>
void SingleLinkedList<T>::removeAt(int index)
{
    if (index == 0)
    {
        removeAtHead();
    }
    else if (index == size - 1)
    {
        removeAtTail();
    }
    else
    {
        Node<T> *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        Node<T> *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        size--;
    }
}

template <class T>
T SingleLinkedList<T>::retrieveAt(int index)
{
    Node<T> *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->value;
}

template <class T>
void SingleLinkedList<T>::replaceAt(T newElement, int index)
{
    Node<T> *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    temp->value = newElement;
}

template <class T>
bool SingleLinkedList<T>::isExist(T element)
{
    Node<T> *temp = head;
    while (temp != NULL)
    {
        if (temp->value == element)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class T>
bool SingleLinkedList<T>::isItemAtEqual(T element, int index)
{
    Node<T> *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    if (temp->value == element)
    {
        return true;
    }
    return false;
}

// template <class T>
// void SingleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx)
// {
//     Node<T> *temp = head;
//     for (int i = 0; i < firstItemIdx; i++)
//     {
//         temp = temp->next;
//     }
//     Node<T> *temp2 = head;
//     for (int i = 0; i < secondItemIdx; i++)
//     {
//         temp2 = temp2->next;
//     }
//     T tempvalue = temp->value;
//     temp->value = temp2->value;
//     temp2->value = tempvalue;
// }

template <class T>
void SingleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    // If both indices are the same, there is nothing to swap
    if (firstItemIdx == secondItemIdx) {
        return;
    }
    
    // Find the first node to be swapped
    Node<T>* prev1 = nullptr;
    Node<T>* curr1 = head;
    int i = 0;
    while (curr1 != nullptr && i < firstItemIdx) {
        prev1 = curr1;
        curr1 = curr1->next;
        i++;
    }
    
    // Find the second node to be swapped
    Node<T>* prev2 = nullptr;
    Node<T>* curr2 = head;
    i = 0;
    while (curr2 != nullptr && i < secondItemIdx) {
        prev2 = curr2;
        curr2 = curr2->next;
        i++;
    }
    
    // If either node is not found, there is nothing to swap
    if (curr1 == nullptr || curr2 == nullptr) {
        return;
    }
    
    // Update the next pointers of the previous nodes
    if (prev1 != nullptr) {
        prev1->next = curr2;
    } else {
        head = curr2;
    }
    
    if (prev2 != nullptr) {
        prev2->next = curr1;
    } else {
        head = curr1;
    }
    
    // Swap the next pointers of the nodes to be swapped
    Node<T>* temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}


template <class T>
bool SingleLinkedList<T>::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}

template <class T>
int SingleLinkedList<T>::linkedListSize()
{
    return size;
}

template <class T>
void SingleLinkedList<T>::clear()
{
    Node<T> *temp = head;
    while (temp != NULL)
    {
        Node<T> *temp2 = temp;
        temp = temp->next;
        delete temp2;
    }
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
void SingleLinkedList<T>::print()
{
    Node<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
    // cout << "Size of list: " << size << endl;
}

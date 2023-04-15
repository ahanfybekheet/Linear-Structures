#include "SingleLinkedList.h"


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
    SingleLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void insertAtHead(T element)
    {
        Node *newNode = new Node;
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
    void insertAtTail(T element)
    {
        Node *newNode = new Node;
        newNode->value = element;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *temp = head;
			while (temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
			tail = newNode;
        }
        size++;
    }
    void insertAt(T element, int index)
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
            Node *newNode = new Node;
            newNode->value = element;
            //newNode->next = NULL;
            Node *temp = head;
            for (int i = 0; i < index-1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }
    void removeAtHead()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else if (size == 1){
			delete head;
			head = nullptr;
			tail = head;
		}
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;  
        }
        size--;
    }
    void removeAtTail()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else if (size == 1){
			delete tail;
			head = nullptr;
			tail = nullptr;
		}
        else
        {
            Node *temp = head;
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
    void removeAt(int index)
    {
        if (index == 0)
        {
            removeAtHead();
        }
        else if (index == size-1)
        {
            removeAtTail();
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index-1; i++)
            {
                temp = temp->next;
            }
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
            size--;
        }

    }
    T retrieveAt(int index)
    {
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->value;
    }
    void replaceAt(T newElement, int index)
    {
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->value = newElement;
    }
    bool isExist(T element)
    {
        Node *temp = head;
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
    bool isItemAtEqual(T element, int index)
    {
        Node *temp = head;
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
    void swap(int firstItemIdx, int secondItemIdx)
    {
        Node *temp = head;
        for (int i = 0; i < firstItemIdx; i++)
        {
            temp = temp->next;
        }
        Node *temp2 = head;
        for (int i = 0; i < secondItemIdx; i++)
        {
            temp2 = temp2->next;
        }
        T tempvalue = temp->value;
        temp->value = temp2->value;
        temp2->value = tempvalue;
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    int linkedListSize()
    {
        return size;
    }
    void clear()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
        //cout << "Size of list: " << size << endl;
    }

};
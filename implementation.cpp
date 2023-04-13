#include <iostream>
using namespace std;

// array based list

template <class T>
class List
{
private:
    int maxSize;
    int listSize;
    int curr;
    T *listArray;
public:
    List(int size)
    {
        maxSize = size;
        listSize = curr = 0;
        listArray = new T[maxSize];
    }
    
    void insert(T it)
    {
        (listSize < maxSize);
        listArray[listSize++] = it;
    }
    void insertAt(T it, int index)
    {
        (listSize < maxSize);
        (index >= 0 && index <= listSize);
        for (int i = listSize; i > index; i--)
        {
            listArray[i] = listArray[i-1];
        }
        listArray[index] = it;
        listSize++;
    }
    T retrieveAt(int index)
    {
        (index >= 0 && index < listSize);
        return listArray[index];
    }
    void removeAt(int index)
    {
        (index >= 0 && index < listSize);
        for (int i = index; i < listSize-1; i++)
        {
            listArray[i] = listArray[i+1];
        }
        listSize--;
    }
    void replaceAt(T it, int index)
    {
        (index >= 0 && index < listSize);
        listArray[index] = it;
    }
    bool isItemAtEqual(T it, int index)
    {
        (index >= 0 && index < listSize);
        return (listArray[index] == it);
    }
    bool isEmpty()
    {
        return (listSize == 0);
    }
    bool isFull()
    {
        return (listSize == maxSize);
    }
    int ListSize()
    {
        return listSize;
    }
    int maxListSize()
    {
        return maxSize;
    }
    void clear()
    {
        delete [] listArray;
        listSize = curr = 0;
        listArray = new T[maxSize];
    }
    void print()
    {
        for (int i = 0; i < listSize; i++)
        {
            cout << listArray[i] << " ";
        }
        cout << endl;
    }


};


//---------------------------------------------------------------------------------

// single linked list

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

//---------------------------------------------------------------------------------

// stack using Linked List

template <class T>
class Stack 
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
    int size;
public:
    Stack()
    {
        head = NULL;
        size = 0;
    }
    void push(T element)
    {
        Node *newNode = new Node;
        newNode->value = element;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    T pop()
    {
        T nodeValue = head->value;

        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }else if (size == 1)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        size--;
        return nodeValue;
    }
    T top()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else
        {
            return head->value;
        }
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int stackSize()
    {
        return size;
    }
    void clear()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
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
    }
};

//---------------------------------------------------------------------------------

// queue using Linked List

template <class T>
class Queue
{
private:
    struct Node
    {
        T value;
        Node *next;
    };
    Node *front;
    Node *rear;
    int size;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    };
    void enqueue(T element)
    {
        Node *newNode = new Node;
        newNode->value = element;
        newNode->next = NULL;
        if (front == NULL)
        {
            front = newNode;
            rear = front;
        }
        else
        {
           Node *temp = front;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            rear = newNode;
        }
        size++;
    };
    T dequeue()
    {
        T nodeValue = front->value;
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }else if (size == 1)
        {
            cout << front->value << endl;
				delete front ;
				front = nullptr;
				rear = front;
        }
        else
        {
            cout << front->value << endl;
				Node *temp = front;
				front = front->next;
				delete temp ;  
        }
        size--;
        return nodeValue;
    };
    T first()
    {
        if (front == NULL)
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        else
        {
            return front->value;
        }
    };
    bool isEmpty()
    {
        return (size == 0);
    };
    int queueSize()
    {
        return size;
    };
    void clear()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    };
    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    };

    
};

//---------------------------------------------------------------------------------
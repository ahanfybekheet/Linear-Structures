#include "List.h"

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
#include "List.h"

// array-based list

template <class T>
List<T>::List(int size) : maxSize(size), listSize(0), curr(0), listArray(new T[size]) {}

template <class T>
void List<T>::insert(T it)
{
    if (listSize < maxSize)
    {
        listArray[listSize++] = it;
    }
}

template <class T>
void List<T>::insertAt(T it, int index)
{
    if (listSize < maxSize && index >= 0 && index <= listSize)
    {
        for (int i = listSize; i > index; i--)
        {
            listArray[i] = listArray[i - 1];
        }
        listArray[index] = it;
        listSize++;
    }
}

template <class T>
T List<T>::retrieveAt(int index)
{
    if (index >= 0 && index < listSize)
    {
        return listArray[index];
    }
    // Handle error case (e.g., throw an exception, return a default value, etc.)
}

template <class T>
void List<T>::removeAt(int index)
{
    if (index >= 0 && index < listSize)
    {
        for (int i = index; i < listSize - 1; i++)
        {
            listArray[i] = listArray[i + 1];
        }
        listSize--;
    }
}

template <class T>
void List<T>::replaceAt(T it, int index)
{
    if (index >= 0 && index < listSize)
    {
        listArray[index] = it;
    }
}

template <class T>
bool List<T>::isItemAtEqual(T it, int index)
{
    if (index >= 0 && index < listSize)
    {
        return (listArray[index] == it);
    }
}

template <class T>
bool List<T>::isEmpty()
{
    return (listSize == 0);
}

template <class T>
bool List<T>::isFull()
{
    return (listSize == maxSize);
}

template <class T>
int List<T>::ListSize()
{
    return listSize;
}

template <class T>
int List<T>::maxListSize()
{
    return maxSize;
}

template <class T>
void List<T>::clear()
{
    delete[] listArray;
    listSize = curr = 0;
    listArray = new T[maxSize];
}

template <class T>
void List<T>::print()
{
    for (int i = 0; i < listSize; i++)
    {
        cout << listArray[i] << " ";
    }
    cout << endl;
}

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
    List(int size);

    void insert(T it);

    void insertAt(T it, int index);

    T retrieveAt(int index);

    void removeAt(int index);

    void replaceAt(T it, int index);

    bool isItemAtEqual(T it, int index);

    bool isEmpty();

    bool isFull();

    int ListSize();

    int maxListSize();

    void clear();

    void print();
};
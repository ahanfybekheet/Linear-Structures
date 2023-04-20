#include "Queue.cpp"

template <class T>
SingleLinkedList<T> generateBinaryNumbers(int n);
int main(){
    SingleLinkedList<string> binaryNumbers = generateBinaryNumbers<string>(10);
    binaryNumbers.print();
    return 0;
}


template <class T>
SingleLinkedList<T> generateBinaryNumbers(int n)
{
    Queue<T> q;
    SingleLinkedList<T> binaryNumbers;
    q.enqueue("1"); // Enqueue a string

    while (binaryNumbers.linkedListSize() < n)
    {
        T curr = q.first();
        q.dequeue();
        binaryNumbers.insertAtTail(curr);
        T s1 = curr + "0";
        T s2 = curr + "1";
        q.enqueue(s1);
        q.enqueue(s2);
    }

    return binaryNumbers;
}

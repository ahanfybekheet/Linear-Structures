//Combine Nodes Between Zeros
#include "DoublyLinkedList.cpp"
#include "Queue.cpp"

template <class T>
void CombineNodesBetweenZeros(DoublyLinkedList<T> *dll);

template <class T>
DoublyLinkedList<T>* MergeKsortedlinkedlists(DoublyLinkedList<T> **dll,int k);

// template <class T>
// SingleLinkedList<T> generateBinaryNumbers(int n);

// template <class T>
// void sortQueue(Queue<T> &q);


int main(){
    // testing Combine Nodes Between Zeros
    // DoublyLinkedList<int> dll;
    // dll = new DoublyLinkedList<int>;
    // dll->insertAtTail(0);
    // dll->insertAtTail(1);
    // dll->insertAtTail(0);
    // dll->insertAtTail(3);
    // dll->insertAtTail(0);
    // dll->insertAtTail(2);
    // dll->insertAtTail(2);
    // dll->insertAtTail(0);
    // CombineNodesBetweenZeros(dll);
    // dll->forwardTraversal();
    
    //testing Merge K sorted linked lists
    // DoublyLinkedList<int> **dll = new DoublyLinkedList<int>*[3];
    // DoublyLinkedList<int> *dll1 = new DoublyLinkedList<int>;
    // DoublyLinkedList<int> *dll2 = new DoublyLinkedList<int>;
    // DoublyLinkedList<int> *dll3 = new DoublyLinkedList<int>;
    // dll1->insertAtTail(1);
    // dll1->insertAtTail(4);
    // dll1->insertAtTail(5);
    // dll2->insertAtTail(1);
    // dll2->insertAtTail(3);
    // dll2->insertAtTail(4);
    // dll3->insertAtTail(2);
    // dll3->insertAtTail(6);
    // dll[0] = dll1;
    // dll[1] = dll2;
    // dll[2] = dll3;
    // DoublyLinkedList<int> *result = MergeKsortedlinkedlists(dll,3);
    // result->forwardTraversal();

    //  generate binary numbers
    // SingleLinkedList<string> binaryNumbers = generateBinaryNumbers<string>(10);
    // for (int i = 0; i < binaryNumbers.linkedListSize(); i++)
    // {
    //     cout << binaryNumbers.retrieveAt(i) << " ";
    // }
    // return 0;

    // sort queue
    // Queue<int> q;
    // q.enqueue(3);
    // q.enqueue(15);
    // q.enqueue(2);
    // q.enqueue(4);
    // sortQueue(q);
    // q.print();
}




template <class T>
void CombineNodesBetweenZeros(DoublyLinkedList<T> *dll){
    for (int sum=0,i = 1; i < dll->doubleLinkedListSize();dll->removeAt(i)){
        int tmp = dll->retrieveAt(i);
        if(tmp!=0){
            sum += tmp;
        }else{
            dll->insertAt(sum, i - 1);
            sum = 0;
            i++;
        }
    }
    dll->removeAtTail();    

};

template <class T>
DoublyLinkedList<T>* MergeKsortedlinkedlists(DoublyLinkedList<T> **dll, int k) {
    DoublyLinkedList<T>* result = new DoublyLinkedList<T>;
    int indexs[k] = {0}, resultIndex = 0, loopSize = 0;
    for (int i = 0; i < k; i++) {
        loopSize += dll[i]->doubleLinkedListSize();
    }
    for (int i = 0; i < loopSize; i++) {
        T leastElm = 1e+9; // INFINITY
        int leastElmIndex;
        for (int j = 0; j < k; j++) {
            if(indexs[j] < dll[j]->doubleLinkedListSize()){
                if (leastElm > dll[j]->retrieveAt(indexs[j])) {
                    leastElm = dll[j]->retrieveAt(indexs[j]);
                    leastElmIndex = j;
                }
            }
        }
        result->insertAt(leastElm, resultIndex);
        resultIndex++;
        indexs[leastElmIndex]++;
    }
    return result;
}



// template <class T>
// SingleLinkedList<T> generateBinaryNumbers(int n)
// {
//     Queue<T> q;
//     SingleLinkedList<T> binaryNumbers;
//     q.enqueue("1"); // Enqueue a string

//     while (binaryNumbers.linkedListSize() < n)
//     {
//         T curr = q.first();
//         q.dequeue();
//         binaryNumbers.insertAtTail(curr);
//         T s1 = curr + "0";
//         T s2 = curr + "1";
//         q.enqueue(s1);
//         q.enqueue(s2);
//     }

//     return binaryNumbers;
// }

// template <class T>
// void sortQueue(Queue<T> &q)
// {
//     int size = q.queueSize();
//     for (int i = 0; i < size; i++)
//     {
//         T min = q.dequeue();
//         for (int j = 0; j < size - i - 1; j++)
//         {
//             T temp = q.dequeue();
//             if (temp < min)
//             {
//                 q.enqueue(min);
//                 min = temp;
//             }
//             else
//             {
//                 q.enqueue(temp);
//             }
//         }
//         q.enqueue(min);
//     }
// }


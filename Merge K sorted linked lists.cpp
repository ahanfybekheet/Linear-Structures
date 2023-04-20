#include "DoublyLinkedList.cpp"



template <class T>
DoublyLinkedList<T>* MergeKsortedlinkedlists(DoublyLinkedList<T> **dll,int k);


int main(){
    
    DoublyLinkedList<int> **dll = new DoublyLinkedList<int>*[3];
    DoublyLinkedList<int> *dll1 = new DoublyLinkedList<int>;
    DoublyLinkedList<int> *dll2 = new DoublyLinkedList<int>;
    DoublyLinkedList<int> *dll3 = new DoublyLinkedList<int>;
    dll1->insertAtTail(1);
    dll1->insertAtTail(4);
    dll1->insertAtTail(5);
    dll2->insertAtTail(1);
    dll2->insertAtTail(3);
    dll2->insertAtTail(4);
    dll3->insertAtTail(2);
    dll3->insertAtTail(6);
    dll[0] = dll1;
    dll[1] = dll2;
    dll[2] = dll3;
    DoublyLinkedList<int> *result = MergeKsortedlinkedlists(dll,3);
    result->forwardTraversal();
}


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
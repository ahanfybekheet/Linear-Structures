#include "DoublyLinkedList.cpp"



template <class T>
void CombineNodesBetweenZeros(DoublyLinkedList<T> *dll);


int main(){
    DoublyLinkedList<int> *dll;
    dll = new DoublyLinkedList<int>;
    dll->insertAtTail(0);
    dll->insertAtTail(1);
    dll->insertAtTail(0);
    dll->insertAtTail(3);
    dll->insertAtTail(0);
    dll->insertAtTail(2);
    dll->insertAtTail(2);
    dll->insertAtTail(0);
    CombineNodesBetweenZeros(dll);
    dll->forwardTraversal();

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
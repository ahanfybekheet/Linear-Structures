#include "Queue.cpp"

template <class T>
void sortQueue(Queue<T> &q);

int main(){
    Queue<int> q;
    q.enqueue(3);
    q.enqueue(15);
    q.enqueue(2);
    q.enqueue(4);
    sortQueue(q);
    q.print();

}


template <class T>
void sortQueue(Queue<T> &q)
{
    int size = q.queueSize();
    for (int i = 0; i < size; i++)
    {
        T min = q.dequeue();
        for (int j = 0; j < size - i - 1; j++)
        {
            T temp = q.dequeue();
            if (temp < min)
            {
                q.enqueue(min);
                min = temp;
            }
            else
            {
                q.enqueue(temp);
            }
        }
        q.enqueue(min);
    }
}

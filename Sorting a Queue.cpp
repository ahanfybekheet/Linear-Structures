#include "Queue.cpp"

template <class T>
void sortQueue(Queue<T> &q)
{
    int n = q.queueSize(); // get the size of the queue
    for (int i = 1; i <= n; i++)
    {
        // find the index of the minimum element in the unsorted part of the queue
        int minIndex = -1;
        int minVal = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            int curr = q.first();
            q.dequeue();
            if (curr <= minVal && j <= n - i)
            {
                minIndex = j;
                minVal = curr;
            }
            q.enqueue(curr);
        }

        // move the minimum element to the end of the unsorted part of the queue
        T minElement;
        for (int j = 0; j < n; j++)
        {
            T curr = q.first();
            q.dequeue();
            if (j != minIndex)
            {
                q.enqueue(curr);
            }
            else
            {
                minElement = curr;
            }
        }
        q.enqueue(minElement);
    }
}

int main() {
    Queue<int> q;
    q.enqueue(3);
    q.enqueue(15);
    q.enqueue(2);
    q.enqueue(4);
    sortQueue(q);
    q.print(); // expected output: 2 3 4 15
    Queue<int> q2;
    q2.enqueue(9);
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(1);
    sortQueue(q2);
    q2.print(); // expected output: 1 1 2 9
    return 0;

}
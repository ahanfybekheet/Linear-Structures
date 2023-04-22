#include "Queue.cpp"
using namespace std;

void generateBinaryNumbers(int n) {
    Queue<string> q;
    q.enqueue("1");

    for (int i = 1; i <= n; i++) {
        string binary = q.dequeue();
        cout << binary << " ";
        q.enqueue(binary + "0");
        q.enqueue(binary + "1");
    }
}


// void generateBinaryNumbers(int n)
// {
//     Queue<string> q;
//     q.enqueue("1");
 
//     while (n--) {
//         string s1 = q.first();
//         q.dequeue();
//         cout << s1 << "\n";
//         string s2 = s1; 
//         q.enqueue(s1.append("0"));
//         q.enqueue(s2.append("1"));
//     }
// }

int main() {
    
    generateBinaryNumbers(3);
    cout << endl;
    return 0;
}


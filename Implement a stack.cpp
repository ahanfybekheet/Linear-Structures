#include"Queue.cpp"

using namespace std;
template<class T>
class Stack{
    private:
        Queue<T> baseQ;
    public:
    void push(T value){
        baseQ.enqueue(value);
    }
    T pop(){
        Queue<T> tmpQ;
        T tmp;
        while(!baseQ.isEmpty()){
            if(baseQ.queueSize()==1){
                tmp = baseQ.dequeue();
            }else{
            tmpQ.enqueue(baseQ.dequeue());
            }
        }
        baseQ = tmpQ;
        return tmp;
    }
};
int main(){
    Stack<int> s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout<< s.pop();
    s.push(6);
    s.push(9);
    cout<< s.pop();
    cout<< s.pop();

}
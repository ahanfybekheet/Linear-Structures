#include"Stack.cpp"

using namespace std;
int precedence(char op);
string infixToPostfix(string infix);
int main(){
    cout << infixToPostfix("X^Y/(5*Z)+2");
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
string infixToPostfix(string infix){
    Stack<char> holder;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isdigit(c) || isalpha(c)) {
            postfix += c;
        }
        else if (c == '(') {
            holder.push(c);
        }
        else if (c == ')') {
            while (!holder.isEmpty() && holder.top() != '(') {
                postfix += holder.pop();
            }
            holder.pop(); // pop the left parenthesis
        }
        else { // c is an operator
            while (!holder.isEmpty() && precedence(c) <= precedence(holder.top())) {
                postfix += holder.pop();
            }
            holder.push(c);
        }
    }

    while (!holder.isEmpty()) {
        postfix += holder.top();
        holder.pop();
    }

    return postfix;
}
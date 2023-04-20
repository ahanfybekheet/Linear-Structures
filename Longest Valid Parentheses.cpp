#include"Stack.cpp"


int LongestValidParentheses(string s);

int main(){
    cout << LongestValidParentheses(string("(()"));
    cout << LongestValidParentheses(string(")()())"));
}


int LongestValidParentheses(string s){
    int lvp=0,vp=0;
    Stack<char> holder;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='('){
            holder.push('(');
        }
        else{
            if(holder.isEmpty()){
                if(vp >lvp){
                    lvp = vp;
                }
                vp = 0;
            }else{
                vp += 2;
                holder.pop();
            }
        }
    }
    if(vp >lvp){
        lvp = vp;
    }
    return lvp;
}
#include <iostream>
#include <stack>
using namespace std;

class Stackk{
    private:
    stack <pair<int,int>> st;

    public:
    void push(int val){
        if(st.empty()){
            st.push({val,val});
        }
        else{
            int mini = min(getMin(), val);
            st.push({val,mini});
        }
    }

    void pop(){
        st.pop();
    }

    int top(){
        return st.top().first;
    }

    int getMin(){
        return st.top().second;
    }
};


int main() {
    Stackk s;
    
    
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
    
    return 0;
}
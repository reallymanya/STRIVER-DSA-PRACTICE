#include <iostream>
#include <stack>
using namespace std;

class Stackk{
    private:
    stack <int> st;
    int mini;

    public: 
    void push(int val){
        if(st.empty()){
            mini = val;
            st.push(val);
            return;
        }

        if(val > mini){
            st.push(val);
        }
        else{
             st.push(2 * val - mini);
             mini = val;
        }
    }

    void pop(){
        if(st.empty()) return;

        int x = st.top();
        st.pop();
       
        if(x < mini)
        mini = 2 * mini - x;
    }

    int top(){
        if(st.empty()) return -1;
        
        int val = st.top();
        
        if(mini < val) return val;

        return mini;
    }

    int getMin(){
        return mini;
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
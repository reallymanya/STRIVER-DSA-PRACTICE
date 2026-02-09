vector<int> nextGreaterElement(vector<int> arr){

    int n = arr.size();
    vector<int> ans(n, -1);     
    stack<int> st;            

    for(int i = 0; i < 2*n; i++) {  

        int ind = i % n;        

        while(!st.empty() && arr[st.top()] < arr[ind]) {   
            ans[st.top()] = arr[ind];                     
            st.pop();                                   
        }

        if(i < n)              
            st.push(ind);       
    }

    return ans;
}

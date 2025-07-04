#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> removedup(vector<int> &a, int n){
set<int> st;
for(int i = 0; i<n;i++){
    st.insert(a[i]);
}

int index = 0;
for(auto it : st){
    a[index] = it;
    index++;
}
a.resize(index); // Resize the vector to remove excess elements
return a;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5};
    int n = arr.size();
    
    arr = removedup(arr, n);
    
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
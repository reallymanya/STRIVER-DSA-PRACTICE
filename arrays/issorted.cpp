#include <iostream>
using namespace std;

int isSorted(int n, vector<int> a) {
    // Write your code here.
    for(int i = 1; i<n;i++){
        if(a[i] >= a[i-1]){

        }
        else{
            return false;
        }
      
    }
      return true;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    if (isSorted(arr.size(), arr)) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }
    return 0;
}
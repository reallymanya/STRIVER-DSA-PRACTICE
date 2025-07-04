#include <iostream>
using namespace std;

int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int largest = arr[0];
    for(int i = 0; i<n;i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}


int main(){
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    cout << "Largest Element in Array: " << largestElement(arr, arr.size()) << endl;
    return 0;
}
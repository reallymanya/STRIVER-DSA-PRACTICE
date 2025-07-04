#include <iostream>
using namespace std;

int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    for(int i = 0; i<n;i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}


int main() {
    int n, num;
   
    cin >> n;
    vector<int> arr(n);
    
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the number to search: ";
    cin >> num;

    int index = linearSearch(n, num, arr);
    
    if(index != -1) {
        cout << "Number found at index: " << index << endl;
    } else {
        cout << "Number not found in the array." << endl;
    }

    return 0;
}
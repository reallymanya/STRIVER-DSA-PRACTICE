#include <iostream>
using namespace std;

int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
     int largest = arr[0];
    int slargest = -1;
    for(int i = 0; i<n;i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > slargest && arr[i] != largest){
            slargest = arr[i];
        }
    }

   /* if(slargest == INT_MIN){
        return -1;
    }*/
    return slargest;
}


int main()
{
    vector<int> arr = {7,7,7,7,7,7,7,7,7,7};
    cout << "Second Largest Element in Array: " << findSecondLargest(arr.size(), arr) << endl;
    return 0;
}
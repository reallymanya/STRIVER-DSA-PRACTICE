#include <iostream>
#include <algorithm>
using namespace std;


int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i < high){
            i++;
        }
        while(arr[j] > pivot && j > low){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr,low,high);
        qs(arr,low,pIndex - 1);
        qs(arr,pIndex + 1, high);
    }
}


vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    qs(arr,0,arr.size() - 1);
    return arr;
}

int main(){
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    arr = quickSort(arr);
    
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
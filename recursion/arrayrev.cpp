//1. using extra array , tc O(n), sc O(n)

#include <iostream>
#include <algorithm> // for std::reverse
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void reverse(int arr[], int n){
    int ans[n];
    for(int i = n-1; i>=0; i--){
        ans[n-i-1] = arr[i];
    }
    printArray(ans, n);
}

//two pointer approach , tc O(n), sc O(1)

void reverse2(int arr[], int n){
    int p1 = 0, p2 = n-1;
    while(p1 < p2){
        swap(arr[p1], arr[p2]);
        p1++, p2--;
    }
    printArray(arr, n);
}
// recursive approach , tc O(n), sc O(n)
void reverse3(int arr[], int n, int start, int end){
    if(start < end){
        swap(arr[start], arr[end]);
        reverse3(arr,n,start+1, end-1);
    }
    
}
//one pointer approach
void f(int arr[], int n, int i){
    if(i>=n/2){
        return;
    }
    swap(arr[i], arr[n-i-1]);
    f(arr, n, i+1);
}
//using algorithm
void reverse4(int arr[], int n){
    reverse(arr, arr+n);
    
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //reverse(arr, n);
    //reverse2(arr,n);

    //reverse3(arr, n, 0, n-1);
  // printArray(arr, n);

   // reverse4(arr, n);

   f(arr, n, 0);
    printArray(arr, n);
     return 0;
    

}
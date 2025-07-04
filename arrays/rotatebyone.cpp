//left rotating an array by one place

#include <iostream>
using namespace std;


void solve(int arr[], int n){
    int temp = arr[0];
    for(int i = 1; i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;

    for(int i = 0; i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
int arr[5];
for(int i = 0; i<5;i++){
    cin >> arr[i];
}
solve(arr, 5);
return 0;
}
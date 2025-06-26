#include <iostream>
using namespace std;

void inssort(int arr[], int n){
    for(int i = 1; i<n;i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
            cout << "runs";
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }
    inssort(arr,n);
    for(int i = 0; i<n;i++){
        cout << arr[i]<<" ";
}
}
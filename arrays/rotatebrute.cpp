#include <iostream>
using namespace std;

void leftrotate(int arr[], int n, int k){
    k = k % n;
    int temp[k];

    for(int i = 0; i<k;i++){
        temp[i] = arr[i];
    }
     
    for(int i = k; i<n;i++){
        arr[i-k] = arr[i];
    }

    for(int i = n-k;i<n;i++){
        arr[i] = temp[i-(n-k)];
    }

}



int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
}

int d;
cin >> d;

leftrotate(arr, n, d);
for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}


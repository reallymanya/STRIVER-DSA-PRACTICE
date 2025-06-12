#include <iostream>
using namespace std;

/*int f(int n, int arr[], int size){
    int cnt = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == n){
            cnt++;
        }
    }
    return cnt;
}

int main() {
   int arr[6] = {1, 0, 1, 1, 0, 1};
   int n = 0;
    int count = f(0, arr,6);
    cout << count;

}*/

// Count the number of occurrences of a number in an array
//using HASHING

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }

    //precompute
    int hashh[13] = {0};
    for(int i = 0; i<n;i++){
        hashh[arr[i]] += 1;
    }
    int num;
    cin >> num;
    while(num--){
        int x;
        cin >> x;
        //fetch
        cout << hashh[x] << endl;
    }
    /*for(int i = 0; i<13;i++){
        if(hashh[i] != 0){
            cout << i << " " << hashh[i] << endl;
        }
    }*/
}
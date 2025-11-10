#include <iostream>
using namespace std;

int* printDivisors(int n, int &size){
// Write your code here
int* arr = new int[10000];
size = 0;
for(int i = 1; i*i <=n;i++){
    if(n%i == 0){
    arr[size++] = i;
    
    if(i != (n/i)){
    arr[size++] = n/i;
    }
    }
}
sort(arr,arr+size);
    return arr;
}

int main() {
    int n = 36;
    int size;       

    int* divisors = printDivisors(n, size);

    for (int i = 0; i < size; i++) {
        cout << divisors[i] << " ";
    }

    return 0;
}
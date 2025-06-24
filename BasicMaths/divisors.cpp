// brute force approach

#include <iostream>
using namespace std;

int* divis(int n , int &size){
int* divisors = new int[n];
int count = 0;
for(int i = 1 ; i<=n;i++){
    if(n%i == 0){
        divisors[count++] = i;
    }
}
size = count;
return divisors;
}
int main(){
int number = 12;
int size;
int *divisors = divis(number,size);
cout << "divisors of number: "<<endl;
for (int i = 0; i < size; i++) {
        cout << divisors[i] << " ";
    }
     delete[] divisors;

    return 0;
}

//tc: O(n)
//sc: O(n)
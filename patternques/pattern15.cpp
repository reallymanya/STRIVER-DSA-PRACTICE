#include <iostream>
using namespace std;

void print15(int n){
    for(int i = 0; i<n;i++){
        for(char ch = 'A'; ch <= 'A'+(n-i-1); ch++){
            cout << ch <<  " ";
        }
        cout << endl;
    }
}

void nLetterTriangle(int n) {
    // Write your code here.
    for(int i = n;i>=1;i--){
        for(char ch = 'A'; ch < 'A' + i; ch++ ){
            cout << ch << " ";
        }
        cout << endl;
        
    }
}

int main() {
    int n;
    cin >> n;
    print15(n);
    nLetterTriangle(n);
    return 0;
}
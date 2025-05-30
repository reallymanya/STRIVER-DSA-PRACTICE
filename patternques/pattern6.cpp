#include <iostream>
using namespace std;

void nNumberTriangle(int n) {
    // Write your code here.
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n-i+1;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    nNumberTriangle(n);
    return 0;
}
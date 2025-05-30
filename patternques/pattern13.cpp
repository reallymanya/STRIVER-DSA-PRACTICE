#include <iostream>
using namespace std;


void nNumberTriangle(int n) {
    // Write your code here.
    int num = 1;
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=i;j++){
            cout << num << " ";
            num++;
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
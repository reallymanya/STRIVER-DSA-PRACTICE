#include <iostream>
using namespace std;

void nLetterTriangle(int n) {
    // Write your code here.
    for(int i = 0; i<n;i++){
        for(char ch = 'A'; ch <= 'A'+i; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    nLetterTriangle(n);
    return 0;
}
#include <iostream>
using namespace std;

void alphaRamp(int n) {
    // Write your code here.
    for(int i = 0; i<n;i++){
        char ch = 'A' + i;
        for(int j = 0; j<=i; j++){
            cout << ch<< " ";
           
        } 
        cout << endl;
        
    }
}
int main() {
    int n;
    cin >> n;
    alphaRamp(n);
    return 0;
}
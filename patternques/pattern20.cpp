#include <iostream>
using namespace std;

void symmetry(int n) {
    // Write your code here.
    for(int i =1; i<=2*n-1;i++){
        //stars
        int stars = i;
        if(i > n) stars = 2*n-i;

        for(int j = 1; j<=stars;j++){
            cout << "* ";
        }

        //spaces
        int spaces = 2*n - 2;
       
        for(int j = 1; j<=spaces; j++ ){
            cout << " ";
        }
        //stars
        for(int j = 1; j<=stars;j++){
            cout << "* ";
        }
        cout << endl;
        if(i<n) spaces -= 2;
        else spaces += 2;

    }
}
int main() {
    int n;
    cin >> n;
    symmetry(n);
    return 0;
}
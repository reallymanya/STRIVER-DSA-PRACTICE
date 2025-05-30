#include <iostream>
using namespace std;

void pattern19(int n){
for(int i = 0; i<n;i++){
    //stars
    for(int j = 0; j<n-i;j++){
        cout << "*";
    }
    //space
    int space = 2*i;
    for(int j=0; j<space;j++){
        cout << " ";
    }
    //stars
    for(int j = 0; j<n-i;j++){
        cout << "*";
    }
    cout << endl;
}

for(int i = 0;i<n;i++){
    //star
    for(int j =0; j<=i;j++){
        cout << "*";
    }
    //space
    int space = 2*(n-i-1);
    for(int j = 0; j<space;j++){
        cout << " ";
    }
    //star
    for(int j = 0; j<=i;j++){
        cout << "*";
    }
    cout << endl;
}
}

int main() {
    int n;
    cin >> n;
    pattern19(n);
    return 0;
}

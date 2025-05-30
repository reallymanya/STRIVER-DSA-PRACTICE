#include <iostream>
using namespace std;


void seeding(int n) {
	// Write your code here.
	for(int i = 1; i<=n;i++){
		for(int j = 1; j<=n-i+1;j++){
			cout << "* ";
		}
		cout << endl;
	}
}

int main() {
    int n;
    cin >> n;
    seeding(n);
    return 0;
}
#include <iostream>
#include <cmath> // for log10
using namespace std;

 //TC:   O(log10(n)) 
 // if the number of iterations depends on division
 // that is when logarithmic will come in time complexity

int count(int n){
   int cnt = 0;
   while(n>0){

        int digit = n%10;
        cnt++;
        n = n/10; //no of times it is div by 10 is the count of digits

   }
    return cnt;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = count(n);
    cout << "Number of digits in " << n << " is: " << result << endl;

    return 0;
}


 //LOGARITHMIC APPROACH
 //int  cnt = (int)(log10(n) + 1);
//tc = o(1);
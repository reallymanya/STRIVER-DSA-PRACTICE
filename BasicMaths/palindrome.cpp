#include <iostream>
using namespace std;

 bool isPalindrome(int x) {

        int rev = 0;
        int num = x;

        while(num>0){
            int dig = num%10;

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && dig > 7)) {
                return false; 
            }

            rev = (rev*10) + dig;
            num = num/10;
        }
        return(rev == x);
    }

    int main(){
        int n;
        cin >> n;
        cout << isPalindrome(n);
    }
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

// hashing 
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    map<int,int> mpp;
    for(int i = 0; i<n;i++){
        int a = book[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end()){
            return "YES";
        }
        mpp[a] = i;
    }
    return "NO";
}
//tc = O(n*logn)
//sc = O(n);

//2-pointer
string readd(int n, vector<int> book, int target){
    int left = 0, right = n-1;
    sort(book.begin(),book.end());
    while(left < right){
        int sum = book[left] + book[right];
        if(sum == target){
            return "YES";
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    return "NO";
}

//tc = O(n) + O(nlogn)(for sorting)
//sc = O(1) (O(n) if we consider distortion)
int main() {
    int n, target;
    cin >> n;
    vector<int> book(n);
    for (int i = 0; i < n; ++i) {
        cin >> book[i];
    }
    cin >> target;
    string result = readd(n, book, target);
    cout << result << endl;
    return 0;
}

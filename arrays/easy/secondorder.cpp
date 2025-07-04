#include <iostream>
using namespace std;

int secondlargest(vector<int> &a, int n){
    if(n<2){
        return -1;
    }
    int largest = INT_MIN;
    int slargest = INT_MIN;
    for(int i = 0; i<n;i++){
        if(a[i] > largest){
            slargest = largest;
            largest = a[i];
        }
        else if (a[i] > slargest && a[i] != largest){
            slargest = a[i];
        }
        
    }
    return slargest;
}

int secondsmallest(vector<int> &a, int n){
    if(n<2){
        return -1;
    }
    int smallest = INT_MAX;
    int ssmallest = INT_MAX;
    for(int i = 0; i<n;i++){
        if(a[i] < smallest){
            ssmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] <  ssmallest && a[i] != smallest){
            ssmallest = a[i];
        }
    }
    return ssmallest;
}






vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
   int slargest = secondlargest(a,n);
   int ssmallest = secondsmallest(a,n);
   return {slargest, ssmallest};
}


int main() {
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    vector<int> result = getSecondOrderElements(arr.size(), arr);
    cout << "Second Largest Element: " << result[0] << endl;
    cout << "Second Smallest Element: " << result[1] << endl;
    return 0;
}
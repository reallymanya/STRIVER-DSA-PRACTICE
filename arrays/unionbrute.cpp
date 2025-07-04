#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> unionBruteForce(vector<int>& arr1, vector<int>& arr2) {
    set<int> set;

    for(int i = 0; i<arr1.size();i++){
        set.insert(arr1[i]);
    }

    for(int i = 0; i<arr2.size();i++){
        set.insert(arr2[i]);
    }

    vector<int> unionarr;
    for(auto it : set){
        unionarr.push_back(it);
    }
    return unionarr;

}

int main(){
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {1, 2, 3, 4,4,5};
    vector<int> result = unionBruteForce(arr1, arr2);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}
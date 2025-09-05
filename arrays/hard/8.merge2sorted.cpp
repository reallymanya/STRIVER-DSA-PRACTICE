// gap method
//tc = O(log2(m+n) * O(m + n)
//sc = O(1)

//2 pointer in L.C 88

//brute in notes -> using third array
#include <iostream>
#include<vector>
using namespace std;

void swapp(vector<long long> &a, vector<long long> &b,int m, int n){
	if(a[m] > b[n]){
		swap(a[m],b[n]);
	}
}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int m = a.size();
	int n = b.size();
	int length = m + n;
	int gap = (length/2) + (length % 2);

	while(gap > 0){
		int left = 0;
		int right = left + gap;
		while(right < length){
			if(left < m && right >= m){
				swapp(a,b,left,right - m);
			}
			else if (left >= m){
				swapp(b,b,left-m,right-m);
			}
			else{
				swapp(a,a,left,right);
			}
			left++, right++;
			
		}
		if(gap == 1) break;
			gap = (gap/2) + (gap%2);
	}
	
}

int main(){
vector<long long> a = {1, 4, 7, 8, 10};
vector<long long> b = {2, 3, 9};
mergeTwoSortedArraysWithoutExtraSpace(a, b);

cout << "Array a: ";
for (auto num : a) cout << num << " ";
cout << endl;

cout << "Array b: ";
for (auto num : b) cout << num << " ";
cout << endl;
}
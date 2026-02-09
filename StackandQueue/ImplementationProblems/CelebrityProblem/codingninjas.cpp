#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	 int i = 0;
	 int j = n-1;

	 while(i<j){
		 if(knows(i,j))
		 i++;
		else
		 j--;
		 
	 }

	 int candidate = i;
	 for(int k = 0; k<n;k++){
		 if(k == candidate)continue;

		if(knows(candidate, k) || !knows(k, candidate)) {
            return -1;
        }

	 }
	  return candidate;
}
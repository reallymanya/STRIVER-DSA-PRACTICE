#include <iostream>
#include <vector>
using namespace std;

int firstocc(vector<int>& arr, int n, int key){
     int s = 0, e = n-1;
    
    int ans = -1;
     while( s <= e){
        int mid = s + (e - s)/2;
        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }

       
        else if(key > arr[mid]){
            s = mid + 1;
        }
        else if(key< arr[mid]){ 
            e = mid - 1;
        }
     }
     return ans;
}


int lastocc(vector<int>& arr, int n, int key){
     int s = 0, e = n-1;
    int ans = -1;
     while( s <= e){
          int mid = s + (e-s)/2;
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }

        else if(key > arr[mid]){
            s = mid + 1;
        }
        else if(key< arr[mid]){ 
            e = mid - 1;
        }
     }
     return ans;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
   int f = firstocc(arr,n,k);
   if(f == -1) return {-1,-1};
    int l = lastocc(arr,n,k);
    return {f,l};
}

int count(vector<int>& arr, int n, int x) {
pair<int,int> ans = firstAndLastPosition(arr,n,x);
if(ans.first == -1) return 0;
return ans.second - ans.first + 1;
	
}

int main(){
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, x = 8;
    int ans = count(arr, n, x);
    cout << "The number of occurrences is: "
         << ans << "\n";
    return 0;
}
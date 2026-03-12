class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n = s1.size();
        int m = s2.size();
        
        int minlen = INT_MAX;
        int start = -1;
        
        for(int i = 0; i<n;i++){
            if(s1[i] == s2[0]){
                int j = i;
                int k = 0;
                
                while(j < n && k < m){
                    if(s1[j] == s2[k]) k++;
                    j++;
                }
                
                if(k == m){
                    int end = j - 1;
                    k = m - 1;
                    
                    while(end >= i){
                        if(s1[end] == s2[k]) k--;
                        if(k < 0) break;
                        end --;
                    }
                    
                    int len = j - end;
                    
                    if(len < minlen){
                        minlen = len;
                        start = end;
                    }
                }
            }
        }
        return start == -1 ? "" : s1.substr(start,minlen);
    }
};

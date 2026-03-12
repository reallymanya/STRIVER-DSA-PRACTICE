string minSubstring(string &a, string &b)
{
    // Write your code here.
    int minLength = 1e9;

    int sIndex = -1;

    for(int i = 0; i<a.size(); i++){
        vector<int> hash(256,0);
        int cnt = 0;

        for(int j = 0; j<b.size();j++){
            hash[b[j]]++;
        }

        for(int j = i; j<a.size();j++){
            if(hash[a[j]] > 0) cnt++;
            hash[a[j]]--;

            if(cnt == b.size())
            {
                if((j - i + 1) < minLength){
                    minLength = j - i + 1;
                    sIndex = i;
                    break;
                }
            }
        }
    }
    if(sIndex == -1) return "";
    return a.substr(sIndex,minLength);
}
class Solution {
public:

    int solve(string s, int i , long num, int sign){

        if( i >= s.size() || !isdigit(s[i]))
        return (int)(sign * num);

        int digit = s[i] - '0';

        if(num > INT_MAX/10 || num == INT_MAX/10 && digit > 7)
        return sign == -1 ? INT_MIN : INT_MAX;

        num = num * 10 + digit;

      return solve(s,i+1,num,sign);
    }

    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1;

        while(i < n && s[i] == ' ') i++;

        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        }

        return solve(s,i,0,sign);
    }
};
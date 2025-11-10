int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend ==  INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;

        bool isPositive = true;

        if(dividend >= 0 && divisor < 0)
        isPositive = false;
       else if(dividend < 0 && divisor > 0)
        isPositive = false;

        long long n = dividend;
        long long d = divisor;

        n = abs(n);
        d = abs(d);
        long quotient = 0;

        while(n>=d){
            int cnt = 0;
            while(n >= (d<<(cnt+1))){
                cnt++;
            }
            quotient += 1 << cnt;
            n -= d * (1 << cnt);
        }

        if (quotient > INT_MAX)
    return isPositive ? INT_MAX : INT_MIN;

        return isPositive ? quotient : -1*quotient;
    }
/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/divide-two-integers
@Language: C++
@Datetime: 16-09-21 05:38
*/

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        
        long long m = abs((long long)dividend);
        long long n = abs((long long)divisor);
        long long res = 0;
        
        int sign = ((dividend>0)^(divisor>0)) ? -1 : 1;
        if(n == 1) return (sign>0) ? m : -m;
        
        // 100/51=1 ; 100/50 = 2;
        while(m>=n)
        {
            long long t = n; // Get the value of n, we fixed n and change m;
            long long p = 1; // For the tracking of the result;
            while(m >=(t<<1))
            {
                p = p<<1;
                t = t<<1;
            }
            res += p; 
            m -= t;
        }
        
        
        return sign>0 ? res : -res;
    }
};
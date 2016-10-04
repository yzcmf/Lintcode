/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/reverse-integer
@Language: C++
@Datetime: 16-09-14 06:11
*/

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        
        long res = 0;
        int sign=1;
        
        if(n<0) 
        {
         n=-n;
         sign = -1;
        }
        
        while(n)
        {
            res = res*10 + n%10;
            n /=10;
        }
        
        if(res>INT_MAX || res<INT_MIN) return 0;
        else
        {
        return res*sign;
        }
    }
};
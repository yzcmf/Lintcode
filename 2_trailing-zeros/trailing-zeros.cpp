/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/trailing-zeros
@Language: C++
@Datetime: 16-09-14 05:30
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        
        long long count =0;
        while(n)
        {
            n =n/5;
            count += n;
        }
        
        return count;
    }
};

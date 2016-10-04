/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/fibonacci
@Language: C++
@Datetime: 16-09-13 05:44
*/

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if(n<0) return -1;
        if(n==1) return 0;
        if(n==2) return 1;
        
        vector<int>dp(n);
        dp[1] = 0;
        dp[2] = 1;
        for(int i=3;i<=n;i++)
        {
          dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

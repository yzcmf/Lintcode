/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/climbing-stairs
@Language: C++
@Datetime: 16-09-13 07:30
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        
        vector<int>dp(n);
        dp[0]=1;
        dp[1]=2;
         
        for(int i=2;i<n;i++)
        {
         dp[i] = dp[i-1]+dp[i-2];
        }
        
        return dp[n-1];
    }
};

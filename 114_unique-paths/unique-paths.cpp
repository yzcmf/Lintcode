/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/unique-paths
@Language: C++
@Datetime: 16-09-16 09:29
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        
        // if(m<1 || n<1) return 0;
        // vector<vector<int>>dp(m,vector<int>(n));
        
        // dp[0][0] = 1;
        
        // for (int i = 1; i < n; i ++)
        // {
        //  dp[0][i] = 1;
        // }

        // for (int j = 1; j < m; j ++)
        // {
        // dp[j][0] = 1;
        // }
    
        // for(int i=1;i<m;i++)
        // {
        //   for(int j=1;j<n;j++)
        //   {
        //     dp[i][j] = dp[i-1][j]+dp[i][j-1];
        //   }
        // }
        // return dp[m-1][n-1];
        
        if(m<1 || n<1) return 0;
        vector<int>dp(n,1);
        
        for(int i=1;i<m;i++)
        {
          for(int j=1;j<n;j++)
          {
            dp[j] += dp[j-1];
          }
        }
        
        return dp[n-1];
    }
};

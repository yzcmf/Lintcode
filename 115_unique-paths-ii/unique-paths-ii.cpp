/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/unique-paths-ii
@Language: C++
@Datetime: 16-09-16 10:53
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // write your code here
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m==0 || n==0|| obstacleGrid[0][0]==1) return 0;
        vector<int>dp(n,1);
        
        for(int j=1;j<n;j++)
            {
                if(obstacleGrid[0][j] == 1)
                {
                    dp[j] = 0;
                    continue;
                }
                dp[j] = dp[j-1];
        }
            
        for(int i=1;i<m;i++)
        {
            dp[0] = obstacleGrid[i][0]==1 ? 0 : dp[0];//check the first row;
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[j] = 0;
                    continue;
                }
                dp[j] += dp[j-1];
            }
        }
        
        return dp[n-1];
    }
};
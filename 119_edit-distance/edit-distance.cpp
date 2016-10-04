/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/edit-distance
@Language: C++
@Datetime: 16-09-21 06:44
*/

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int m=word1.size(), n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int j=1;j<=n;j++)
        dp[0][j]=j;
        
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=i;
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1]) dp[i][j]++;
                dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i][j]);
            }
        }
        
        return dp[m][n];
    }
};

//Good reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-edit-distance.html
/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/longest-common-subsequence
@Language: C++
@Datetime: 16-09-23 02:32
*/

/*
-- the common subsequence can be distinct;
DP[i][j]表示字符串A的前i位和字符串B的前j位的最长公共子序列数目;
case1: A[i] == B[j] : DP[i][j] = DP[i-1][j-1] + 1;
case2: A[i] != B[j] : DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
*/
class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int m = A.size();
        int n = B.size();
        if(m <= 0 || n <= 0) return 0;
        vector<vector<int>>DP(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
              if(A[i-1] == B[j-1]) 
                 DP[i][j] = DP[i-1][j-1] + 1;
              else
                 DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            }
        }
        return DP[m][n];
    }
};

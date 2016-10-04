/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/maximal-square
@Language: C++
@Datetime: 16-09-24 04:54
*/

//---DP:O(n^2);
class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>>&matrix) {
        // write your code here
        if(matrix.empty()||matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>>DP(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0] == 1)
            {
            DP[i][0]=1;
            res = 1;
            }
        }
        
        for(int j=0;j<n;j++)
        {
            if(matrix[0][j] == 1)
            {
            DP[0][j]=1;
            res = 1;
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j] == 1)
                DP[i][j] = min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1]))+1;
                res = max(res,DP[i][j]);
            }
        }
    
        return res*res;
    }
};

//Good reference:
//http://yucoding.blogspot.com/2015/10/leetcode-question-maximal-square.html
//http://www.cnblogs.com/easonliu/p/4548769.html
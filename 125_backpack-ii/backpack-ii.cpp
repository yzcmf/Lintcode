/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/backpack-ii
@Language: C++
@Datetime: 16-09-20 05:34
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        
        if(A.empty()) return 0;
        int len = A.size();
        int DP[m+1];
        
        for(int j=0;j<=m;j++)
        DP[j] = 0;
        
        for(int i=0;i<len;i++)
        {
            for(int j=m;j>=1;j--)
            {
                if(A[i]<=j)
                {
                    DP[j] = max(DP[j],V[i]+DP[j-A[i]]);
                }
            }
        }
        
        return DP[m];
    }
};
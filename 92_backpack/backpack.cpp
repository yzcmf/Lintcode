/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/backpack
@Language: C++
@Datetime: 16-09-20 05:20
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        // if(A.empty() || m==0) return 0;
        // int len = A.size();
        // vector<int> dp(len+1,0);
        
        // for(int i=1;i<len+1;i++) 
        // {
        //     if(A[i] + dp[i-1] <=m)
        //     dp[i] = dp[i-1] + A[i];
        //     else
        //     {
        //     dp[i] = dp[i-1];
        //     }
        // }
        // return dp[len];
        // We could pick up randomly; -- Can't use subarray travserval
        
        // -- DP solution : Using the DP[i] : (0,i-1) most value which can fill the backpack;
        
        if(A.empty()||m==0) return 0;
        int len = A.size();
        int DP[m+1];
        
        for(int j=0;j<=m;j++)
        DP[j] = 0;
        
        // For each item, find the j can hold it;
        // Update DP from DP[m] to DP[1];
        // When no j is great than A[i],the j<A[i] has finished the updatig processing;
        for(int i=0;i<len;i++)
        {
            for(int j=m;j>=1;j--)
            {
                if(A[i]<=j)
                {
                    DP[j] = max(DP[j-A[i]]+A[i],DP[j]);
                }
            }
        }
        
        return DP[m];
    }
};
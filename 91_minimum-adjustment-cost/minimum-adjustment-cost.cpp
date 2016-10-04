/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/minimum-adjustment-cost
@Language: C++
@Datetime: 16-09-30 00:55
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int>A, int target) {
        // write your code here
        //DP[i][j]: the cost to adjust the A[i] to become j;
        // j is from 0 -100; according to the problem;
        //Equation: DP[i][j]=min(DP[i][j],DP[i-1][k]+abs(A[i]-j))
        //k:A[i-1] to the adjustment k and 
        //the range is:(max(0,j-target),min(100,j+target))
        //|k|<=100 && |j-k|<=target and thus the range comes out;
        
        if(A.empty()) return 0;
        vector<vector<int>>DP(A.size(),vector<int>(101,INT_MAX));
        
        for(int i=0;i<=100;i++)
        {
        DP[0][i]=abs(A[0]-i);
        }
        
        for(int i=1;i<A.size();i++)
        {
            for(int j=0;j<=100;j++)
            {
                for(int k=max(0,j-target);k<=min(100,j+target);k++)
                  DP[i][j]=min(DP[i][j],DP[i-1][k]+abs(A[i]-j));
            }
            
        }
        
        int res=INT_MAX;
        for(int i=0;i<=100;i++)
        {
        res=min(res,DP[A.size()-1][i]);
        }
        
        // The last round we have gotten 101 outcomes for the DP[A.size()-1][j];
        // Thus, we should also find the min cost towards the 101 status;
        
        return res;
    }
};
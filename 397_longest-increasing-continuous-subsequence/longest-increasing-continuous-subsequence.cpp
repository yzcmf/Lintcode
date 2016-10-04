/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/longest-increasing-continuous-subsequence
@Language: C++
@Datetime: 16-09-15 01:02
*/

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int cnt = 1;
        int max_res=INT_MIN;
        
        if(A.empty()) return 0;
        if(A.size()==1) return 1;
        
        for(int i=1;i<A.size();i++)
        {
            if(A[i]>=A[i-1]) 
            {
                cnt++;
                max_res = max(max_res,cnt);
            }
            else
            {
                cnt = 1;
            }
        }
        
        for(int i=A.size()-2;i>=0;i--)
        {
            if(A[i]>=A[i+1]) 
            {
                cnt++;
                max_res = max(max_res,cnt);
            }
            else
            {
                cnt = 1;
            }
        }
        
        return max_res;
    }
};
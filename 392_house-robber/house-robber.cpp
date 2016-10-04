/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/house-robber
@Language: C++
@Datetime: 16-09-22 21:58
*/

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        //Method one -- Common Solution
        
        // long long sum1 = 0;
        // long long sum2 = 0;
        
        // for(int i=0;i<A.size();i++)
        // {
        //     if(i % 2 == 0)
        //     {
        //     sum1 += A[i];
        //     sum1 = max(sum1,sum2);
        //     }
        //     else
        //     {
        //     sum2 += A[i];
        //     sum2 = max(sum1,sum2);
        //     }
        // }
        
        // return max(sum1,sum2);
        
         //Method two -- DP Solution
         
        if (A.size() <= 1) return A.empty() ? 0 : A[0];
        vector<long long> dp{A[0], max(A[0], A[1])};// dp{} like: array={a1,a2};
        for (int i = 2; i < A.size(); ++i) {
            dp.push_back(max(dp[i - 2] + A[i], dp[i - 1]));
        }
        return dp.back();
    }
};
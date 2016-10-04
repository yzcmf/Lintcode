/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/maximum-subarray
@Language: C++
@Datetime: 16-09-15 02:29
*/

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */

// -- Normal thinking;     
    // int maxSubArray(vector<int> nums) {
    //     // write your code here
    //     int max_sum = INT_MIN;
    //     int cur_sum = 0;
        
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         cur_sum += nums[i];
    //         max_sum=max(max_sum,cur_sum);
    //         if(cur_sum<0)
    //         {
    //           cur_sum = 0;  
    //         }
    //     }
        
    //     return max_sum;
    // }

// -- DP solution
    int maxSubArray(vector<int>A) {
        // write your code here
        int n = A.size();
        if(n<=0) return 0;
        int max_sum = A[0], cur_sum = A[0];
        for(int i=1; i<n; i++) {
            cur_sum = cur_sum<=0 ? A[i] : A[i]+cur_sum;
            max_sum = max(max_sum,cur_sum);
        }
        return max_sum;
    }
};

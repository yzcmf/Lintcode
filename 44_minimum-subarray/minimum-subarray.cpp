/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/minimum-subarray
@Language: C++
@Datetime: 16-09-15 03:38
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
//Normal method;     
    // int minSubArray(vector<int> nums) {
    //     // write your code here
        
    //     int min_sum = INT_MAX;
    //     int cur_sum = 0;
        
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         cur_sum += nums[i];
    //         min_sum = min(min_sum,cur_sum);
    //         if(cur_sum>0)
    //         cur_sum = 0;
    //     }
        
    //     return min_sum;
    // }
    
//DP method;     
    int minSubArray(vector<int> nums) {
        // write your code here
        
        int min_sum = nums[0];
        int cur_sum = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
          cur_sum = (cur_sum >0) ? nums[i] : (cur_sum+nums[i]);
          min_sum = min(min_sum,cur_sum);
        }
        
        return min_sum;
    }    
};

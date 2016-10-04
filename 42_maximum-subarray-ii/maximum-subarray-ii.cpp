/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/maximum-subarray-ii
@Language: C++
@Datetime: 16-09-25 04:28
*/

//Common Solution;
//--Time:O(n);
//--Space:O(n); 
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        vector<int>max_LR(n),max_RL(n);
        
        int max_LR_sum = INT_MIN,LR_sum=0;
        for(int i=0;i<n;i++)
        {
            LR_sum += nums[i];
            max_LR_sum = max(max_LR_sum,LR_sum);
            max_LR[i] = max_LR_sum;
            if(LR_sum<0) LR_sum = 0;
        }
        
        int max_RL_sum = INT_MIN,RL_sum=0;
        for(int i=n-1;i>=0;i--)
        {
            RL_sum += nums[i];
            max_RL_sum = max(max_RL_sum,RL_sum);
            max_RL[i] = max_RL_sum;
            if(RL_sum<0) RL_sum = 0;
        }
        
        int max_sum = INT_MIN;
        for(int i=0;i<n-1;i++)
        {
           max_sum = max(max_sum,max_LR[i]+max_RL[i+1]);
        }
        
        return max_sum;
    }
};

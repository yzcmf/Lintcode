/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/wiggle-sort
@Language: C++
@Datetime: 16-10-01 04:19
*/

class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        int flag = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] * flag  < nums[i-1] * flag)
            swap (nums[i],nums[i-1]);
            
            flag = -flag;
        }
        
        return;
    }
};
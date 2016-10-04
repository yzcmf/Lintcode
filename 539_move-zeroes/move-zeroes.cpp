/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/move-zeroes
@Language: C++
@Datetime: 16-09-15 03:49
*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        int k=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
             nums[k++] = nums[i];
        }
        
        for(int i=k;i<nums.size();i++)
        {
          nums[i] = 0;  
        }
    }
};
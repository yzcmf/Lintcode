/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/partition-array-by-odd-and-even
@Language: C++
@Datetime: 16-09-15 04:52
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
//Two pointers;

    void partitionArray(vector<int> &nums) {
        // write your code here
        
        int left = 0,right = nums.size()-1;
        
        while(left<right)
        {
            if(nums[left] % 2 != 0) left++;
            else if(nums[right] % 2 == 0) right--;
            else
            {
             swap(nums[left],nums[right]);
            }
        }
        
    }
};
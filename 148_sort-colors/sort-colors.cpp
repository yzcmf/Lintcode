/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/sort-colors
@Language: C++
@Datetime: 16-09-30 07:32
*/

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        if(nums.empty()) return;
        int left = 0;
        int right = nums.size()-1;
        int i=0;
        
        while(i<=right)
        {
            if(nums[i] == 0)
            swap(nums[i++],nums[left++]);
            else if(nums[i] == 1)
            {
            i++;
            }
            else if(nums[i] == 2)
            swap(nums[i],nums[right--]);
        }
        
        return;
    }
};
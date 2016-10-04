/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array
@Language: C++
@Datetime: 16-09-15 22:19
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        
        int len = nums.size();
        if(len<=1) return len;
        int k=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1])
            len--;
            else
            {
            nums[k++] = nums[i];
            }
        }
        return len;
    }
};
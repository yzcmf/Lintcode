/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/majority-number
@Language: C++
@Datetime: 16-09-15 01:25
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int count1=1;
        int Idx=0;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[Idx]==nums[i]) 
            count1++;
            else
            {
             count1--;
            }
            if(count1 == 0)
            {
                Idx = i;
                count1 =1;
            }
        }
        
        return nums[Idx];
    }
};

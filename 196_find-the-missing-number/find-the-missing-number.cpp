/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/find-the-missing-number
@Language: C++
@Datetime: 16-09-22 00:00
*/

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        // Note: 1.The arrry is not sorted; 2.We can't use the map;
        
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum1 += nums[i];
            sum2 += i;
        }
        
        if(sum2 == sum1) return nums.size();
        return sum2+nums.size() - sum1;
    }
};
/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/majority-number-ii
@Language: C++
@Datetime: 16-09-24 03:43
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
         int num1 = 0, num2 = 0;
         int ret1 = 0, ret2 = 0;
         
         for (int i = 0; i < nums.size(); i++) {
             if (num1 != 0 && ret1 == nums[i]) {
                 num1++;
             } else if (num2 != 0 && ret2 == nums[i]) {
                 num2++;
             } else if (num1 != 0 && num2 != 0) {
                 num1--; 
                 num2--;
             } else if (num1 == 0) {
                 num1 = 1;
                 ret1 = nums[i];
             } else {
                 num2 = 1;
                 ret2 = nums[i];
             }
         }
         
         int count1 = 0, count2 = 0;
         
         for (int i=0; i<nums.size(); i++) {
             if (ret1 == nums[i]) {
                 count1++;
             } else if (ret2 == nums[i]) {
                 count2++;
             }
         }
        
         if (count1 > count2) {
             return ret1;
         } else {
             return ret2;
         }
    }
};

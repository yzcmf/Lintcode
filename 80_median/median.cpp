/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/median
@Language: C++
@Datetime: 16-09-15 00:28
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        if (nums.empty()) return 0;

        int len = nums.size();
        return helper(nums, 0, len - 1, (len + 1) / 2);
    }

private:
    int helper(vector<int> &nums, int l, int u, int size) {
       int i=l;
       for(int j=l+1;j<=u;j++)
       {
           if(nums[j]<nums[l])
           {
               i++;
               swap(nums[i],nums[j]);
           }
       }
       
       swap(nums[l],nums[i]);
       //Note: nums[i] is the pivot
       
       if(i+1-l == size) return nums[i];
       if(i+1-l < size) return helper(nums,i+1,u,size-(i+1-l));
       if(i+1-l>size) return helper(nums,l,i-1,size);
    }
};




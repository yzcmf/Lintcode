/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 16-09-21 08:08
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        if (nums.empty()) return -1;
        int start=0,end=nums.size()-1;

        //Search until there are two elements left;
        //Can only compare with the end to overcome the no-rotated case;
        while(start+1<end)
        {
            int mid = (start+end)/2;
            if(nums[mid]>nums[end])
            start = mid;
            else if(nums[mid]<nums[end])
            end = mid;
            else
            end--;
        }
        
       if (nums[start] < nums[end]) {
            return nums[start];
        } else {
            return nums[end];
        }
        
    }
};
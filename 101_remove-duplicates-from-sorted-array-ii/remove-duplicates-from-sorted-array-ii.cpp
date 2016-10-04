/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array-ii
@Language: C++
@Datetime: 16-09-15 22:47
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        //Method one -- common;
        
        // int count = 1;
        // int k=1;
        // int len = nums.size();
        // if(len<=2) return len;
        
        // for(int i=1;i<len;i++)
        // {
        //     if(nums[i] != nums[i-1]) count=1; // Unique number;
        //     else count++; // The number of duplicate numbers;
        //     if(count < 3) 
        //     {
        //       nums[k++] = nums[i];
        //     }
        // }
        
        // return k;
        
        //Commone two -- smart(using the nums[i] == nums[i-2]);
        
        int k=2;
        int len = nums.size();
        if(len<=2) return len;
        
        for(int i=2;i<len;i++)
        {
            if(nums[i] > nums[k-2])
            nums[k++] = nums[i];
        }
        
        return k;
    }
};
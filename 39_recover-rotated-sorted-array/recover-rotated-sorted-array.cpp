/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/recover-rotated-sorted-array
@Language: C++
@Datetime: 16-09-15 22:11
*/

class Solution {
public:

// --O(n) space;

    // void recoverRotatedSortedArray(vector<int> &nums) {
    //     // write your code here
        
    //     vector<int> res;
        
    //     if(nums.size() <= 1) return ;
        
    //     int pivot = nums.size(); 
        
    //     for(int i=1;i<nums.size();i++)
    //     {
    //         if(nums[i]<nums[i-1])
    //         {
    //             pivot = i;
    //             break;
    //         }
    //     }
        
    //     for(int i=pivot;i<nums.size();i++)
    //     {
    //       res.push_back(nums[i]);
    //     }
        
    //     for(int i=0;i<pivot;i++)
    //     {
    //       res.push_back(nums[i]);
    //     }
        
    //     for(int i=0;i<nums.size();i++)
    //     {
    //       nums[i] = res[i];
    //     }
    // }
    
// O(1) space;
   void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if(nums.size() <= 1) return ;
        int pivot = nums.size(); 
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                pivot = i;
                break;
            }
        }
        
        // Using the reverse() function;
        reverse(nums.begin(), nums.begin() + pivot); // 0 ~ (pivot-1);
        reverse(nums.begin() + pivot , nums.end());// pivot ~ (end-1);
        reverse(nums.begin(), nums.end());// 0 ~ (end-1);
       
    }
    
};
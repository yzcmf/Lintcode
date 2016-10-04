/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/3sum-closest
@Language: C++
@Datetime: 16-09-18 21:02
*/

class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        
        if(nums.size()<3) return INT_MAX;
        int min_res = INT_MAX;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++)
         {
            int left=i+1,right=nums.size()-1;
            while(left<right)
            {
              int diff = nums[i] + nums[left] + nums[right]-target;
              if(abs(diff)<abs(min_res)) min_res = diff;
              if(diff == 0) break;
              else if(diff<0)
              left++;
              else if(diff>0)
              right--;
            }
        } 
        
        return min_res + target;
    }
};

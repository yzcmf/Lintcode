/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/longest-consecutive-sequence
@Language: C++
@Datetime: 16-09-23 03:35
*/

//Time:O(n);
//Space:O(n);
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &nums) {
        // write you code here
        if(nums.size() == 0 ) return 0;
        map<int,int>ht;
        int cnt = 1;
        for(int i=0;i<nums.size();i++) ht[nums[i]] = 1;
        
        for(int i=0;i<nums.size();i++)
        {  
            if(ht[nums[i]])
            {
             int left = nums[i] - 1;
             int right = nums[i] + 1;
             while(ht[left])
             {
                 ht[left]=0;
                 left--;
             }
             while(ht[right])
             {
                 ht[right]=0;
                 right++;
             }
             cnt = max(cnt,right-left-1);
            }
        }
        return cnt;
    }
};
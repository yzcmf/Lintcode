/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/3sum
@Language: C++
@Datetime: 16-09-17 06:39
*/

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        
        vector<vector<int>> allSol;
        if(nums.size()<3) return allSol;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i] == nums[i-1] && i>0) continue;
            int l=i+1,r=nums.size()-1;
            
            while(l<r)
            {
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==0)
                {
                    vector<int>sol;
                    sol.push_back(nums[i]);
                    sol.push_back(nums[l]);
                    sol.push_back(nums[r]);
                    allSol.push_back(sol);
                    l++;
                    r--;
                    while(nums[l] == nums[l-1])l++;
                    while(nums[r] == nums[r+1])r--;
                }
                else if(sum<0) l++;
                else if(sum>0) r--;
            }
            
        }
        
        return allSol;
    }
};

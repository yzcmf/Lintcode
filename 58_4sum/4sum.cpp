/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/4sum
@Language: C++
@Datetime: 16-09-18 23:15
*/

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        vector<vector<int>>allSol;
        vector<int>sol;
        sort(nums.begin(),nums.end());
        Ksum(nums,0,nums.size()-1,target,4,sol,allSol);
        return allSol;
    }
    
    void Ksum(vector<int>&nums,int start,int end,int target,int k,vector<int>&sol,
              vector<vector<int>>&allSol)
    {
        if(k<=0) return;
        if(k==1)
        {
            for(int i=start;i<=end;i++)
            {
                if(target == nums[i])
                {
                    sol.push_back(target);
                    allSol.push_back(sol);
                    sol.pop_back();
                    return;
                }
            }
        }
        
        if(k==2)
        {
          Twosum(nums,start,end,target,sol,allSol);
          return;
        }
        
        for(int i=start;i<=end-k+1;i++)
        {
            //Note: it's really wrong that : nums[i] = nums[i-1] ;
            if(i>start && nums[i]==nums[i-1]) continue;
            sol.push_back(nums[i]);
            Ksum(nums,i+1,end,target-nums[i],k-1,sol,allSol);
            sol.pop_back();
        }
    }
    
    void Twosum(vector<int>&nums,int start,int end,int target,vector<int>&sol,
                vector<vector<int>>&allSol)
    {
        while(start<end)
        {
            int sum = nums[start] + nums[end];
            if(sum == target)
            {
                sol.push_back(nums[start]);
                sol.push_back(nums[end]);
                allSol.push_back(sol);
                sol.pop_back();
                sol.pop_back();
                start++;
                end--;
                while(nums[start] == nums[start-1]) start++; 
                while(nums[end] == nums[end+1]) end--; 
            }
            else if(sum < target) 
            start++;
            else 
            end--;
        }
    }
};

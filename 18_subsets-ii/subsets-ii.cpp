/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/subsets-ii
@Language: C++
@Datetime: 16-10-01 02:48
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // write your code here
        vector<vector<int>>allSol;
    	vector<int>Sol;
    	if(nums.empty())return allSol;
    	allSol.push_back(Sol);
    	sort(nums.begin(),nums.end());// -- very important !
    	findsubsetsII(nums,Sol,allSol,0);
    	return allSol;
    }
    void findsubsetsII(vector<int> &nums,vector<int>&Sol,vector<vector<int>>&allSol,int start)
    {
        for(int i= start;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1] && i>start) continue;
            Sol.push_back(nums[i]);
            allSol.push_back(Sol);
            findsubsetsII(nums,Sol,allSol,i+1);
            Sol.pop_back();
        }
    }
};

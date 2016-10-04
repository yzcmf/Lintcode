/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/subsets
@Language: C++
@Datetime: 16-10-01 02:44
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsets(vector<int> &nums) {
    	// write your code here
    	vector<vector<int>>allSol;
    	vector<int>Sol;
    	if(nums.empty())return allSol;
    	allSol.push_back(Sol);
    	findsubsets(nums,Sol,allSol,0);
    	return allSol;
    }
    void findsubsets(vector<int> &nums,vector<int>&Sol,vector<vector<int>>&allSol,int start)
    {
        for(int i= start;i<nums.size();i++)
        {
            Sol.push_back(nums[i]);
            allSol.push_back(Sol);
            findsubsets(nums,Sol,allSol,i+1);
            Sol.pop_back();
        }
    }
};
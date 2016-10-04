/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/combination-sum-ii
@Language: C++
@Datetime: 16-09-20 06:12
*/

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &candidates,int target) {
        // write your code here
        vector<vector<int>>allSol;
        vector<int>Sol;
        sort(candidates.begin(),candidates.end());
        DFS(candidates,target,Sol,allSol,0);
        return allSol;
    }
    
     
    void DFS(vector<int> &candidates, int target, vector<int>& Sol,vector<vector<int>>& allSol,int start)
    {
        if(candidates.empty()) return;
//Using : find(allSol.begin(),allSol.end(),Sol) == allSol.end() to get rid of the dupliacted
        if(target == 0 && find(allSol.begin(),allSol.end(),Sol) == allSol.end())
        {
         allSol.push_back(Sol);
         return;
        }
        
        for(int i=start;i<candidates.size();i++)
        {
            if(candidates[i]<=target)
            {
            Sol.push_back(candidates[i]);
            DFS(candidates,target-candidates[i],Sol,allSol,i+1);
            Sol.pop_back();
            }
        }
        
        return;
    }
};
/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/combinations
@Language: C++
@Datetime: 16-09-20 06:35
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        // write your code here;
        vector<vector<int>>allSol;
        vector<int>Sol;
        DFS(n,k,Sol,allSol,1);
        return allSol;
    }
    
    void DFS(int n, int k, vector<int>& Sol,vector<vector<int>>& allSol,int start)
    {
        if(Sol.size()==k)
        {
            allSol.push_back(Sol);
            return;
        }
        for(int i=start;i<=n;i++)
        {
          Sol.push_back(i);
          DFS(n,k,Sol,allSol,i+1);
          Sol.pop_back();    
        }
    }
    
    //  vector<vector<int>>res;
    
    // void helper(int n,int k,int cur,vector<int> tmp){
    //     if(tmp.size()==k){
    //         res.push_back(tmp);
    //         return;
    //     }

    //     //当前层有可选的数从cur到n都有可能
    //     for(int i=cur;i<=n;i++){
    //         tmp.push_back(i);
    //         helper(n,k,i+1,tmp);//i+1
    //         tmp.pop_back();
    //     }
    // }

    // vector<vector<int>> combine(int n, int k) {
    //     // write your code here
    //     vector<int>tmp;
    //     helper(n,k,1,tmp);
    //     return res;
    // }
};
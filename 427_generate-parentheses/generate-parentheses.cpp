/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/generate-parentheses
@Language: C++
@Datetime: 16-09-22 03:43
*/

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> allSol;
        string Sol;
        DFS(n,Sol,allSol,0,0);
        return allSol;
    }
    
    void DFS(int n,string& Sol,vector<string>& allSol,int left,int right)
    {
        if(left==n && right==n) 
        {
         allSol.push_back(Sol);
         return;   
        }
        if(left<n)
        {
            Sol.push_back('(');
            DFS(n,Sol,allSol,left+1,right);
            Sol.pop_back();
        }
        if(right<left)
        {
            Sol.push_back(')');
            DFS(n,Sol,allSol,left,right+1);
            Sol.pop_back();
        }
    }
};
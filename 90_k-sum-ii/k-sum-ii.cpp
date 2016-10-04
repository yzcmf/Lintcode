/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/k-sum-ii
@Language: C++
@Datetime: 16-10-01 08:43
*/

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int>>kSumII(vector<int> A, int k, int target) {
        // write your code here
        sort(A.begin(),A.end()); // -- very important !!
        vector<vector<int>>allSol;
        vector<int>Sol;
        calc(allSol,Sol,A,0,k,target);
        return allSol;
    }
    
    void calc(vector<vector<int>>&allSol,vector<int>&Sol,vector<int> &A,
                int s, int k, int target)
    {

        if(target == 0 && k == 0) 
        {
         allSol.push_back(Sol);
         return;
        }
        
        for(int i=s;i<A.size() && A[i]<=target;i++)
        {
            Sol.push_back(A[i]);
            calc(allSol,Sol,A,i+1,k-1,target-A[i]);
            Sol.pop_back();
        }
    }    
};

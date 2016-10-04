/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/k-sum
@Language: C++
@Datetime: 16-09-20 07:37
*/

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    //-- Time Limit Exceeded
    /*
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        vector<int>Sol;
        vector<vector<int>>allSol;
        sort(A.begin(),A.end());
        DFS(A,k,target,Sol,allSol,0);
        return allSol.size();
    }
    
    void DFS(vector<int>&A, int k, int target,vector<int>&Sol,vector<vector<int>>&allSol,int start)
    {
        if(target == 0 && k==0 && find(allSol.begin(),allSol.end(),Sol) == allSol.end()) 
        {
            allSol.push_back(Sol);
            return;
        }
        
        for(int i=start;i<A.size();i++)
        {
            if(A[i]<=target)
            {
                Sol.push_back(A[i]);
                DFS(A,k-1,target-A[i],Sol,allSol,i+1); 
                Sol.pop_back();
            }
        }
    }
    */
    
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        
    const int n = A.size();

        // table[i][j][t] denotes the number of ways to select,
        // from first i elements, j elements whose sum equals to t
    vector<vector<vector<int>>> table(2, vector<vector<int>>(n + 1, vector<int>(target + 1, 0)));

        for (int i=1; i<= n; i++) {
            if (A[i-1]<= target) {
                for (int j=i; j<=n; j++) {
                    table[1][j][A[i-1]] = 1;
                }
            }
        }

        for (int i = 2; i <= k; i++) {
            for (int j = i; j <= n; j++) {
                for (int p = 1; p <= target; p++) {
                    table[i%2][j][p] = 0;
                    if (i<j) {
                        table[i%2][j][p] = table[i%2][j-1][p];
                    }
                    if (p - A[j-1] >= 0) {
                        table[i%2][j][p] += table[(i-1)%2][j-1][p-A[j-1]];
                    }
                }
            }
        }
        return table[k%2][n][target];
    }
//Reference: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/k-sum.cpp    
};
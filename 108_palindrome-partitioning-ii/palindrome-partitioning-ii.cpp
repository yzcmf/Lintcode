/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/palindrome-partitioning-ii
@Language: C++
@Datetime: 16-09-25 20:47
*/

class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        int n=s.size();
        if(n == 0) return 0;
        vector<vector<bool>>isPal(n, vector<bool>(n, false));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                //i+1>j-1:Means 1~2 chars here -- we could optimize to 3;
                //i+1>=j-1:Means 1~3 chars here -- i~j : at most 3;ex:"aca";
                if((i+1>=j-1||isPal[i+1][j-1]) && s[i]==s[j]) 
                 isPal[i][j]=true;
            }
        }
        
        //DP[i]表示长度为i的prefix：s[0: i-1]的min cut数量。
        //对所有 0<=j<i，且s[j: i-1]为palindrome
        //DP[i] = min (DP[j] + 1,DP[i]) 
        vector<int>DP(n+1,INT_MAX);
        DP[0] = -1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=i-1;j++)
            {
              if(isPal[j][i-1])    
              DP[i] = min (DP[j] + 1,DP[i]); 
            }
        }
        return DP[n];
    }
};


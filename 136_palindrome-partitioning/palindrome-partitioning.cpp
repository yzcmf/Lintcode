/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/palindrome-partitioning
@Language: C++
@Datetime: 16-09-25 20:32
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        int n = s.size();
        vector<vector<string>>allSol;
        vector<string>Sol;
        vector<vector<bool>>isPal(n,vector<bool>(n,false));// -- DP to infer
        //Calculate:isPal[i][j] and based on the isPal[i+1][j-1];
        //Thus, i is going to decrease; j is going to increase;
        //Note: i<=j; Thus we can make sure the following forloop;
        for(int i=n-1;i>=0;i--)
        {
          for(int j=i;j<n;j++)
            {
             // i+1>=j-1 : Means 1~3 chars here,set to be true;  
             if((i+1>=j-1||isPal[i+1][j-1]) && s[i]==s[j])    
                isPal[i][j]=true;
            }
        }
        Comb(s,Sol,allSol,0,isPal);
        return allSol;
    }
    
    void Comb(string s, vector<string>& Sol, vector<vector<string>>& allSol,int start,
              vector<vector<bool>>& isPal)
    {
        if(start == s.size()) 
        {
        allSol.push_back(Sol);        
        return;
        }
        
        for(int i=start;i<s.size();i++)
        {
            if(isPal[start][i])
            {
                Sol.push_back(s.substr(start,i-start+1));
                Comb(s,Sol,allSol,i+1,isPal);
                Sol.pop_back();
            }
        }
    }
};
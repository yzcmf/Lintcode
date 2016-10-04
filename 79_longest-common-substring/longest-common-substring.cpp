/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/longest-common-substring
@Language: C++
@Datetime: 16-09-23 02:43
*/

//The characters in substring should occur continuously in original string. 
//This is different with subsequence. AC solution;
class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
           int res = 0;
           for(int i=0;i<A.size();i++)
           {
                for(int j=0;j<B.size();j++)
                {
                  int len=0;
                  while(i+len<A.size() && j+len<B.size() && A[i+len] == B[j+len])
                  {
                     len++;
                     res = max(res,len);
                  }
                }   
            }
        return res;
    }
};

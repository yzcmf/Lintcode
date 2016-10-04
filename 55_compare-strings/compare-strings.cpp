/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/compare-strings
@Language: C++
@Datetime: 16-09-13 07:41
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        
        if(A.size()<B.size()) return false;
        
        map<char,int>ht;//Initialized,all to the zeros;
        
        for(int i=0;i<A.size();i++)
        {
            ht[A[i]]++;
        }
        
        for(int i=0;i<B.size();i++)
        {
            ht[B[i]]--;
            if(ht[B[i]]<0) 
            return false;
        }
        
        return true;
    }
};

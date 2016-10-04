/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/delete-digits
@Language: C++
@Datetime: 16-09-21 03:32
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        string s;
        if(A.size()<k) return s;
        int cnt = 0;
        
        for(int i=0;i<A.size();i++)
        {
            //Decide whether to delete the s.back()
            while(!s.empty() && cnt<k && s.back()>A[i])
            {
                s.pop_back();
                cnt++;
            }
            if(A[i] != '0' || !s.empty())
            s.push_back(A[i]);
        }
        //If the number of deleted numbers are not enough 
        if(cnt < k) s.resize(s.size()-k+cnt);
        return s;
    }
};

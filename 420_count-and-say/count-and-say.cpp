/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/count-and-say
@Language: C++
@Datetime: 16-09-14 03:06
*/

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string helper (string s)
    {
         stringstream ss;
         char c = s[0];
         int count = 1;
         
         for(int i=1;i<s.size();i++)
         {
             if(s[i]!=c)
             {
                 ss<<count<<c;
                 c = s[i];
                 count=1;
             }
             else
             {
              count++;
             }
         }
         ss<<count<<c;
         return ss.str();
    }
     
    string countAndSay(int n) {
        // Write your code here
        string s = "1";
        
        for(int i=1;i<n;i++)
        {
            s = helper(s);
        }
        
        return s;
    }
};
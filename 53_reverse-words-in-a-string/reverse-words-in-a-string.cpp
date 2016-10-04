/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/reverse-words-in-a-string
@Language: C++
@Datetime: 16-09-14 17:45
*/

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        string ret;
        int j=s.size();
        
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==' ') j=i;
            else if((s[i-1]==' ')||(i==0))
            {
            //ret.append(s.substr(i,j-i));
            ret +=s.substr(i,j-i);
            if(!ret.empty()) ret +=" ";
            }
        }
        
        return ret;
    }
};
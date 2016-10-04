/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/length-of-last-word
@Language: C++
@Datetime: 16-09-13 07:54
*/

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        
        if(s.empty()) return 0;
        int ans=0;
        int i=s.size()-1;
        while(i>=0 && s[i] ==' ') i--;
        int len = i;
        
        for(int i=len;i>=0;i--)
        {
            if (s[i] == ' ') break;
            ans++;
        }
        return ans;
    }
};
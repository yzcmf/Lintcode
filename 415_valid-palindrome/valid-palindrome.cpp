/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/valid-palindrome
@Language: C++
@Datetime: 16-09-16 10:06
*/

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        
        if(s.empty()) return true;
        
        int l=0,r=s.size()-1;
        
        while(l<=r)
        {
            if(!isalnum(s[l])) 
            {
            l++;
            continue;
            }
            if(!isalnum(s[r])) 
            {
            r--;
            continue;
            }
            if(tolower(s[l]) == tolower(s[r]))
            {
                l++;
                r--;
            }
            else if(tolower(s[l]) != tolower(s[r]))
            {
             return false;
            }
        }
        
        return true;
    }
};
/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/longest-palindromic-substring
@Language: C++
@Datetime: 16-09-23 12:22
*/

class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        if(s.empty()) return "";
        string ret = s.substr(0,1);
        int max_len = 1;
        for(int i=1;i<s.size();i++)
        {
          int left = i-1;
          int right = i+1;
          while(left>=0 && right<=s.size()-1) 
          {
              if(s[left] != s[right]) break;
              left--;
              right++;
          }
          if(max_len < right-1-left)
          {
          ret = s.substr(left+1,right-1-left);    
          max_len = right-1-left;
          }
          
          left = i-1;
          right = i;
          while(left>=0 && right<=s.size()-1) 
          {
              if(s[left] != s[right]) break;
              left--;
              right++;
          }
          if(max_len < right-1-left)
          {
          ret = s.substr(left+1,right-1-left);    
          max_len = right-1-left;
          }
        }
        
        return ret;
    }
};
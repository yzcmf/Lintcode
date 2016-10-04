/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/two-strings-are-anagrams
@Language: C++
@Datetime: 16-09-14 05:32
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        
       map<char,int>ht;
        
       if(s.size() != t.size()) return false;
       
       for(int i=0;i<s.size();i++)
       {
           ht[s[i]]++;
       }
       
       for(int i=0;i<t.size();i++)
       {
           ht[t[i]]--;
           if(ht[t[i]]<0) return false;
       }
       
       return true;
    }
};
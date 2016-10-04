/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/unique-characters
@Language: C++
@Datetime: 16-09-16 09:09
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        map<char,int>ht;
        
        // for(int i=0;i<str.size();i++)
        // {
        //     ht[str[i]]++;//Unique will appear only once;
            
        //     if(ht[str[i]]>1)
        //     return false;
        // }
        
        for(int i=0;i<str.size();i++)
        {
            if(ht.find(str[i])!=ht.end() && i>0)
            return false;
            ht[str[i]]=i;//Unique will be found in the ht;
        }
        
        return true;
    }
};
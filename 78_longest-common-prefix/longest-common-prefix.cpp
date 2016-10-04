/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/longest-common-prefix
@Language: C++
@Datetime: 16-09-23 02:09
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if(strs.empty())   return "";
        if(strs.size()<2)  return strs[0];
        string ret= strs[0];
        
        for(int i=1;i<strs.size();i++)
        {
            for(int j=0;j<ret.size();j++)
            {    
                if(ret[j] != strs[i][j])
                {
                ret = strs[i].substr(0,j);
                }
            }
        }
        
        return ret;
    }
};
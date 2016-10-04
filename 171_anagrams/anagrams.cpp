/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/anagrams
@Language: C++
@Datetime: 16-09-19 03:18
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        vector<string>ret;
        map<string,vector<int>>ht;
        
        for(int i=0;i<strs.size();i++)
        {
            string key = strs[i];
            sort(key.begin(),key.end());
            ht[key].push_back(i);
        }
        
        for(map<string,vector<int>>::iterator it=ht.begin();it!=ht.end();it++)
        {
            if(it->second.size()>1)
            {
                for(int i=0;i<it->second.size();i++)
                {
                 ret.push_back(strs[it->second[i]]);
                }
            }
        }
        
        return ret;
    }
};

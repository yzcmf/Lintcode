/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/longest-words
@Language: C++
@Datetime: 16-09-15 01:15
*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> res;
        if(dictionary.size()<=1) return dictionary;
        int max_len = 0;
        
        for(int i=0;i<dictionary.size();i++)
        {
            if(dictionary[i].size() < max_len) continue;
            if(dictionary[i].size() > max_len)
            {
                res.clear();
                max_len = dictionary[i].size();
            }
            res.push_back(dictionary[i]);
        }
        
        return res;
    }
};
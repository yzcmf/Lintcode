/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/simplify-path
@Language: C++
@Datetime: 16-10-01 06:30
*/

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        string cur;
        vector<string>ret;
        path.push_back('/');
        
        for(int i=0;i<path.size();i++)
        {
            if(path[i] == '/')
            {
                if(cur.empty()) continue;
                else if(cur == ".") cur.clear();
                else if(cur == "..")
                {
                    if(!ret.empty())
                    ret.pop_back();
                    cur.clear();
                }
                else
                {
                 ret.push_back(cur);
                 cur.clear();
                }
            }
            else
            {
             cur.push_back(path[i]);   
            }
        }
        
        string res;
        for(int i=0;i<ret.size();i++)
        res.append('/' + ret[i]);
        
        if(res.empty()) res ="/";
        return res;
    }
};
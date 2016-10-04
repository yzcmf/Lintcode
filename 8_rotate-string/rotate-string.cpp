/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/rotate-string
@Language: C++
@Datetime: 16-09-15 23:46
*/

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        if(str.empty()) return;
        
        offset %= str.size();
        
        reverse(str.begin(),str.end()-offset);
        reverse(str.end()-offset,str.end());
        reverse(str.begin(),str.end());
    }
};

/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/gray-code
@Language: C++
@Datetime: 16-09-22 03:52
*/

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int>res;
        
        for(int i=0;i<pow(2,n);i++)
        {
            res.push_back((i>>1)^i);
        }
    
        return res;
    }
};
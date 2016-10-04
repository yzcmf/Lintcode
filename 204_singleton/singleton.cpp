/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/singleton
@Language: C++
@Datetime: 16-09-16 00:09
*/

class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        
        static Solution* instance;  
        
        return instance;  
    }
};
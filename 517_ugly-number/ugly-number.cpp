/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/ugly-number
@Language: C++
@Datetime: 16-09-16 09:03
*/

class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // Write your code here
        
        if(num<=0) return false;
        
        while(num %2 ==0) num /=2;
        while(num %3 ==0) num /=3;
        while(num %5 ==0) num /=5;
        
        return num == 1;
    }
};
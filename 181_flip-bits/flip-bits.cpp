/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/flip-bits
@Language: C++
@Datetime: 16-09-13 07:48
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        
        int num = a^b;
        int count=0;
        while(num)
        {
            num &= (num-1);
            count++;
        }
        
        return count;
    }
};
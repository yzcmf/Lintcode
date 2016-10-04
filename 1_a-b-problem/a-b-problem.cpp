/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/a-b-problem
@Language: C++
@Datetime: 16-09-13 05:15
*/

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        
        while(b!=0) // If b == 0; then there are no carry, a is the correct answer;
        {
            int _a = a^b; // No carry addition
            int _b = (a&b)<< 1;// Estmate the carry
            
            a = _a;
            b = _b;
        }
        
        return a;
    }
};
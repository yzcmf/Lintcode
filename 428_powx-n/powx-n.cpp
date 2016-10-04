/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/powx-n
@Language: C++
@Datetime: 16-09-24 06:45
*/

class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if (n < 0 ) {
            return 1.0 / myPow(x, -n);
        }
        if (n == 0) {
            return 1;
        }
        double v = myPow(x, n / 2);
        if (n % 2 == 0) {
            return v * v;
        } else {
         return v * v * x;
        }
    }
};
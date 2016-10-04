/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/print-numbers-by-recursion
@Language: C++
@Datetime: 16-09-24 07:02
*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
vector<int> numbersByRecursion(int n) {
        vector<int>result;
        numbersByRecursionHelper(0, n, result);
        return result;
}
// Construct the numbers by the current digit count.
void numbersByRecursionHelper(int depth, int n, vector<int>& result) {
        if (depth == n) {
            return;
        }
        if (depth == 0) {  // Initiate the result.
            for (int d = 1; d <= 9; d++) {
                result.push_back(d);
            }
        } 
        else {  // Construct the numbers by the previous result.
            int count=result.size();
            for (int d=1;d<=9;d++){
                result.push_back(d*pow(10,depth));
                for (int i=0;i<count;i++) {
                    result.push_back(result[i] + d*pow(10, depth));
                }
            }
        }
        // Construct the numbers in the next depth.
        numbersByRecursionHelper(depth + 1, n, result);
}

};
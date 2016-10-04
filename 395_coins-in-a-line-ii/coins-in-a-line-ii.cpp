/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/coins-in-a-line-ii
@Language: C++
@Datetime: 16-09-17 03:58
*/

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int sum1=0;
        int sum2=0;
        int i=0;
       
        while(i<values.size())
        {
            sum1 +=values[i++];
            sum1 +=values[i++];
            sum2 +=values[i++];
        }
        
        return sum1>sum2;
    }
};
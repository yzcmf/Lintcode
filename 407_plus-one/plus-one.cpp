/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/plus-one
@Language: C++
@Datetime: 16-09-15 21:28
*/

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        int carry = 1;
        vector<int> res;
        
        for(int i=digits.size()-1;i>=0;i--)
        {
            int t = (digits[i]+carry);
            digits[i]= t%10;
            carry = t/10;
        }
        
        
        if(carry) res.push_back(carry);
        for(int i=0;i<digits.size();i++)
        res.push_back(digits[i]);
        
        return res;
    }
};
/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/add-binary
@Language: C++
@Datetime: 16-09-14 17:53
*/

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        
        int carry=0;
        int sum;
        int ai,bj;
        char val;
        string res;
        
        for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0;i--,j--)
        {
            //Filled out the overlength of a or b to the zeros;
            ai = i>=0? a[i]-'0':0;
            bj = j>=0? b[j]-'0':0;
            
            sum = ai + bj +carry;
            val = sum%2+'0';
            carry = sum/2;
            
            //Note: the val should be inserted in the front;
            res.insert(res.begin(),val); 
        }
        
        if(carry == 1) res.insert(res.begin(),'1'); 
        
        return res;
    }
};
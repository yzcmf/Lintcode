/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/ugly-number-ii
@Language: C++
@Datetime: 16-10-01 07:07
*/

class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        vector<int>res(1,1);
        int i2=0,i3=0,i5=0;
        for(int i=1;i<=n-1;i++)
        {
            int m2 = res[i2]*2;
            int m3 = res[i3]*3;
            int m5 = res[i5]*5;
            
            int mn = min(min(m2,m3),m5);
            res.push_back(mn);
            
            if(mn == m2) i2++;
            if(mn == m3) i3++;
            if(mn == m5) i5++;
        }
        
        return res.back();
    }
};
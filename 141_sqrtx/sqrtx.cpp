/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/sqrtx
@Language: C++
@Datetime: 16-09-16 08:24
*/

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        
        if(x<0) return -1;
        long l=0,r=(x/2)+1,mid;//r>=(l+1);
        
        while(l<=r)
        {
            mid = (r+l)/2;
            long t = mid*mid - x;
            if(t == 0) return mid;
            else if(t>0)
            {
              r = mid-1;    
            }
            else if(t<0)
            {
              l = mid+1;    
            }
        }
        
        return r;
    }
};
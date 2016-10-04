/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/digit-counts
@Language: C++
@Datetime: 16-09-21 03:47
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int cnt=0;
        if(k==0) return n/10 + 1;  

        for(int i=0;i<=n;i++)
        {
          int num = i;
            while(num)
            {
              int res = num%10;
              if(res == k) 
              {
               cnt++;
               //break; -- no need to be here; count for the digits not the numbers;
              }
              num /= 10; 
            }
        }
        return cnt;
    }
};
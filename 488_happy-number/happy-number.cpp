/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/happy-number
@Language: C++
@Datetime: 16-09-14 03:25
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        
        if(n<=0) return false;
        
        //Add the set to avoid the time problem;
        set<int> s;
        
        while(n>1)
        {
          int res=0;
          while(n)
          {
              res += (n%10)*(n%10);
              n /= 10;
          }
          n = res;
          
          if(s.count(n)) break;
          else
          {
              s.insert(n);
          }
        }
        
        return n==1;
    }
};
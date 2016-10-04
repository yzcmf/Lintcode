/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/fizz-buzz
@Language: C++
@Datetime: 16-09-13 07:59
*/

class Solution {
public:
    /**
     * param n: As description.
     * return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
      
      vector<string> res; 
      
      for(int i=1;i<=n;i++)
      {
      if(i%3==0 && i%5==0)
          res.push_back("fizz buzz");
      else if(i%3==0)      
          res.push_back("fizz");
      else if(i%5==0)
          res.push_back("buzz");
      else
          res.push_back(to_string(i));
      }
          
      return res;      
    }
};
/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/strstr
@Language: C++
@Datetime: 16-09-16 07:59
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        
        if(source != NULL && target != NULL) 
        {
        string s(source);
        string t(target);
        
        int s_len = s.size();
        int t_len = t.size();
        
        for(int i=0;i<s_len-t_len+1;i++)
        {
        if(s.substr(i,t_len) == t) 
        return i;
        }
        
        }
        
        return -1;
        
//         if(source!=nullptr && target!=nullptr) 
//         {
//          string s(source);
//          string t(target);
  
//   int S_len=s.length();
//   int T_len=t.length();
  
//   for(int i=0;i<S_len-T_len+1;i++)
//   {
//       if(s.substr(i,T_len)==t)
//       return i;
//   }
//   }
  
//   return -1;
    }
};

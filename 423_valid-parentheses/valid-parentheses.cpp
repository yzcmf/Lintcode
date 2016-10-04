/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/valid-parentheses
@Language: C++
@Datetime: 16-09-16 09:53
*/

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        
        stack<char>stack;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]== '('|| s[i]== '[' || s[i]== '{') 
            {
            stack.push(s[i]);
            continue;
            }
            
            if(s[i]== ')' && stack.top()!='(') return false;
            if(s[i]== ']' && stack.top()!='[') return false;
            if(s[i]== '}' && stack.top()!='{') return false;
            
            stack.pop();
        }
        
        return stack.empty();
        
        //  stack<char> stack;
        
        // for(int i=0;i<s.size();i++)
        // {
        //   if(s[i]=='('||s[i]=='{'||s[i]=='[')
        //   {
        //       stack.push(s[i]);
        //       continue;
        //   }
        //   char top = stack.top();
        //   stack.pop();    
        //   if(s[i]==')' && top!='(') return false;
        //   if(s[i]==']' && top!='[') return false;
        //   if(s[i]=='}' && top!='{') return false;
        // }
        // return stack.empty();
    }
};
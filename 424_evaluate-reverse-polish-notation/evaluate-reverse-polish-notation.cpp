/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/evaluate-reverse-polish-notation
@Language: C++
@Datetime: 16-09-21 07:02
*/

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        if(tokens.size()==1) return atoi(tokens[0].c_str());
        stack<int>s;
        int res;
        
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="+" && tokens[i]!="-"&& tokens[i]!="*" && tokens[i]!="/")
            s.push(atoi(tokens[i].c_str()));//c_str:make it compatible in c;
            else
            {
                int n = s.top();
                s.pop();
                int m = s.top(); 
                s.pop();
                if(tokens[i] == "+")  res = m+n;
                if(tokens[i] == "-")  res = m-n;
                if(tokens[i] == "*")  res = m*n;
                if(tokens[i] == "/")  res = m/n;
                s.push(res);
            }
        }
        return s.top();
    }
};
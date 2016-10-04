/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/min-stack
@Language: C++
@Datetime: 16-09-23 01:54
*/

class MinStack {
private:
stack<int>s;
stack<int>m;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        s.push(number);
        if(m.empty()||number<=m.top())
        //if(m.empty()||number<=m.top())
        m.push(number);
    }
   
          
// void push(int number) {
//     s.push(number);
//     if(m.empty()||number<=m.top())
//     m.push(number);
// }

    int pop() {
        // write your code here
        int temp = s.top();
        s.pop();
        if(temp == m.top())
        m.pop();
        return temp;
    }

    int min() {
        // write your code here
        return m.top();
    }

};

/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/implement-queue-by-two-stacks
@Language: C++
@Datetime: 16-09-22 22:40
*/

class Queue {
public:
    stack<int> stack1;//For holding the push
    stack<int> stack2;//For holding the pop

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        
        if (!stack2.empty())  
        {  
            int tmp = stack2.top();  
            stack2.pop();  
            return tmp;  
        }  
       
        return -1;  
    }

    int top() {
        // write your code here
        while (!stack1.empty())  
        {  
            stack2.push(stack1.top());  
            stack1.pop();  
        }  
        
        if (!stack2.empty())  
        {  
           return stack2.top();  
        }  
       
        return -1;  
    }
};

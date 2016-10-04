/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/assignment-operator-overloading-c-only
@Language: C++
@Datetime: 16-09-19 02:46
*/

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }
    
    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if(this != &object)
        {
        //1:Allocate new memory and copy the elements;
            char *new_pData = NULL;
            if(object.m_pData != NULL)
            {
                size_t count = strlen(object.m_pData);
                new_pData = new char[count];
                copy(object.m_pData,object.m_pData+count,new_pData);
            }
        
        //2:Deallocate old memory;
        if(m_pData != NULL)
        {
            delete[] m_pData;
        }
        
        //3:Assign the new memory to the object;
        m_pData = new_pData;
        }
    return *this;
   }
};

//https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/assignment-operator-overloading-c-only.cpp
//http://techinpad.blogspot.com/2015/05/lintcode-assignment-operator.html
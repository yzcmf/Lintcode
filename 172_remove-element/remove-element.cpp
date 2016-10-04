/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/remove-element
@Language: C++
@Datetime: 16-09-15 22:59
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        
        int k=0;
        
        for(int i=0;i<A.size();i++)
        {
            if(A[i] == elem)
            continue;
            else
            {
            A[k++] = A[i];
            }
        }
        return k;
    }
};
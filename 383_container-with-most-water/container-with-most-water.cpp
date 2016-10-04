/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/container-with-most-water
@Language: C++
@Datetime: 16-09-19 21:17
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &A) {
        // write your code here
        
       int left = 0, right = A.size()-1, max_res = 0;
       
       while(left<right)
       {
           max_res = max(max_res,(right-left)*min(A[left],A[right]));
           if(A[left]<A[right]) left++;
           else if(A[left]>=A[right])
           right--;
       }
       return max_res;
    }
};
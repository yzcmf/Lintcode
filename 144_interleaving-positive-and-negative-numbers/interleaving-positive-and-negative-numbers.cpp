/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/interleaving-positive-and-negative-numbers
@Language: C++
@Datetime: 16-09-22 04:24
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        
        int positive_idx = 1;
        int negative_idx = 0;
        int positive_nums= 0;
        
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>0) positive_nums++;
            if(positive_nums>A.size()/2)
            {
            positive_idx = 0;
            negative_idx = 1;
            }
        }
        
        while(positive_idx < A.size() && negative_idx < A.size())
        {
            while(negative_idx < A.size() && A[negative_idx]< 0)
            negative_idx += 2;
            while(positive_idx < A.size() && A[positive_idx]> 0)
            positive_idx += 2;
            
            //if(positive_idx < A.size() && negative_idx < A.size())
            swap(A[negative_idx],A[positive_idx]);
        }
    }
};
/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/merge-sorted-array
@Language: C++
@Datetime: 16-09-15 03:06
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int i=m-1,j=n-1;
        int k=m+n-1;//Assume the enough length for the A;
        
        while(i>=0 && j>=0) A[k--] = (A[i]>B[j]) ? A[i--] : B[j--];
        while(j>=0) A[k--] = B[j--];

    }
};
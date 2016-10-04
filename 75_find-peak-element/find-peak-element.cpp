/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/find-peak-element
@Language: C++
@Datetime: 16-09-21 23:51
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    //There must be one peak element at least;
    int findPeak(vector<int>A) {
        // write your code here
        int start = 0, end = A.size()-1;
        while(start+1<end)
        {
            int mid = (start+end)/2;
            if(A[mid]<A[mid-1]) end = mid-1;
            else if(A[mid]<A[mid+1]) start = mid+1;
            else 
            return mid;
        }
        
        int mid = A[start]>A[end] ? start : end;
        
        return mid;
    }
};

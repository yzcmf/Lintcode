/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/search-insert-position
@Language: C++
@Datetime: 16-09-15 23:51
*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        
        int bgn = 0,end = A.size()-1,mid;
        
        while(bgn<=end)
        {
            mid = (bgn + end)/2;
            if(target<A[mid]) end = mid-1;
            else if(target>A[mid]) bgn = mid+1;
            else
            return mid;
        }
        return bgn;
    }
};
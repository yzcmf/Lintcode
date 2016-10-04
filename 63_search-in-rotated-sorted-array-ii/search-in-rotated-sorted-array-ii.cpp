/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/search-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 16-09-26 04:25
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        if(A.empty()) return false;
        int start=0,end=A.size()-1;

        while(start+1<end)
        {
            int mid = (start + end)/2;
            if(A[mid] == target) return true;
            if(A[start]<A[mid])
            {
                if(A[start]<=target && target<A[mid])
                end = mid;
                else
                start = mid;
            }
            else if(A[start]>A[mid])
            {
                if(A[mid]<target && target<=A[end])
                start = mid;
                else
                end = mid;
            }
            else
            start++;
        }
        
        if (A[start] == target) {
            return true;
        }
        if (A[end] == target) {
            return true;
        }
        return false;
    }
};
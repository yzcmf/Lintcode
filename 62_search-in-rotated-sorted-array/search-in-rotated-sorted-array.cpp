/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/search-in-rotated-sorted-array
@Language: C++
@Datetime: 16-09-26 04:20
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        if(A.empty()) return -1;
        int start=0,end=A.size()-1;
        
        //Inside the while loop we ask for the result
        //Thus:left=0,right=A.size()-1;left<=right
        //Outside the while loop we ask for the result;
        //There will be two numbers left;
        //Compare the A[mid] with the target and A[start],A[end];
        while(start+1<end)
        {
            int mid = (start + end)/2;
            if(A[mid] == target) return mid;
            if(A[start]<A[mid])
            {
                if(A[start]<=target && target<A[mid])
                end = mid;
                else
                start = mid;
            }
            else
            {
                if(A[mid]<target && target<=A[end])
                start = mid;
                else
                end = mid;
            }
        }
        
        if (A[start] == target) {
            return start;
        }
        if (A[end] == target) {
            return end;
        }
        return -1;
    }
};
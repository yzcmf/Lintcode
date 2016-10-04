/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix
@Language: C++
@Datetime: 16-09-16 00:04
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        
        if(matrix.empty()||matrix[0].empty()) return false;
        
        int start = 0,end = matrix.size()-1,mid;
        
        while(start<=end)
        {
            mid = (start+end)/2;
            if(matrix[mid][0]<target) start = mid+1;
            else if(matrix[mid][0]>target) end = mid-1;
            else
            {
             return true;
            }
        }
        
        if(start == 0) return false;
        
        int row = start-1;
        start = 0,end = matrix[0].size()-1;
        
        while(start<=end)
        {
            mid = (start+end)/2;
            if(matrix[row][mid]<target) start = mid+1;
            else if(matrix[row][mid]>target) end = mid-1;
            else
            {
             return true;
            }
        }
        
        return false;
    }
};

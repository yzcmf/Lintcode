/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix-ii
@Language: C++
@Datetime: 16-09-27 06:01
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0 || n == 0) return 0;
        
        int row,col = n-1;
        int ans;
        
        while(row<=m-1 && col>=0)
        {
            if(target == matrix[row][col])
            {
                ans++;
                col--;
            }
            else if(target < matrix[row][col])
            {
                col--;
            }
            else
            {
                row++;
            }
        }
        return ans;
    }
};

/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/set-matrix-zeroes
@Language: C++
@Datetime: 16-09-30 06:15
*/

//O(1) space;
class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int>> &matrix) {
        // write your code here
        if(matrix.empty()||matrix[0].empty()) return;
        int row = matrix.size();
        int col = matrix[0].size();
        int cflag = 0;
        int rflag = 0;
        
        // Mark the original for the first row and col;
        for(int i=0;i<row;i++){if(matrix[i][0] == 0) cflag = 1;}
        for(int j=0;j<col;j++){if(matrix[0][j] == 0) rflag = 1;}
        
        //Set the first row and col, have changed the original outlook;
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //Set the rest according to the first row and col;
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        //Set first row and col according to the original flag;
        if(cflag){for(int i=0;i<row;i++) matrix[i][0] = 0;}
        if(rflag){for(int j=0;j<col;j++) matrix[0][j] = 0;}
        
    }
};
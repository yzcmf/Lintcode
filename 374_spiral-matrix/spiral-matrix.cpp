/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/spiral-matrix
@Language: C++
@Datetime: 16-10-01 01:20
*/

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int>res;
        if(matrix.size() == 0 || matrix[0].size() == 0) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int lvl = (min(m,n)+1)/2;
        
        for(int i=0;i<lvl;i++)
        {
            //From col i to lastCol;
            //From row i to lastRow;
            int lastRow = m-1-i;
            int lastCol = n-1-i;
            // Odd circle; -- Do not forget to add the last number;
            if(lastRow == i)
            {
               for(int j=i;j<=lastCol;j++)
               res.push_back(matrix[lastRow][j]); 
            }
            // Odd circle; -- Do not forget to add the last number;
            else if (lastCol == i)
            {
               for(int j=i;j<=lastRow;j++)
               res.push_back(matrix[j][lastCol]);  
            }
            // Even circle;
            else 
            {
              for(int j=i;j<lastCol;j++)
              res.push_back(matrix[i][j]);
              for(int j=i;j<lastRow;j++)
              res.push_back(matrix[j][lastCol]);
              for(int j=lastCol;j>i;j--)
              res.push_back(matrix[lastRow][j]);
              for(int j=lastRow;j>i;j--)
              res.push_back(matrix[j][i]);
            }
        }
        return res;
    }
};
//Good reference: http://www.cnblogs.com/grandyang/p/4362675.html
//http://bangbingsyb.blogspot.com/2014/11/leetcode-spiral-matrix-i-ii.html
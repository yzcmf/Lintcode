/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/matrix-zigzag-traversal
@Language: C++
@Datetime: 16-10-02 02:48
*/

// Time:  O(m * n)
// Space: O(1)
class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int>> &matrix) {
        vector<int> zigzag;
        int m = matrix.size(), n = matrix[0].size();
        //x+y == i; i is from 0 to m-1 + n-1 == m+n-2;
        //when i is the odd : row((i-y)++),col(y--);
        //when i is the even : row(x--),col((i-x)++);
        for (int i = 0; i < m + n - 1; i++) {
            //For the i=1,3,5..;
            if (i % 2) {
                //  0<= x<=m-1; 0<=i-x<=n-1 => max(i-n+1,0) <= x <= min(i,m-1)
                for (int y = min(i, n - 1);  y >= max(0, i - m + 1); y--) {
                    zigzag.push_back(matrix[i - y][y]);
                }
            } 
            //For the i=0,2,4..;
            else {
                //  0<= x<=m-1; 0<=i-x<=n-1 => max(i-n+1,0) <= x <= min(i,m-1)
                for (int x = min(i, m - 1);  x >= max(0, i - n + 1); x--) {
                    zigzag.push_back(matrix[x][i - x]);
                }
            }
        }

        return zigzag;
    }
};

//https://algorithm.yuanbin.me/zh-hans/problem_misc/matrix_zigzag_traversal.html
//https://github.com/legendtkl/LintCode-1/blob/master/C%2B%2B/matrix-zigzag-traversal.cpp
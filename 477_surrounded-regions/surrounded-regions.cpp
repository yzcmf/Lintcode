/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/surrounded-regions
@Language: C++
@Datetime: 16-10-01 04:54
*/

/*
只有在边界由‘O’连成的片区不会被改变为‘X’，
其余位置的‘O’均会被改为‘X’；
所以依次从每行的左右边界，每列的上下边界出发，
检查元素,对于不能由‘O’改为‘X’的位置标记为'1'
*/
class Solution {  
public:  
    void surroundedRegions(vector<vector<char>>& board) {  
        if (board.empty()||board[0].empty())  return;  
        int m = board.size(), n = board[0].size();  
        /*核心思想，只有在边界由‘O’连成的片区不会被改变为‘X’*/  
        for (int i = 0; i < m; i++)  
        {  
            //检查每行第一个元素  
            check(board, i, 0, m, n);  
            //若矩阵多列，则继续检查每行最后一个元素  
            if (n > 1)  check(board, i, n - 1, m, n);  
        }  
  
        for (int j = 1; j < n-1; j++)  
        {  
            //检查每列第一个元素  
            check(board, 0, j, m, n);  
            //若矩阵多行，继续检查每列最底元素  
            if (m > 1)  check(board, m - 1, j, m, n);  
        }  
  
        for (int i = 0; i < m; ++i)  
        {  
            for (int j = 0; j < n; ++j)  
            {  
                if (board[i][j] == 'O') board[i][j] = 'X';  
            }
        }
  
        for (int i = 0; i < m; ++i)  
        {  
            for (int j = 0; j < n; ++j)  
            {  
                if (board[i][j] == '1') board[i][j] = 'O';  
            } 
        } 
          
    }  
  
    /*检查（i,j）位置是否为'o',若为'o'，标记为'1' */  
    void check(vector<vector<char>>& board,int i, int j, int row, int col)  
    {  
        if (i < 0 || i >= row || j < 0 || j >= col)  return;  
        if (board[i][j] == 'O')  
        {  
            board[i][j] = '1';  
            if (i > 1)        check(board, i - 1, j, row, col);  
            if (i < row - 1)  check(board, i + 1, j, row, col);  
            if (j > 1)        check(board, i, j - 1, row, col);  
            if (j < col - 1)  check(board, i, j + 1, row, col);  
        }  
    }  
};  

//Good reference: http://blog.csdn.net/fly_yr/article/details/52215233?hmsr=toutiao.io&utm_medium=toutiao.io&utm_source=toutiao.io
//Good reference: http://blog.csdn.net/ithomer/article/details/8799323
/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/minimum-path-sum
@Language: C++
@Datetime: 16-09-15 03:27
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        
        if(grid.empty()||grid[0].empty()) return 0;
        
        for(int i=1;i<grid.size();i++)
        {
            grid[i][0] += grid[i-1][0];
        }
        
        for(int j=1;j<grid[0].size();j++)
        {
            grid[0][j] += grid[0][j-1];
        }
        
        for(int i=1;i<grid.size();i++)
        {
         for(int j=1;j<grid[0].size();j++)
         {
            grid[i][j] += min(grid[i][j-1],grid[i-1][j]);
         }
        }
        
        return grid[grid.size()-1][grid[0].size()-1];
    }
};

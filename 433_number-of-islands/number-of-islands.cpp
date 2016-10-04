/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/number-of-islands
@Language: C++
@Datetime: 16-09-15 04:20
*/


int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if(grid.empty() ||grid[0].empty()) return false;
        int cnt=0;
        
        for(int i=0;i<grid.size();i++)
        {
         for(int j=0;j<grid[0].size();j++)
         {
             if(grid[i][j] == 1)
             {
                 grid[i][j] = 0;
                 cnt++;
                 //Get rid of all 1 connect to this 1 using dfs;
                 dfs(grid,i,j);
             }
          } 
        }
        return cnt;
    }
private:    
    void dfs(vector<vector<bool>>&grid,int x,int y)
    {
        for(int k=0;k<4;k++)
        {
            int i = x + dir[k][0];
            int j = y + dir[k][1];
            
            if( i<grid.size() && i>=0 && j<grid[0].size() && j>=0 && grid[i][j])
            {
              grid[i][j] = 0;//Get rid of all the 1;
              dfs(grid,i,j);   
            }
        }
    }
};



//https://leetcode.com/problems/number-of-islands/

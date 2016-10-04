/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/n-queens-ii
@Language: C++
@Datetime: 16-09-27 00:10
*/

//http://bangbingsyb.blogspot.com/2014/11/leetcode-n-queens-i-ii.html
/*
1. 逐行放置皇后：排除在同一行的可能。
2. 记录之前所放皇后的列坐标：col[i]=j表示第i行的皇后在第j列。
   这样在放置第i+1行时，只要保证col[i+1] != col[k], k=0...i 即可。
3. 对角线判断：对于任意(i1, col[i1])和(i2, col[i2])，
   只有当abs(i1-i2) = abs (col[i1]-col[i2])时，两皇后才在同一对角线。
*/
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> col;
        int totSol = 0;
        solveNQ(n, 0, col, totSol);
        return totSol;
    }
    
    void solveNQ(int n, int irow, vector<int> &col, int &totSol) {
        if(irow==n) {
            totSol++;
            return;
        }
        
        for(int icol=0; icol<n; icol++) {
            if(validPos(col, irow, icol)) {
                col.push_back(icol);
                solveNQ(n, irow+1, col, totSol);
                col.pop_back();
            }
        }
    }
    
    bool validPos(vector<int> &col, int irow, int icol) {
        for(int i=0; i<col.size(); i++) {
            if(icol==col[i] || abs(irow-i)==abs(icol-col[i]))
                return false;
        }
        return true;
    }    
};

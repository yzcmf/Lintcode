/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/spiral-matrix-ii
@Language: C++
@Datetime: 16-10-01 01:13
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        // This problem is a square;
        vector<vector<int>>res(n,vector<int>(n,0));
        int lvl = n/2;
        int val = 1;
        
        for(int i=0;i<lvl;i++)
        {
            int last = n-1-i;
            for(int j=i;j<last;j++)
            res[i][j] = val++;
            for(int j=i;j<last;j++)
            res[j][last] = val++;
            for(int j=last;j>i;j--)
            res[last][j] = val++;
            for(int j=last;j>i;j--)
            res[j][i] = val++;
        }
        
        if( n % 2 == 1) res[n/2][n/2] = val;
        return res;
    }
};
//http://bangbingsyb.blogspot.com/2014/11/leetcode-spiral-matrix-i-ii.html

// class Solution {
// public:
//     /**
//      * @param n an integer
//      * @return a square matrix
//      */
//     vector<vector<int>> generateMatrix(int n) {
//         // Write your code here
//         vector<vector<int>>ret(n,vector<int>(n,0));
//         int nlvl = n/2; //The number of the circle:[min(n,n)+1]/2;
//         int val =1;
//         for(int i=0;i<nlvl;i++)
//         {
//             int last = n-1-i;
//             for(int j=i;j<last;j++)
//               ret[i][j] = val++;
//             for(int j=i;j<last;j++)
//               ret[j][last]=val++;
//             for(int j=last;j>i;j--)
//               ret[last][j] = val++;
//             for(int j=last;j>i;j--)
//               ret[j][i] = val++;
//         }
        
//         if( n%2 == 1) ret[n/2][n/2] = val;
//         return ret;
//     }
// };

